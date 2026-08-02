# Conditional Statements

A small C program that calculates the maximum of two values

## 🧩 Description

The source file **max.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 max.c -x c main.o -o max
```

### Explanation of Flags

- `-I.` — Adds the current directory to the include path (for header files).
- `-std=c99` — Ensures the program is compiled with the C99 standard.
- `-x c` — Forces GCC to treat the next input file (`main.o`) as a C source file.
- `-o` — Specifies the name of the output executable.

---

## ▶️ Running the Program

After successful compilation, run the program with:

```bash
./max <a> <b>
```

The output is maximum of `<a>` and `<b>`.

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| `0` `5` | `5` | The maximum of `0` and `5` is `5` |
| `0` `-5` | `0` | The maximum of `0` and `-5` is `0` |
| `0` `0` | `0` | The border case considers the maximum of `0` and `0`, which is `0` |
 
---

## 🧱 File Structure

```
.
├── max.c
├── max.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
