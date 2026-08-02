# Conditional Statements

A small C program that calculates if a number `n` is in an interval `[begin,end]`

## 🧩 Description

The source file **interval.c** implements the logic, while **main.o** contains the main entry point.

---

## ⚙️ Compilation Instructions

To compile the program, use the following command in your terminal:

```bash
gcc -I. -std=c99 interval.c -x c main.o -o interval
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
./interval <number> <begin> <end>
```

The output is 1 iff `number` is in interval `[begin,end]`.

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| `5` `1` `10` | `1` | `5` is in `[1,10]` |
| `-1` `0` `50` | `0` | `-1` is not in `[0,50]` |
| `0` `0` `0` | `1` | `0` is included in `[0,0]` |
 
---

## 🧱 File Structure

```
.
├── interval.c
├── interval.h
├── main.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
