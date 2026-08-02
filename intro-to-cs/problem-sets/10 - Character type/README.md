# Conditional Statements

A small C program that tells if a character `c` is lowercase (returns 0), uppercase (returns 1), number (returns 2) or a special character (returns 3).

## 🧩 Description

The source file **chartype.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 chartype.c -x c main.o -o chartype
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
./chartype <c>
```

The output is 0 iff `c` is lowercase. 
The output is 1 iff `c` is uppercase. 
The output is 2 iff `c` is a number. 
The output is 3 iff `c` is a special character. 

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| `a` | `0` | `a` is a lowercase letter. |
| `A` | `1` | `A` is a uppercase letter. |
| `1` | `2` | `1` is a number. |
| `$` | `3` | `$` is a special character. |
 
---

## 🧱 File Structure

```
.
├── chartype.c
├── chartype.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
