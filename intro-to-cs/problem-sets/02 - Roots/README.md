# hasroots

A C program for detecting whether a given quadratic equation has real roots.

## 🧩 Description

This project contains a program that determines whether a quadratic equation (of the form *ax^2 + bx + c = 0*) has real roots, based on the discriminant (*b^2 - 4ac*).  

The source file **hasroots.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 hasroots.c -x c main.o -o hasroots
```

### Explanation of Flags

- `-I.` — Adds the current directory to the include path (for header files).  
- `-std=c99` — Ensures the program is compiled with the C99 standard.  
- `hasroots.c` — The C source file containing the function implementations.  
- `-x c` — Forces GCC to treat the next input file (`main.o`) as a C source file.
- `-o hasroots` — Specifies the name of the output executable (`hasroots`).

---

## ▶️ Running the Program

After successful compilation, run the program with:

```bash
./hasroots <a> <b> <c>
```

The output determines if the polynomial <a>x^2 + <b>x + <c> has real roots.
 
---

## 🧱 File Structure

```
.
├── hasroots.c
├── hasroots.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
