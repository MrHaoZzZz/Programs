# The Number of Real Roots of a Quadratic Equation

A C program for detecting the number of real roots of a quadratic equation.

## 🧩 Description

This project contains a program that determines the number of real roots of a quadratic equation (of the form *ax^2 + bx + c = 0*), based on the discriminant (*b^2 - 4ac*).  

The source file **nroots.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 nroots.c -x c main.o -o nroots
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
./nroots <a> <b> <c>
```

The output determines the number of real roots of the polynomial `<a>x^2 + <b>x + <c>`.
 
---

## 🧱 File Structure

```
.
├── nroots.c
├── nroots.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
