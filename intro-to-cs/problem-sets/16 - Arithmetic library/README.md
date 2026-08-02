# Basic arithmetic operations using only ++ and --

A small collection of C programs that calculates basic arithmetic operations in the natural numbers, with a limited use of C functions. Use only: 
1) assignments;
2) control structures like if, for, while, etc; 
3) constants like 0, 1, etc.; 
4) comparisons like ==, <, etc. 
5) logical operators, like &&, ||, ! 
6) var++ and var--, where var is a variable; 
7) other functions already defined in the arithmetic.h file. 

*IMPORTANT:* Do not use +, *, /, %, etc!

These are the functions to be implemented (all of them in the same arithmetic.c file)

- iadd(n,m) = n + m

- imul(n,m) = n * m

- ipred(n) is the predecessor of n in Nat, namely, ipred(n) = n-1 if n > 0 and ipred(0)=0   

- isub(n,m) = n-m if n>=m and 0 otherwise.

- idiv(n,d) = the quotient in the integer division of n by d

- irem(n,d) = the remainder in the integer division of n by d

- is_prime(n) = true if and only if n is prime

- iroot(n,m) = n√m if n√m is a natural number

- ilog2(n) = number of bits to store numbers 0..(n-1)

## 🧩 Description

The source file **arithmetic.c** implements the logic of all functions listed in **arithmetic.h**, while **iadd.o**, **imul.o**, etc. contain the main entry point of each function.

---

## ⚙️ Compilation Instructions

To compile each program, use the following commands in your terminal:

```bash
gcc -I. -std=c99 arithmetic.c -x c iadd.o -o iadd
```
or 
```bash
gcc -I. -std=c99 arithmetic.c -x c imul.o -o imul
```
etc.

### Explanation of Flags

- `-I.` — Adds the current directory to the include path (for header files).
- `-std=c99` — Ensures the program is compiled with the C99 standard.
- `-x c` — Forces GCC to treat the next input file (e.g. `add.o`) as a C source file.
- `-o` — Specifies the name of the output executable.

---

## ▶️ Running the Program

After successful compilation, run each program with:

```bash
./iadd <n> <m>
```
or

```bash
./imul <n> <m>
```

The output is the corresponding arithmetic operation, e.g. the
addition of `<n>` and `<m>`, or the multiplication of `<n>` and `<m>`, whenever `<n>` and `<m>` are natural numbers. 

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the program:

| Input | Expected Output | Explanation |
|:------|:----------------|:-------------|
| iadd `7` `2`  | `9` | 7+2=9 |
| imul `2` `5`  | `10` |  2*5=10 |
| ipred `2`  | `1` |  The predecessor of 2 is 1  |
| ipred `0`  | `0` |  The predecessor of 0 is 0  |
| isub `5` `2` | `3` |  5-2=3  |
| isubt `5` `7` | `0` |  5-7=0 (subtraction in Nat)  |
| idiv `7` `2` | `3` |  7/2=3 (division in Nat)  |
| idiv `0` `2` | `0` |  0/2=0 (division in Nat)  |
| irem `7` `2` | `1` |  7%2=1 (remainder in the integer division)  |
| irem `15` `5` | `0` |  15%5=0 (remainder in the integer division)  |
| is_prime `5` | `1` |  1 (true) because 5 is prime  |
| is_prime `4` | `0` |  0 (false) because 0 is  not prime  |
| iroot `2`  `9`| `3` |  3 is the square root of 9  |
| ilog2 `4` | `2` |  2 bits are needed for 4 states |
| ilog2 `5` | `3` |  3 bits are needed for 4 states |
 
---

## 🧱 File Structure

```
.
├── arithmetic.c
├── arithmetic.h
├── iadd.o
├── imul.o
├── ipred.o
├── isub.o
├── idiv.o
├── irem.o
├── is_prime.o
├── iroot.o
├── ilog2.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
