# Conditional Statements

A small C program that calculates the N<sup>th</sup> of the [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence).

## 🧩 Description

The source file **fibonacci.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 fibonacci.c -x c main.o -o fibonacci
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
./fibonacci <n>
```

The output is the `<n>`<sup>th</sup> number of the Fibonacci sequence.

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| `7`  | `13` |  The 7<sup>th</sup> of the Fibonacci sequence is 13 |
| `10`  | `55` |  The 10<sup>th</sup> of the Fibonacci sequence is 55 |
| `3`  | `2` |  The 3<sup>rd</sup> of the Fibonacci sequence is 2 |
| `2`  | `1` |  The 2<sup>nd</sup> of the Fibonacci sequence is 1 |
| `1`  | `1` |  The 1<sup>st</sup> of the Fibonacci sequence is 1 |
 
---

## 🧱 File Structure

```
.
├── fibonacci.c
├── fibonacci.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
