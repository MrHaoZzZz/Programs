# Divisible

A simple C program that determines if a number is divisible by another

## 🧩 Description

The source file **divisible.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 divisible.c -x c main.o -o divisible
```

### Explanation of Flags

- `-I.` — Adds the current directory to the include path (for header files).  
- `-std=c99` — Ensures the program is compiled with the C99 standard.  
- `divisible.c` — The C source file containing the function implementations.  
- `-x c` — Forces GCC to treat the next input file (`main.o`) as a C source file.
- `-o` — Specifies the name of the output executable.

---

## ▶️ Running the Program

After successful compilation, run the program with:

```bash
./divisible <dividend> <divisor>
```

The output determines if `<dividend>` is divisible by `<divisor>`.

---

## 🧩 Project Structure

```
.
├── divisible.h       # Function declarations and documentation
├── main.o            # Input/Output
└── README.md         # This file
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
