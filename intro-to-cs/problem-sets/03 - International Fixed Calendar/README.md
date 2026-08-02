# International Fixed Calendar Utilities

A small C program that perform date conversions based on the **International Fixed Calendar (IFC)** system.

- **`days2date`**: Given the number of days elapsed since the beginning of the year, returns the corresponding IFC date.  
- **`date2days`**: Given an IFC date, returns the number of days elapsed since the beginning of the year.

---

## 🗓️ Background: The International Fixed Calendar

The **International Fixed Calendar (IFC)** is a reform calendar proposed by Moses B. Cotsworth in 1902.  
It divides the year into **13 months**, each with **28 days** (exactly four weeks), totaling **364 days**.  
An additional **“Year Day”** is inserted at the end of the year (and one **“Leap Day”** in leap years) to keep the calendar aligned with the solar year.

Each month starts on the same day of the week every year, simplifying date calculations and scheduling.

**Structure:**
- 13 months *×* 28 days = 364 days  
- + 1 “Year Day” (outside the week cycle)  
- + 1 “Leap Day” (in leap years)

For more details on the IFC, check its Wikipedia site: https://en.wikipedia.org/wiki/International_Fixed_Calendar

This project provides tools to convert between day counts and IFC dates.

**IFC Months and Day Ranges**

| Month | Day Range  |
|-------|------------|
|  1    |   1 – 28   |
|  2    |  29 – 56   |
|  3    |  57 – 84   |
|  4    |  85 – 112  |
|  5    | 113 – 140  |
|  6    | 141 – 168  |
|  7    | 169 – 196  |
|  8    | 197 – 224  |
|  9    | 225 – 252  |
| 10    | 253 – 280  |
| 11    | 281 – 308  |
| 12    | 309 – 336  |
| 13    | 337 – 364  |

**Special Days:**
- **Year Day**: day 365 (outside month cycle)  
- **Leap Day**: day 366 (in leap years)

---

## ⚙️ Compilation Instructions

Both programs depend on the logic implemented in **calendar.c**.

You can compile the code as follows:

### 📅 `date2days`

```bash
gcc -I. -std=c99 calendar.c -x c days2date.o -o days2date
```

### 📅 `days2date`

```bash
gcc -I. -std=c99 calendar.c -x c date2days.o -o date2days
```

### Explanation of Flags

- `-I.` — Adds the current directory to the include path (for header files).  
- `-std=c99` — Ensures the program is compiled with the C99 standard.  
- `calendar.c` — The C source file containing the function implementations.  
- `-x c` — Forces GCC to treat the next input file (`days2date.o`) as a C source file.
- `-o` — Specifies the name of the output executable.

---

## ▶️ Running the Program

After successful compilation, you can:

### Convert elapsed number of days to date

Run the program `days2date` with:

```bash
./days2date <n>
```

The output is the date corresponding to the <n>th day of the year.

### Convert date to elapsed number of days

Run the program `date2days` with:

```bash
./date2days <mmdd>
```

The output is number of days elapsed until <mmdd>.
 
---

## 🧱 File Structure

```
.
├── calendar.c
├── calendar.h
├── days2date.o
├── date2days.o
└── README.md
```

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to redistribute and/or modify this software under the terms of the GNU GPL as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

For full license details, see: https://www.gnu.org/licenses/gpl-3.0.html

