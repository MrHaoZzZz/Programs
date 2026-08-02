# Programs

个人代码仓库，按用途分门别类整理。

## 目录结构

| 目录 | 内容 |
|---|---|
| `intro-to-cs/` | **Intro. to CS** 课程（C 语言） |
| `intro-system-program/` | **Intro. to System Program** 课程（Java） |
| `practice/` | 课外练习（洛谷、LeetCode、算法模板） |
| `contest/` | 竞赛项目（数学建模 MCM） |
| `teaching/` | 教学示例（C 基础） |
| `archive/` | **ERP/Odoo 项目文档**（员工手册、流程演示、PLM 文档等，见下文） |
| `odoo-addons/` | Odoo 模块开发工作区（学习教程 + bom_import 源码 + 工具） |

## ERP / Odoo 项目（archive/）

公司 ERP（Odoo 19）相关文档，MD 与截图放在 `archive/` 根目录（保持相对路径可预览）：

- `ERP操作手册-普通员工.md` / `.pdf` — 员工操作手册（56 张截图在 `screenshots/第X章-*`）
- `PLM+ERP完整流程演示.md` — 研发→量产→生产→出货→归档 全流程演示
- `产品全生命周期操作流程.md` — 研发/量产/停产 操作流程

`archive/` 子目录：

| 目录 | 内容 |
|---|---|
| `流程与表单/` | DHR 批记录流程（xlsx/纯文本）、销售订单评审表、PLM 概念与工作流文档 |
| `学习资料/` | Odoo 插件开发教程（BOM 导入为例）+ 源码、作业 |
| `旧文件/` | 与 ERP 无关的历史/课程文件（保留备查） |
| `screenshots/` | 各文档的截图（第X章、产品生命周期、流程-ERP） |

## 课程项目

### intro-to-cs/ (Intro. to CS, C 语言)

- `problem-sets/` — 26 道编程题（Leap Year, Roots, FizzBuzz, Sorting 等）
- `pa1-firefighter/` — PA1: 无人机消防模拟
- `pa2-gauss-jordan/` — PA2: 高斯-约当消元 / 交通规划
- `image-processing/` — 图像处理项目
- `calendar-tool/` — 日历工具（validate/shift/diff/weekday/workdays/monthcal）

### intro-system-program/ (Intro. to System Program, Java)

- `exercises/` — 课程练习（`sys/` 含各章节练习与模拟题，`java_final/` 为期末文件 IO 练习）
- `arithmetic-interpreter/` — 算术表达式解释器（Spring Boot）
- `isp-reversi/` — 黑白棋（Reversi）游戏（Spring Boot）

## 课外

- `practice/luogu/` — 洛谷刷题，按题号分目录（C++），`UVA10696` 为 Java
- `practice/templates/` — 算法模板（素数、搜索）
- `contest/mcm-2025/` — 2025 数学建模竞赛材料

## 构建说明

- C 项目用 `make`（`intro-to-cs/` 下各项目自带 Makefile）
- Java 项目用 Maven：`./mvnw spring-boot:run`（无需 JDK 全局安装，wrapper 自动下载）
- `teaching/` 直接 `gcc 文件名.c -o 输出` 编译
- Luogu 单文件：`g++ 1.cpp -o 1`