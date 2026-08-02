# Image Processing in C

## 1. Compilation Instructions

To compile the program, simply run `make` in the project directory:

```bash
make
```

This will produce the executable `imgproc`.

To clean the object files and executable:

```bash
make clean
```

**Requirements**:  
- GCC compiler (supports C99)  
- `stb_image.h` and `stb_image_write.h` must be placed in the same directory as the source files. They are available at:  
  - https://github.com/nothings/stb/blob/master/stb_image.h  
  - https://github.com/nothings/stb/blob/master/stb_image_write.h  

---

## 2. Program Usage

The program is invoked with the following command line format:

```bash
./imgproc input.bmp output.bmp operation [parameters]
```

### Supported operations and examples:

| Operation        | Example command |
|------------------|-----------------|
| Grayscale        | `./imgproc in.bmp out.bmp grayscale` |
| Horizontal flip  | `./imgproc in.bmp out.bmp flip horizontal` |
| Vertical flip    | `./imgproc in.bmp out.bmp flip vertical` |
| Rotate           | `./imgproc in.bmp out.bmp rotate 90` (supports 0, 90, 180, 270, -90, -180, -270) |
| Blur             | `./imgproc in.bmp out.bmp blur` |
| Crop             | `./imgproc in.bmp out.bmp crop x y width height` (e.g., `crop 100 50 200 300`) |
| **Additional features** | |
| Threshold        | `./imgproc in.bmp out.bmp threshold [value]` (optional value, default 128) |
| Brightness       | `./imgproc in.bmp out.bmp bright delta` (delta is an integer, positive for brighter, negative for darker) |
| Color inversion  | `./imgproc in.bmp out.bmp invert` |
| Resize (bilinear)| `./imgproc in.bmp out.bmp resize scale` (scale is a positive floating‑point number, e.g., 0.5 to shrink, 2.0 to enlarge) |

All output images are saved as BMP format.

---

## 3. Design Description

### Image Representation
The image is stored as a **row‑major** 1D array of `unsigned char`. Each pixel consists of three channels in RGB order: `[R, G, B]`. The index for channel `c` (0‑2) of pixel at row `i`, column `j` is:

```
index = (i * width + j) * channels + c
```

All processing functions allocate a new output image of appropriate size, leaving the input untouched. Memory is allocated with `malloc` and freed by the caller.

### Core Operations

- **Grayscale**: Converts RGB to luminance using the weighted formula `gray = 0.299*R + 0.587*G + 0.114*B`. Floating‑point arithmetic is used, then truncated to `unsigned char`.

- **Horizontal / Vertical Flip**: Reflects the image by reversing row or column order.

- **Rotate**: Supports angles that are multiples of 90°. For 90° and 270°, the output dimensions are swapped (height ↔ width). The implementation uses direct coordinate mapping and handles negative angles by normalising to 0‑359°.

- **Blur**: Applies a 3×3 box blur with **integer arithmetic only**. For each pixel, the sum of valid neighbouring pixels (within image bounds) is divided by the count of valid neighbours. Boundary pixels use fewer neighbours (e.g., corners use 4 neighbours). No out‑of‑bounds access occurs.

- **Crop**: Extracts a rectangular region defined by `(x, y, crop_width, crop_height)`, where `(x, y)` is the top‑left corner (column, row). Before cropping, the validity of the region is checked via the helper function `invalid_boundary`. If the region is invalid, the program prints an error and exits gracefully without saving output.

### Additional Features (10 points)

Four extra features were implemented:

| Feature | Difficulty | Points |
|---------|------------|--------|
| Threshold (binary) | Easy | 3 |
| Brightness adjustment | Easy | 3 |
| Color inversion | Easy | 3 |
| Resize (bilinear) | Medium | 10 |

**Total claimed: 10 points** (combining easy and medium, capped at 10 because only one medium feature chosen).

- **Threshold**: Converts the image to binary (0 or 255) based on a grayscale intensity threshold. The threshold value is optional; if not provided, a default of 128 is used. Grayscale is computed with the same formula as the `grayscale` operation.

- **Brightness Adjustment**: Adds a given integer `delta` to each channel and clamps the result to [0, 255] using the `clamp` helper function.

- **Color Inversion**: `new = 255 - old` per channel.

- **Resize (bilinear)**: Scales the image by a user‑given floating‑point factor using **bilinear interpolation**.  
  - For each output pixel, its coordinate is mapped back to the input image (floating‑point).  
  - The four surrounding pixels are used, and two‑pass linear interpolation (horizontal then vertical) produces the final value.  
  - Boundary handling: if the mapped coordinate falls outside the input, the nearest edge pixel is used (clamped).  
  - The result is rounded to the nearest integer using `+0.5` before casting to `unsigned char`.  
  - The output dimensions are computed as `(int)(scale * width)` and `(int)(scale * height)`, with a minimum of 1 pixel in each direction.

### Helper Functions

- `clamp(int value)`: Ensures a value stays within [0, 255].
- `boundary_value_check`: Clamps all pixel values to the [0, 255] range (used after loading, though all operations already guarantee this).
- `invalid_boundary`: Returns `1` if a crop rectangle is invalid, else `0`.

---

## 4. Specifications (Require / Ensure / Invariant)

