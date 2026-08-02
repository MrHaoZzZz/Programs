# Conditional Statements

A small C program that performs grade conversion from a numeric type system `[0-100]` and a letter based system `[F-A]`.

The conversion is:

| Letter | Number range |
|:-------|:-------------|
| A | 90-100 |
| B | 80-89 |
| C | 70-79 |
| D | 60-69 |
| F | 0-59 |



## 🧩 Description

The source file **grades.c** implements the logic.

- **`number_to_letter`**: Given a numeric grade, converts it to a letter grade.  
- **`letter_to_number`**: Given a letter grade, converts it to a number grade.  
- **`rounding`**: Given a number grade, rounds it.  

---

## ⚙️ Compilation Instructions

To compile the programs, use the following commands in your terminal:

- **`number_to_letter`**
```bash
gcc -I. -std=c99 grades.c -x c number_to_letter.o -o number_to_letter
```
- **`letter_to_number`**
```bash
gcc -I. -std=c99 grades.c -x c letter_to_number.o -o letter_to_number
```
- **`rounding`**
```bash
gcc -I. -std=c99 grades.c -x c rounding.o -o rounding
```

### Explanation of Flags

- `-I.` — Adds the current directory to the include path (for header files).
- `-std=c99` — Ensures the program is compiled with the C99 standard.
- `-x c` — Forces GCC to treat the next input file (`main.o`) as a C source file.
- `-o` — Specifies the name of the output executable.

---

## ▶️ Running the Program

After successful compilation, run the program with:

- **`number_to_letter`**
```bash
./number_to_letter <number-grade>
```

- **`letter_to_number`**
```bash
./letter_to_number <letter-grade>
```

- **`rounding`**
```bash
./rounding <number-grade>
```

---

## 🧪 Test Cases

Below are some sample test cases to verify the correctness of the programs:

- **`number_to_letter`**

| Input | Expected Output |
|:------|:----------------|
| `95` | `A` |
| `83` | `B` |
| `71` | `C` |
| `69` | `D` |
| `51` | `F` |

- **`letter_to_number`**

| Input | Expected Output |
|:------|:----------------|
| `A` | `100` |
| `B` | `89` |
| `C` | `79` |
| `D` | `69` |
| `F` | `59` |

 
- **`rounding`**

| Input | Expected Output |
|:------|:----------------|
| `95` | `100` |
| `83` | `80` |
| `71` | `70` |
| `69` | `70` |
| `51` | `50` |
---

## 🧱 File Structure

```
.
├── grades.c
├── grades.h
├── number_to_letter.o
├── letter_to_number.o
├── rounding.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html
