# ============================================================
# 第一节课：用"和 C++ 对比"的方式学 Python 基础
# 运行方法：在 VS Code 里打开这个文件，点右上角"运行"三角形
# 或者在终端输入： ../.venv/bin/python 00_第一个Python程序.py
# ============================================================

# ---------- 1. 输出 ----------
# C++: cout << "hello" << endl;
print("hello, 数学建模")

# ---------- 2. 变量：不用声明类型、不用写分号 ----------
# C++: int x = 5;
# C++: double pi = 3.14;
# C++: string name = "xxx";
x = 5
pi = 3.14
name = "王小明"
print(x, pi, name)

# ---------- 3. 列表 List = C++ 的数组/vector ----------
# C++: vector<int> a = {1, 2, 3, 4, 5};
a = [1, 2, 3, 4, 5]
a.append(6)                      # C++: a.push_back(6);
print("a =", a)
print("第一个元素 a[0] =", a[0])   # C++: a[0]
print("最后一个元素 a[-1] =", a[-1])  # Python 特有的负索引
print("长度 len(a) =", len(a))     # C++: a.size()

# ---------- 4. for 循环 ----------
# C++: for (int i = 0; i < 5; i++) { ... }
for i in range(5):
    print("i =", i)

# ---------- 5. 函数：不用写返回类型 ----------
# C++: int add(int x, int y) { return x + y; }
def add(x, y):
    return x + y

print("add(2, 3) =", add(2, 3))
