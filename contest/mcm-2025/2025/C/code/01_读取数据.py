# ============================================================
# 第二节课：用 pandas 读取 Excel 数据
# 核心概念：DataFrame（数据框）= 一张表
#   - 像 Excel 工作表
#   - 像 C++ 的 vector<结构体>（每一行是一个人的记录）
#   - df["列名"] 取一列，像取数组的一个"切片"
# ============================================================

import pandas as pd  # 引入 pandas，约定俗成叫它 pd（C++ 里就像 #include）
from pathlib import Path  # 用于定位文件路径

# ---------- 0. 定位数据文件（推荐写法，新手必学） ----------
# __file__ = 当前这个 .py 文件
# .resolve()  = 转成绝对路径（不依赖"在哪运行"）
# .parent     = 上一层目录
# 这里 code/ 的上一级是 C/，数据文件 C/附件(1).xlsx 就在那里
this_file = Path(__file__).resolve()      # code/01_读取数据.py
project_dir = this_file.parent.parent     # C/
file = project_dir / "附件(1).xlsx"       # C/附件(1).xlsx
print("数据文件位置：", file)

# ---------- 1. 读取 Excel 的两个 sheet ----------
# 附件里有两张表：男胎检测数据、女胎检测数据
# sheet_name=None 表示"把所有 sheet 都读进来"，返回一个字典
all_sheets = pd.read_excel(file, sheet_name=None)

print("Excel 里有这些工作表：", list(all_sheets.keys()))
print()

male_df = all_sheets["男胎检测数据"]   # 男胎数据表
female_df = all_sheets["女胎检测数据"] # 女胎数据表

# ---------- 2. 看表格长什么样 ----------
print("=== 男胎数据 shape（行数, 列数） ===")
print(male_df.shape)   # C++ 里相当于 (n, m)，n 个人/条记录，m 个字段
print()

print("=== 男胎数据前 3 行（像 Excel 里看前几行） ===")
print(male_df.head(3))
print()

print("=== 女胎数据 shape ===")
print(female_df.shape)
print()

# ---------- 3. 列出所有列名（就是表头） ----------
print("=== 男胎数据的全部列名 ===")
for i, col in enumerate(male_df.columns):
    print(i, col)
print()

# ---------- 4. 取一列、看一列的基本统计 ----------
# df["列名"] 返回一个 Series，可以理解成 C++ 的一维数组/vector
age = male_df["年龄"]      # 取出"年龄"这一列
print("=== 男胎年龄这一列 ===")
print("前 5 个：", age.head(5).tolist())
print("平均值 mean：", age.mean())
print("标准差 std：", age.std())
print("最小值 min：", age.min(), " 最大值 max：", age.max())
