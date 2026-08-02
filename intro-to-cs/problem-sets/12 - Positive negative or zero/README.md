# Conditional Statements

A small C program that determines if a number is positive, negative or zero.

## 🧩 Description

The source file **positive_negative_zero.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 positive_negative_zero.c -x c main.o -o positive_negative_zero
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
./positive_negative_zero <n>
```

The output is 0 iff `n` is zero. 
The output is 1 iff `n` is greater than zero. 
The output is -1 iff `n` is lesser than zero. 

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| `0` | `0` | `0` is equal to `0`. |
| `1` | `1` | `1` is greater than `0`. |
| `-1` | `-1` | `-1` is lesser than `0`. |
 
---

## 🧱 File Structure

```
.
├── positive_negative_zero.c
├── positive_negative_zero.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
