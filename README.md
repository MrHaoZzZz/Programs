# Programs

Personal code repository + **Fairring Medical (飞润医疗) Odoo ERP project**.

## Directory Layout

| Directory | Contents |
|---|---|
| `odoo/` | **Odoo ERP project** (development workspace + desktop client) |
| `archive/` | Misc historical files |
| `contest/` | Competition material (MCM) |
| `intro-to-cs/` | Intro. to CS course (C) |
| `intro-system-program/` | Intro. to System Program course (Java) |
| `practice/` | LeetCode / Luogu practice & algorithm templates |
| `teaching/` | Teaching examples (C) |

---

## Odoo ERP Project (`odoo/`)

Company ERP for **Shenzhen Fairring Medical Technology Co., Ltd.**, built on **Odoo 19** (docker), plus a desktop client and a remote-development tunnel.

### What we did so far

| Area | Status |
|---|---|
| **OA workflows** | 57 approval flows (oa_base + 6 dept modules: hr/fin/scm/qa/rd/asset), approval chains, add-sign / transfer / delegate / return |
| **PLM rebuild** | Strict **Stage-Gate TR0–TR4** (aligned to FR-QP-019), DHF 52-doc checklist, traceability matrix, DMR aggregate, graded design change (A/B/C), doc control (external files) |
| **UI/UX** | Global theme (`ui_theme`), ERP home dashboard, required-field asterisks, save/close text buttons, standard chatter |
| **Desktop client** | Electron app (`odoo/desktop/`), UA+token gated, versioned setup archives |
| **Remote dev tunnel** | Tailscale (TUN mode) + SSH — Mac can drive WSL directly, no public IP exposed |

### Structure

```
odoo/
├── development/
│   ├── addons/            # module dev workspace (bom_import + tools)
│   ├── diagnostics/       # playwright diagnostic scripts
│   ├── docs/              # design-docs / handoff / manuals / report / requirements / screenshots
│   └── odoo-remote-verify.py   # XML-RPC read-only verification script
└── desktop/               # Electron desktop client
```

### Environments (docker on WSL)

| Container | Purpose | Port | DB | Auth |
|---|---|---|---|---|
| `odoo19-odoo-1` | production + demo | 8081 (nginx) | `odoo19`, `odoo19_demo` | admin/admin |
| `odoo19-odoo-test-1` | test | 8082 (nginx) | `odoo19_test` | admin/admin |
| `odoo19-db-1` | Postgres 15 | 5432 | all | odoo/odoo |
| `odoo19-nginx-1` | reverse proxy | 8080/8081/8082 | — | — |

> Production DB `odoo19` (8080) requires request headers `User-Agent: OdooDesktopClient` + `X-Odoo-Client: <token>`; plain browser/curl returns 403.

### Remote development (Tailscale + SSH)

Tailnet nodes:

| Node | Tailnet IP | Notes |
|---|---|---|
| `mr-haozis-macbook-air` (Mac) | 100.117.50.11 | Tailscale TUN mode, auto-starts via LaunchDaemon |
| `engineer7` (Windows host) | 100.94.10.40 | OpenSSH → PowerShell (port 22), portproxy 2222 → WSL |
| `wsl-odoo` (WSL2 Ubuntu 22.04) | 100.75.79.122 | Odoo dev machine (root sshd) |

Connect from the Mac (`~/.ssh/config` already configured):

```bash
ssh wsl                                  # → WSL bash (root), 100.94.10.40:2222 → wsl-odoo:22
ssh Administrator@100.94.10.40          # → Windows PowerShell (port 22)
```

- All traffic goes over the Tailscale WireGuard tunnel — **no public IP exposed**.
- WSL dev: read source / git / docker / odoo shell via `ssh wsl "..."`.
- Windows ops: firewall / services / registry via `ssh Administrator@100.94.10.40 "..."` (or from WSL: `powershell.exe -NoProfile -Command '...'`).

---

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
