# Conditional Statements

A small C program that calculates the absolute value of a number.

## 🧩 Description

The source file **abs.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 abs.c -x c main.o -o abs
```

### Explanation of Flags

- `-I.` — Adds the current directory to the include path (for header files).  
- `-std=c99` — Ensures the program is compiled with the C99 standard.  
- `abs.c` — The C source file containing the function implementations.  
- `-x c` — Forces GCC to treat the next input file (`main.o`) as a C source file.
- `-o` — Specifies the name of the output executable.

---

## ▶️ Running the Program

After successful compilation, run the program with:

```bash
./abs <i>
```

The output is the absolute value of the integer `<i>`.

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| `5` | `5` | The absolute value of a positive number is itself. |
| `0` | `0` | Zero is its own absolute value. |
| `-3` | `3` | The absolute value of a negative number is its positive counterpart. |
| `-100` | `100` | Checks correctness for larger negative numbers. |
| `42` | `42` | Confirms the function handles arbitrary positive integers. |
| `-42` | `-42` | Confirms the function handles arbitrary positive integers. |
 
---

## 🧱 File Structure

```
.
├── abs.c
├── abs.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
