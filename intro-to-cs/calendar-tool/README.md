# Calendar Tool
## Overview
This is a command-line utility written in C for processing dates in the Gregorian calendar. It provides six core operations: date validation, date shifting, day difference calculation, weekday lookup, workday counting, and monthly calendar generation. The tool adheres strictly to the Gregorian calendar rules and correctly handles leap years.

## Student IDs
- `800015521`
- `800013757`

## Compilation
Compile the source files using GCC with `Makefile`:
```bash
make
```

## Date Format
All date inputs must follow the strict `YYYY-MM-DD` format:
- Exactly 10 characters in length
- Hyphens at positions 4 and 7 (0-indexed)
- All other characters must be digits
- Valid year range: 1 to 5000 (inclusive)

## Commands
The general usage syntax is:
```bash
./calendar_tool <command> <arguments...>
```

### 1. validate
Checks if a date is valid, distinguishing between format errors and logical date errors.
- **Syntax**: `./calendar_tool validate <date>`
- **Outputs**:
  - `valid date`: The date is correctly formatted and represents a real calendar date
  - `invalid format`: The date string does not match the `YYYY-MM-DD` format
  - `invalid date`: The format is correct but the date does not exist (e.g., invalid month or day)

### 2. shift
Shifts a date by a specified number of days.
- **Syntax**: `./calendar_tool shift <date> <k>`
- **Note**: Currently supports positive values of `k` only (shifts forward in time)
- **Output**: The resulting date in `YYYY-MM-DD` format

### 3. diff
Calculates the signed difference in days between two dates.
- **Syntax**: `./calendar_tool diff <date1> <date2>`
- **Output**: 
  - Positive if `date2` is later than `date1`
  - Negative if `date2` is earlier than `date1`
  - 0 if the dates are identical

### 4. weekday
Determines the day of the week for a given date.
- **Syntax**: `./calendar_tool weekday <date>`
- **Output**: 3-letter English abbreviation (Mon, Tue, Wed, Thu, Fri, Sat, Sun)
- **Convention**: Week starts on Monday

### 5. workdays
Counts the number of working days (Monday to Friday) between two dates, inclusive.
- **Syntax**: `./calendar_tool workdays <date1> <date2>`
- **Exclusions**: Saturdays and Sundays are not counted as workdays

### 6. monthcal
Prints a formatted monthly calendar for the specified year and month.
- **Syntax**: `./calendar_tool monthcal <year> <month>`
- **Format**: Week starts on Monday, each day occupies 3 characters in fixed-width columns

## Updated Validation Logic
The `validate` function now returns distinct error codes for different failure cases:
1. Returns `0` if the date is valid
2. Returns `1` for format errors:
   - String length is not 10 characters
   - Hyphens are not at positions 4 and 7
   - Non-digit characters appear outside the hyphen positions
3. Returns `2` for logical date errors:
   - Month is not between 1 and 12
   - Day is not valid for the given month and year (including leap year checks for February)

## Reference Test Cases
These test cases demonstrate the expected behavior of all commands:
```bash
./calendar_tool validate 2026-04-15
valid date

./calendar_tool validate 2026-02-29
invalid date

./calendar_tool validate 2026-4-05
invalid format

./calendar_tool shift 2026-04-15 10
2026-04-25

./calendar_tool shift 2026-04-01 -1
2026-03-31

./calendar_tool diff 2026-04-10 2026-04-15
5

./calendar_tool diff 2026-04-15 2026-04-10
-5

./calendar_tool weekday 1970-01-01
Thu

./calendar_tool weekday 2000-01-01
Sat

./calendar_tool workdays 2026-04-01 2026-04-07
5

./calendar_tool monthcal 2026 4
Mon Tue Wed Thu Fri Sat Sun
          1   2   3   4   5
  6   7   8   9  10  11  12
 13  14  15  16  17  18  19
 20  21  22  23  24  25  26
 27  28  29  30
```

## Implementation Details
- **Leap Year Calculation**: A year is a leap year if it is divisible by 400, or divisible by 4 but not by 100
- **Date Arithmetic**: Uses total days since year 1 as the base for all date calculations
- **Weekday Mapping**: 0 = Monday, 1 = Tuesday, ..., 6 = Sunday
- **Memory Management**: Dynamic memory allocation is used for date string generation in the `shift` and `monthcal` functions

## Error Handling
The tool provides clear error messages for common issues:
- `Invalid command.`: Unrecognized command entered
- `invalid format`: Date string does not match the required format
- `invalid date`: Date is logically invalid despite correct format

## File Structure
- `main.c`: Contains the main function and command-line argument parsing
- `calendar.c`: Contains all core date manipulation functions
- `Makefile`: The file that compiles the program