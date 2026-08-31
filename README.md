# Programs

Personal code repository: coursework, practice, and teaching examples.

> The Odoo ERP project used to live here but has moved to a **private repo** (`MrHaoZzZz/odoo-erp`) — see the project's own Chinese README there.

## Directory Layout

| Directory | Contents |
|---|---|
| `intro-to-cs/` | Intro. to CS course (C) |
| `intro-system-program/` | Intro. to System Program course (Java) |
| `practice/` | LeetCode / Luogu practice & algorithm templates |
| `contest/` | Competition material (MCM) |
| `teaching/` | Teaching examples (C) |
| `archive/` | Misc historical files |

## Course Projects

### intro-to-cs/ (Intro. to CS, C)

- `problem-sets/` — 26 exercises (Leap Year, Roots, FizzBuzz, Sorting, ...)
- `pa1-firefighter/` — PA1: drone firefighting simulation
- `pa2-gauss-jordan/` — PA2: Gauss-Jordan elimination / traffic planning
- `image-processing/` — image processing project
- `calendar-tool/` — calendar utilities (validate/shift/diff/weekday/workdays/monthcal)

### intro-system-program/ (Intro. to System Program, Java)

- `exercises/` — course exercises (`sys/`, `java_final/`)
- `arithmetic-interpreter/` — arithmetic expression interpreter (Spring Boot)
- `isp-reversi/` — Reversi game (Spring Boot)

## Extras

- `practice/luogu/` — Luogu problems by id (C++), `UVA10696` in Java
- `practice/templates/` — algorithm templates (primes, search)
- `contest/mcm-2025/` — 2025 MCM materials

## Build Notes

- C: `make` (Makefiles under `intro-to-cs/`)
- Java: `./mvnw spring-boot:run` (wrapper auto-downloads JDK)
- `teaching/`: `gcc file.c -o out`
- Luogu single file: `g++ 1.cpp -o 1`
