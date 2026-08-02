# Conditional Statements

A small C program that calculates the summation of the odd numbers from 0 to a possitive number.

## 🧩 Description

The source file **odd_summation.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 odd_summation.c -x c main.o -o odd_summation
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
./odd_summation <n>
```

The output is the summation of the odd numbers between `0` and`<n>`.

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| `4`  | `4` |  `1 + 3= 4` |
| `1`  | `1` | `1 = 1` |
| `0` | `0` |  `0` by definition|
 
---

## 🧱 File Structure

```
.
├── odd_summation.c
├── odd_summation.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