### 4.1 Grayscale
- **Require**: `pixels` is a valid pointer to an RGB image of size `width × height × channels`, with `channels == 3`.  
- **Ensure**: Returns a newly allocated image of the same dimensions where every pixel's R, G, B channels are set to the computed grayscale value (0‑255). The input remains unchanged.  
- **Loop invariant**: For each processed pixel, the grayscale value is correctly computed using the weighted sum and is in [0, 255].

### 4.2 Flip (Horizontal & Vertical)
- **Require**: Same as grayscale.  
- **Ensure**: Returns a newly allocated image where pixels are mirrored horizontally (or vertically). The input remains unchanged.  
- **Loop invariant**: For each source pixel, its destination index is correctly calculated as the mirror position.

### 4.3 Rotate
- **Require**: `degree` must be one of `0, 90, 180, 270, -90, -180, -270` (normalised internally).  
- **Ensure**: Returns a newly allocated image of the appropriate dimensions (swapped for 90°/270°). The pixel mapping follows the correct rotation geometry. Returns `NULL` if the degree is unsupported.  
- **Loop invariant**: Each source pixel is placed at the correct rotated coordinate in the output.

### 4.4 Blur
- **Require**: Same as grayscale.  
- **Ensure**: Returns a newly allocated image where each pixel is the arithmetic mean (integer division) of its valid 3×3 neighbours. Boundary pixels use only available neighbours. The input remains unchanged.  
- **Loop invariant**: For each output pixel, the sum and count of valid neighbours are accumulated correctly, and the final division is performed only after the neighbourhood is fully traversed.

### 4.5 Crop
- **Require**: `x, y, crop_width, crop_height` define a rectangle completely inside the image boundaries (validated by `invalid_boundary` before calling).  
- **Ensure**: Returns a newly allocated image of size `crop_width × crop_height` containing the extracted region. If the rectangle is invalid, returns `NULL` (the caller prints an error and exits).  
- **Loop invariant**: Each destination pixel is copied from the correct source offset.

### 4.6 Threshold
- **Require**: `thres` is an integer between 0 and 255 (default 128).  
- **Ensure**: Returns a binary image (0 or 255) based on the grayscale value of each pixel.  
- **Loop invariant**: The grayscale value is computed once per pixel and compared with the threshold.

### 4.7 Brightness
- **Require**: `delta` is an integer (can be negative).  
- **Ensure**: Each channel is increased by `delta` and clamped to [0, 255].  
- **Loop invariant**: Clamping is applied to every pixel channel.

### 4.8 Invert
- **Require**: Same as grayscale.  
- **Ensure**: Each channel becomes `255 - original`.  
- **Loop invariant**: No clamping needed because result is always within [0, 255].

### 4.9 Resize (Bilinear)
- **Require**: `scale > 0`.  
- **Ensure**: Returns a new image of size `(int)(scale * width) × (int)(scale * height)` (minimum 1×1) with bilinear interpolation. Boundary pixels are used when the mapped coordinate is out of bounds.  
- **Loop invariant**: For each output pixel, the four surrounding input pixels are correctly identified and interpolated using floating‑point arithmetic, then rounded to the nearest integer.

---

## 5. Test Suite

### Test Images
A set of small BMP images (e.g., 4×4, 8×8, and a standard test image) were used to verify correctness.

### Edge Cases Tested

| Operation | Edge Cases |
|-----------|------------|
| Grayscale | All‑white, all‑black, and colour gradient images. |
| Flip | Images with odd/even width/height. |
| Rotate | 90° and 270° rotations (dimension swap), 180°, 0°, negative angles. |
| Blur | Corner pixels (only 4 neighbours), edge pixels (6 neighbours), interior (9 neighbours). |
| Crop | Valid rectangles of various sizes; **invalid** rectangles (negative coordinates, out‑of‑bounds, zero/negative dimensions) – program prints error and exits. |
| Threshold | Default (128) and user‑specified values (0, 64, 200). |
| Brightness | Delta values causing values below 0 or above 255 (clamping verified). |
| Invert | Mixed colours to ensure complement. |
| Resize | Scaling factors 0.5, 1.0, 2.0, 3.0; also extremely small (0.1) and large (10.0) factors. |

### Expected Behavior
- All functions produce the correct mathematical output as verified by manual calculation for small images.
- No memory leaks (checked with `valgrind`).
- Invalid inputs (missing parameters, unsupported rotation degrees, invalid crop region) result in clear error messages and graceful termination without writing a corrupted output file.

---

## 6. Additional Features Claimed

| Feature | Difficulty | Points |
|---------|------------|--------|
| Threshold (binary) | Easy | 3 |
| Brightness adjustment | Easy | 3 |
| Color inversion | Easy | 3 |
| Resize (bilinear) | Medium | 10 |
| **Total** | | **10** (only one medium, so total is 10) |

These features are fully implemented and integrated into the command‑line interface.

---

## 7. Known Limitations

- The program only supports BMP input/output (as required).  
- Rotation is limited to multiples of 90°.  
- The blur uses integer division, which truncates toward zero (acceptable as per spec).  
- The resize uses bilinear interpolation, which may cause slight blurring when enlarging (expected).  
- The `boundary_value_check` is called after loading, but all operations already ensure values stay in [0, 255]; it serves as a safety net.