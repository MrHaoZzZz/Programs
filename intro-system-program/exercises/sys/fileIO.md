## 第二章 迭代器（Iterator）与流（Stream）
对应课件：Lecture 08 + Tutorial 09

### 2.1 迭代器（Iterator）基础
**定义**：迭代器（Iterator）是提供标准方式遍历集合的对象，遍历过程不需要暴露集合的底层实现。

**核心方法**：
- `boolean hasNext()`：判断集合中是否还有下一个元素。
- `E next()`：获取下一个元素，并将迭代器前进到下一个位置。

**核心价值**：解耦“集合遍历逻辑”和“元素处理逻辑”。同一份元素处理算法，可以适配所有实现了迭代器接口的集合，无需修改代码。

### 2.2 迭代器示例：范围迭代器
实现一个生成 `[start, end)` 区间整数的迭代器：
```java
class RangeIterator {
    RangeIterator(int start, int end) {
        this.start = start;
        this.end = end;
        assert this.start <= this.end;
    }

    boolean hasNext() {
        return this.start < this.end;
    }

    int next() {
        int current = this.start;
        this.start++;
        return current;
    }

    private int start;
    private int end;
}
```
逐行解析：
- 字段 `start` 表示当前迭代位置，`end` 是结束边界（不包含）。
- 构造方法接收起止值，通过断言保证起始值不大于结束值。
- `hasNext()`：只要当前位置小于结束值，就存在下一个元素。
- `next()`：保存当前值，将 `start` 加1，返回保存的当前值。

使用示例：
```java
RangeIterator it = new RangeIterator(10, 14);
System.out.println(it.hasNext()); // 输出 true
System.out.println(it.next());    // 输出 10
// 依次调用next会返回11、12、13，之后hasNext返回false
```

### 2.3 迭代器的解耦优势
以三维矩阵求和为例：不使用迭代器时，需要编写三层嵌套循环，算法与矩阵维度强绑定。
```java
int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < p; k++) {
            sum += matrix.get(i, j, k);
        }
    }
}
```

使用三维盒子迭代器（BoxIterator）后，代码大幅简化：
```java
BoxIterator it = new BoxIterator(n, m, p);
int sum = 0;
while (it.hasNext()) {
    Point x = it.next();
    sum += matrix.get(x.i, x.j, x.k);
}
```
遍历逻辑完全封装在迭代器内部，求和算法不需要关心矩阵维度和遍历顺序，只要迭代器接口一致，算法就可以复用到任意集合上。

### 2.4 常见数据结构的迭代器实现
#### 2.4.1 链表迭代器
链表（Linked List）的迭代器只需保存当前节点的引用即可实现遍历：
```java
class List<T> {
    private class Node {
        T elem;
        Node next;
    }
    private Node start;

    ListIterator iterator() {
        return new ListIterator(this.start);
    }

    class ListIterator {
        private ListIterator(Node p) {
            this.current = p;
        }
        boolean hasNext() {
            return this.current != null;
        }
        T next() {
            T elem = this.current.elem;
            this.current = this.current.next;
            return elem;
        }
        private Node current;
    }
}
```
代码解析：
- `ListIterator` 是 `List` 的内部类，可以访问 `List` 的私有 `Node` 类型。
- 构造方法接收起始节点，初始化 `current` 指针。
- `hasNext` 判断当前指针是否为空。
- `next()` 返回当前节点的元素，然后将 `current` 移动到下一个节点。
- `List` 类提供 `iterator()` 方法，返回指向链表头部的全新迭代器。

#### 2.4.2 二叉树迭代器
二叉树（Binary Tree）的深度优先迭代器，通过栈实现前序遍历：
```java
class BinaryTreeIterator<T> {
    private Stack<BinaryTree<T>> stack;

    BinaryTreeIterator(BinaryTree<T> tree) {
        this.stack = new Stack<BinaryTree<T>>();
        if (tree != null) {
            this.stack.push(tree);
        }
    }

    boolean hasNext() {
        return this.stack.size() > 0;
    }

    T next() {
        BinaryTree<T> t = this.stack.pop();
        if (t.left != null) {
            this.stack.push(t.left);
        }
        if (t.right != null) {
            this.stack.push(t.right);
        }
        return t.elem;
    }
}
```
代码解析：
- 用栈保存待访问的子树；构造时若树非空，将根节点压入栈。
- `hasNext` 判断栈是否非空。
- `next()` 弹出栈顶节点，先压入右子树、再压入左子树（栈后进先出，保证左子树先被访问），返回当前节点的元素，实现前序遍历。

### 2.5 流（Stream）
**定义**：流（Stream）是可以无限长度的元素序列，数据按需生成/加载，不会一次性全部载入内存。

**典型应用场景**：
- 在线视频：逐帧加载播放，而非下载完整视频
- 大文件读取：逐块读取，不将整个文件载入内存
- 数据库查询结果：逐条返回，不加载全部结果集

流可以完美用迭代器表示：迭代器“逐个获取、按需生成”的特性，正好匹配流的模式。

**示例：斐波那契（Fibonacci）无限流**
```java
class FibonacciIterator {
    FibonacciIterator() {
        this.a = 0;
        this.b = 1;
    }
    int next() {
        int current = this.a;
        this.a = this.b;
        this.b = current + this.b;
        return current;
    }
    private int a;
    private int b;
}
```
代码解析：这个迭代器的 `hasNext` 永远返回 `true`，代表无限序列。每次调用 `next()` 生成下一个斐波那契数，不需要预先存储所有数值，内存占用恒定。

### 2.6 Tutorial 09 迭代器练习
#### 2.6.1 偶数迭代器
生成 `0, 2, 4, 6...` 无限偶数序列的迭代器：
```java
class EvenIterator implements Iterator<Integer> {
    private int current = 0;

    @Override
    public boolean hasNext() {
        return true;
    }

    @Override
    public Integer next() {
        int result = current;
        current += 2;
        return result;
    }
}
```
代码解析：实现Java标准 `Iterator<Integer>` 接口，`current` 从0开始，每次 `next` 返回当前值并加2，`hasNext` 恒为真表示无限序列。

#### 2.6.2 反向数组迭代器
从后往前遍历数组的泛型迭代器：
```java
class ReverseArrayIterator<T> implements Iterator<T> {
    private T[] array;
    private int index;

    public ReverseArrayIterator(T[] array) {
        this.array = array;
        this.index = array.length - 1;
    }

    @Override
    public boolean hasNext() {
        return index >= 0;
    }

    @Override
    public T next() {
        return array[index--];
    }
}
```
代码解析：
- 构造方法接收数组，将 `index` 初始化为数组最后一个元素的下标。
- `hasNext`：下标大于等于0则还有元素。
- `next`：返回当前下标的元素，下标自减1，实现倒序遍历。

#### 2.6.3 斐波那契迭代器
```java
class FibonacciIterator implements Iterator<Integer> {
    private int prev = 0;
    private int curr = 1;

    @Override
    public boolean hasNext() {
        return true;
    }

    @Override
    public Integer next() {
        int next = prev + curr;
        prev = curr;
        curr = next;
        return prev;
    }
}
```
代码解析：用 `prev` 和 `curr` 保存序列的前两个数，每次 `next` 计算下一个数，更新两个指针，返回新的 `prev`（即本次的斐波那契数）。前10次调用输出：`1 1 2 3 5 8 13 21 34 55`。

### 2.7 抽象语法树（Abstract Syntax Tree, AST）
**定义**：抽象语法树（AST）是源代码的树形表示，每个节点代表一种语法结构（数字、加法、乘法等）。
**核心作用**：正确表示运算符优先级，便于遍历、计算、转换代码。

例如表达式 `(3+4)*2` 对应的AST：根节点是乘法，左孩子是加法（左3、右4），右孩子是2。如果不用树结构、线性从左到右计算，会错误地先算 `3+4` 再乘2，违背乘法优先级。

#### 解释器完整流水线
1. **词法分析器（Lexer/Tokenizer）**：将源代码文本拆分为词法单元（Token），例如把 `"35 + 42 * 2"` 拆分为 `[数字35, 加号, 数字42, 乘号, 数字2]`。
2. **语法分析器（Parser）**：根据语法规则将Token序列转换为AST，建立层级结构。
3. **求值器（Evaluator/Interpreter）**：遍历AST，递归计算每个节点的值，得到最终结果。

---

## 第三章 输入输出：文件读写
对应课件：Lecture 09 + Tutorial 09 序列化部分

### 3.1 存储器层级
计算机存储分为多层，各层在速度、成本、容量、特性上差异显著：
| 存储层级 | 速度 | 单位成本 | 容量 | 特性 |
| :--- | :--- | :--- | :--- | :--- |
| CPU寄存器 / CPU缓存 | 极快 | 极高 | 极小 | 易失性，断电数据丢失 |
| 主内存（DRAM/RAM） | 快 | 中等 | 中等 | 易失性 |
| 二级存储（SSD/HDD） | 慢 | 极低 | 极大 | 持久化，断电数据保留 |

**文件（File）**是操作系统提供的核心抽象，用于在二级存储上读写数据，通过文件名引用。文件本质是字节（Byte，8位）的序列，不直接存储字符串、对象等高级数据，这些数据必须编码为字节后才能写入文件。

### 3.2 文件的基本操作
操作系统提供的标准文件操作：
- 打开文件：分为读模式、写模式
- 从已打开的文件读取数据
- 向已打开的文件写入数据
- 关闭文件，释放系统资源

### 3.3 Java中的文件读取
#### 3.3.1 单字节读取
使用 `FileInputStream` 读取文件的单个字节：
```java
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        FileInputStream fis = new FileInputStream("a.txt");
        System.out.println(fis.read());
        fis.close();
    }
}
```
代码解析：
- `FileInputStream` 是字节输入流，用于读取文件的原始字节。
- `read()` 方法读取一个字节，返回 `int` 类型：读到文件末尾（EOF）返回-1，否则返回0~255之间的整数。
- `close()` 方法关闭文件，释放操作系统资源。

#### 3.3.2 异常（Exception）处理
IO操作随时可能失败（文件不存在、无权限、磁盘已满、设备断开等），Java通过异常机制处理这类错误。`FileInputStream` 的构造、`read`、`close` 方法都可能抛出 `IOException`。

处理异常的两种方式：
1. **捕获处理（try-catch）**：当前方法自行处理异常
```java
try {
    FileInputStream fis = new FileInputStream("a.txt");
    System.out.println(fis.read());
    fis.close();
} catch (IOException e) {
    System.out.println("Could not read the file.");
}
```
2. **向上抛出（throws）**：在方法签名后声明 `throws IOException`，将异常交给调用者处理。

#### 3.3.3 读取文件全部字节
循环读取直到文件末尾：
```java
ArrayList<Byte> bytes = new ArrayList<Byte>();
FileInputStream fis = new FileInputStream("a.txt");
while (true) {
    int next = fis.read();
    if (next == -1) {
        break;
    }
    bytes.add((byte)next);
}
fis.close();
```
代码解析：无限循环调用 `read`，返回-1则退出循环，否则转换为 `byte` 类型加入列表。

### 3.4 字符编码（Encoding）
文件只存储字节，字符需要通过编码规则与字节序列对应。**编码就是字符与字节序列的映射规则**。

常见编码标准：
- ASCII：英文字符对应0~127的单字节编码。
- UTF-8：变长编码，兼容ASCII，中文通常占3字节，是目前最通用的编码。
- GBK、Big5：中文地区的传统编码，同一个汉字在不同编码下的字节完全不同。

**核心原则**：读写文本文件必须明确编码，否则读取内容会出现乱码。

Java中使用 `InputStreamReader` 按指定编码读取字符：
```java
FileInputStream fis = new FileInputStream("nihao.txt");
InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
while (true) {
    int next = isr.read();
    if (next == -1) break;
    System.out.println((char)next);
}
isr.close();
```
代码解析：`InputStreamReader` 包装字节流，按照指定的UTF-8编码将字节解码为字符。`read()` 返回字符的编码值，强制转换为 `char` 即可得到对应字符。

### 3.5 文件写入
#### 3.5.1 字节写入
使用 `FileOutputStream` 写入字节：
```java
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        FileOutputStream fos = new FileOutputStream("a.txt");
        fos.write(65);
        fos.write(66);
        fos.write(67);
        fos.close();
    }
}
```
代码解析：向文件写入65、66、67三个字节，对应ASCII中的'A'、'B'、'C'。

#### 3.5.2 文本写入
使用 `OutputStreamWriter` 按指定编码写入文本：
```java
FileOutputStream fos = new FileOutputStream("a.txt");
OutputStreamWriter osw = new OutputStreamWriter(fos, "UTF-8");
osw.write("你好");
osw.close();
```
代码解析：将字符串按照UTF-8编码转换为字节序列，再写入文件。

### 3.6 序列化（Serialization）
- **序列化**：将对象转换为字节序列写入文件的过程。
- **反序列化**：将字节序列还原为对象的过程。

#### 3.6.1 整数的序列化
约定格式：非负整数用十进制数字字符表示，以分号结尾，例如1234序列化为 `"1234;"`。

**读取整数方法**
```java
int readInt(FileInputStream fis) throws IOException {
    int n = 0;
    while (true) {
        int next = fis.read();
        if (next == ';') {
            break;
        }
        int digit = next - '0';
        n = 10 * n + digit;
    }
    return n;
}
```
代码解析：逐个读取字符，遇到分号停止。每次将数字字符转换为数值，通过 `n = 10*n + digit` 累加得到完整整数。

**写入整数方法**
```java
void writeInt(FileOutputStream fos, int n) throws IOException {
    int p = 1;
    while (10 * p <= n) {
        p = 10 * p;
    }
    while (p >= 1) {
        fos.write('0' + (n / p));
        n = n % p;
        p = p / 10;
    }
    fos.write(';');
}
```
代码解析：先计算最高位的位权 `p`，再从高位到低位依次取出每一位数字，转换为字符写入，最后写入分号结尾。

#### 3.6.2 数组的序列化
约定格式：先存储数组长度，再存储所有元素，均使用上述整数格式。例如数组 `[123, 456, 789]` 序列化为 `"3;123;456;789;"`。

Tutorial 09中的Reversi游戏存档采用类似的文本序列化格式：
- 格式：`当前玩家 + 棋盘大小 + 棋盘内容`，例如 `B8;EEEEEEEEEEEEEEEEEEEEEEEEEEWWWEEEEEWWBBEEWWWBBEEEBBBBBBEEEEE`
- `B` 表示黑方回合，`8` 表示8×8棋盘，`E` 是空位，`B` 是黑子，`W` 是白子。

---

## 第四章 IO缓冲与随机访问
对应课件：Lecture 10 + Tutorial 10

### 4.1 缓冲（Buffering）
#### 4.1.1 缓冲的意义
每次调用 `read()`/`write()` 都会发起一次操作系统调用，系统调用的开销很高。如果逐字节读写大文件，会产生百万次系统调用，效率极低。

**缓冲思想**：一次性读写一大块数据（称为缓冲区，Buffer），在内存中逐个处理，大幅减少系统调用次数，显著提升性能。

#### 4.1.2 缓冲读取
使用字节数组作为缓冲区，批量读取文件内容：
```java
FileInputStream fis = new FileInputStream("a.txt");
byte[] buffer = new byte[BUFFER_SIZE];
fis.read(buffer);
fis.close();
```
`read(byte[] buffer)` 方法：最多读取 `buffer.length` 个字节存入缓冲区，返回实际读取到的字节数，读到文件末尾返回-1。

**批量读取求和示例**
```java
int add_all_bytes(String filename) throws IOException {
    FileInputStream fis = new FileInputStream(filename);
    byte[] buffer = new byte[BUFFER_SIZE];
    int sum = 0;
    int n;
    while ((n = fis.read(buffer)) != -1) {
        for (int i = 0; i < n; i++) {
            sum += buffer[i];
        }
    }
    fis.close();
    return sum;
}
```
代码解析：循环读取，每次尽量填满缓冲区，然后处理缓冲区内的 `n` 个有效字节。`BUFFER_SIZE` 通常设为1KB、8KB、64KB等。

#### 4.1.3 缓冲写入
批量写入缓冲区数据：
```java
FileOutputStream fos = new FileOutputStream("a.txt");
byte[] buffer = new byte[BUFFER_SIZE];
// 填充缓冲区数据
fos.write(buffer);
fos.close();
```
`write(byte[] buffer, int offset, int length)` 可以只写入缓冲区的指定子区间。

**批量写入随机字节示例**
```java
void write_random(String filename, int n) throws IOException {
    byte[] buffer = new byte[BUFFER_SIZE];
    FileOutputStream fos = new FileOutputStream(filename);
    Random random = new Random();
    int remaining = n;
    while (remaining > 0) {
        random.nextBytes(buffer);
        int written = Math.min(remaining, BUFFER_SIZE);
        fos.write(buffer, 0, written);
        remaining = remaining - written;
    }
    fos.close();
}
```
代码解析：每次生成一缓冲区的随机字节，写入文件，直到写够 `n` 个字节。

### 4.2 随机访问（Random Access）
之前的文件读写都是顺序模式，只能从头到尾依次读写。`RandomAccessFile` 类支持随机跳转读写文件的任意位置。

**核心方法**：
- `new RandomAccessFile(String filename, String mode)`：打开文件，`mode` 为 `"r"` 只读，`"rw"` 读写。
- `void seek(long position)`：跳转到文件的指定字节位置。
- `long getFilePointer()`：获取当前读写位置。
- `long length()`：获取文件总长度。
- 读写方法：`readByte()/writeByte()`、`readShort()/writeShort()`、`readInt()/writeInt()`、`readLong()/writeLong()`，分别读写1、2、4、8字节的数值。

#### 4.2.1 字节序（Endianness）
多字节整数在存储时有两种字节顺序：
- **大端（Big Endian）**：高位字节在前，例如1000000存储为 `[0, 15, 66, 64]`
- **小端（Little Endian）**：低位字节在前，例如1000000存储为 `[64, 66, 15, 0]`

Java的 `RandomAccessFile` 默认使用大端序。很多文件格式（如WAV、BMP）采用小端序，需要手动通过 `Integer.reverseBytes()`、`Short.reverseBytes()` 翻转字节顺序。

#### 4.2.2 示例：WAV音频文件处理
WAV是无压缩音频格式，文件结构分为三部分：
1. RIFF头（12字节）："RIFF"标识、文件大小、"WAVE"标识
2. fmt块（24字节）：格式参数，包括采样率、位深、声道数
3. data块：音频采样数据

WAV文件中所有整数均为小端存储。

**示例：反转WAV文件的音频内容**
```java
void reverse_wav(String filename) throws IOException {
    RandomAccessFile f = new RandomAccessFile(filename, "rw");
    // 跳转到data块大小字段，读取采样总数
    f.seek(40);
    int n = Integer.reverseBytes(f.readInt()) / 2;
    // 读取所有采样
    ArrayList<Short> samples = new ArrayList<Short>();
    for (int i = 0; i < n; i++) {
        samples.add(Short.reverseBytes(f.readShort()));
    }
    // 跳回数据起始位置，倒序写入
    f.seek(44);
    for (int i = 0; i < n; i++) {
        f.writeShort(Short.reverseBytes(samples.get(n - 1 - i)));
    }
    f.close();
}
```
代码解析：先读取采样总数，将所有采样读入内存，再倒序写回文件，实现音频反转效果。

### 4.3 资源管理
#### 4.3.1 资源泄漏问题
如果读写过程中抛出异常，`close()` 方法就不会执行，文件资源会发生泄漏。

传统的 `try-finally` 写法：
```java
FileInputStream fis = new FileInputStream(filename);
try {
    fis.read();
} catch (IOException e) {
    // 处理错误
} finally {
    fis.close();
}
```
但这种写法还需要处理构造失败、`close` 本身抛异常的情况，代码非常繁琐且容易出错。

#### 4.3.2 try-with-resources
Java提供 `try-with-resources` 语法，自动关闭所有实现了 `AutoCloseable` 接口的资源：
```java
try (FileInputStream fis = new FileInputStream(filename)) {
    fis.read();
} catch (IOException e) {
    // 处理错误
}
```
无论代码正常结束还是抛出异常，都会自动调用 `fis.close()`，保证资源正确释放，代码简洁且安全。

### 4.4 Tutorial 10：BMP图像格式与滤镜
#### 4.4.1 BMP文件结构
BMP是无压缩位图格式，结构如下：
- BMP文件头（14字节）："BM"标识、文件大小、像素数据偏移量
- DIB头（40字节）：图像宽度、高度、位深、压缩方式等
- 像素数组：从下到上、从左到右存储，每个像素为BGR顺序（蓝、绿、红）
- 行填充：每行的字节数必须是4的倍数，不足则补0填充，填充量公式：`padding = (4 - (width * 3) % 4) % 4`

#### 4.4.2 小端整数读取
BMP的数值均为小端序，读取方法如下：
```java
private int readLittleEndianIntFromStream(FileInputStream fis) throws IOException {
    int b1 = fis.read(); // 最低位字节
    int b2 = fis.read();
    int b3 = fis.read();
    int b4 = fis.read(); // 最高位字节
    return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
}
```
代码解析：
- `<<` 是左移运算符，将字节移动到整数对应的位位置，例如 `b2 << 8` 表示将第二个字节左移8位。
- `|` 是按位或运算符，将四个字节的位组合成一个完整的int整数。

#### 4.4.3 常见图像滤镜
1. **灰度滤镜（Grayscale）**：采用光度法将彩色转为灰度，公式：`gray = 0.299*R + 0.587*G + 0.114*B`
```java
public BMPImage toGrayscale() {
    byte[] newData = new byte[pixelData.length];
    for (int i = 0; i < pixelData.length; i += 3) {
        int b = pixelData[i] & 0xFF;
        int g = pixelData[i+1] & 0xFF;
        int r = pixelData[i+2] & 0xFF;
        int gray = (int)(0.299 * r + 0.587 * g + 0.114 * b);
        newData[i] = (byte) gray;
        newData[i+1] = (byte) gray;
        newData[i+2] = (byte) gray;
    }
    return new BMPImage(...);
}
```
代码解析：`& 0xFF` 将有符号的byte转换为0~255的无符号值；计算灰度后，三个颜色通道设置为同一个灰度值。

2. **反色滤镜（Negative）**：每个通道取反，`newValue = 255 - 原值`
3. **亮度调节**：每个通道加上delta值，裁剪到0~255范围
4. **模糊滤镜**：每个像素取周围3×3邻域像素的平均值

#### 4.4.4 缓冲的性能优势
- 逐字节读写：1920×1080的图片需要约620万次IO调用，速度极慢
- 缓冲读写：仅需2次IO调用（读取头、读取像素），性能提升几个数量级

**结论**：处理大量数据时必须使用缓冲。

---

## 第五章 面向对象：子类与继承（Inheritance）
对应课件：Lecture 11 + Tutorial 11

### 5.1 类层级结构
面向对象编程中，类按照层级组织：
- 每个类有且仅有一个直接父类（超类，Superclass）
- 一个类可以有零个或多个子类（Subclass）
- 所有类的根是 `Object` 类，它没有父类

子类与父类是 **“is-a”（是一种）** 关系：所有子类的实例，同时也是父类的实例。例如 `Dog` 是 `Mammal` 的子类，那么所有狗都是哺乳动物。

Java中使用 `extends` 关键字声明父类：
```java
class Animal {}
class Mammal extends Animal {}
class Dog extends Mammal {}
```
如果不写 `extends`，类默认继承 `Object`。

### 5.2 里氏替换原则（Liskov Substitution Principle）
核心含义：所有对父类成立的属性/方法，对子类也一定成立。如果一个方法接收父类参数，那么传入任何子类对象都能正常工作。
例如方法 `int age(Animal a)` 可以接收 `Dog`、`Cat` 等所有 `Animal` 子类的对象。
该原则是面向对象多态性的基础。

### 5.3 继承（Inheritance）
子类会继承父类所有的字段和方法，无需重复编写代码，实现代码复用。
```java
class Button {
    void setCaption(String caption) {...}
    String getCaption() {...}
}
class AcceptButton extends Button {
    void accept() {...}
}
```
代码解析：`AcceptButton` 继承了 `Button`，自动拥有 `setCaption` 和 `getCaption` 方法，同时新增自己的 `accept` 方法。

### 5.4 方法重写（Method Overriding）
子类可以重新定义父类已有的方法，覆盖父类的实现，称为方法重写。
```java
class BasicRobot {
    void speak() {
        System.out.println("Hi, I'm a robot!");
    }
}
class CleaningRobot extends BasicRobot {
    @Override
    void speak() {
        System.out.println("Hi, I'm a cleaning robot!");
    }
}
```
代码解析：
- `@Override` 注解表示该方法重写了父类方法，不是必须的，但可以让编译器检查语法正确性。
- 多态特性：通过父类引用调用方法时，会执行对象实际类型的方法。例如将 `CleaningRobot` 对象存入 `ArrayList<BasicRobot>`，遍历调用 `speak()` 时，会执行各自重写后的版本。

如果方法被 `final` 关键字修饰，则不能被子类重写。

### 5.5 受保护访问（Protected）
Java的三级访问权限：
- `private`：仅本类可以访问
- `protected`：本类和所有子类可以访问
- `public`：所有类都可以访问

```java
class Counter {
    protected int value;
    void increase() { this.value++; }
}
class DecreaseableCounter extends Counter {
    void decrease() { this.value--; }
}
```
代码解析：`value` 字段为 `protected`，子类 `DecreaseableCounter` 可以直接访问，同时对外不可见，兼顾了继承便利性和封装性。

### 5.6 抽象类（Abstract Class）
抽象类不能直接实例化（不能用 `new` 创建对象），只能作为父类被子类继承。
**抽象方法**：只有方法签名、没有实现体的方法，必须由子类实现。包含抽象方法的类必须声明为 `abstract`。

```java
abstract class Animal {
    abstract String voice();
    void speak() {
        System.out.println(this.voice());
    }
}
class Dog extends Animal {
    String voice() {
        return "woof";
    }
}
```
代码解析：`Animal` 是抽象类，`voice()` 是抽象方法，子类 `Dog` 必须实现 `voice()` 方法；`speak()` 是具体方法，所有子类直接继承该实现。

抽象类的作用：定义统一的接口规范，同时提供公共代码实现。

### 5.7 super关键字
`super` 关键字有两个核心用途：
1. 调用父类构造方法：`super(参数)`，必须写在子类构造方法的第一行。
2. 调用父类被重写的方法：`super.方法名(参数)`，避免无限递归。

**示例：带撤销功能的图片类**
```java
class ImageWithUndo extends Image {
    ImageWithUndo(int width, int height) {
        super(width, height);
        this.history = new Stack<UndoAction>();
    }
    void set(int i, int j, Color color) {
        history.push(new UndoAction(i, j, color));
        super.set(i, j, color);
    }
}
```
代码解析：
- 构造方法第一行调用父类构造，初始化图片基础数据。
- `set` 方法重写了父类的 `set`，先保存撤销记录，再用 `super.set` 调用父类原本的set方法。如果写 `this.set` 会递归调用自身，造成死循环。

### 5.8 Tutorial 11 补充内容
#### 5.8.1 Object类
所有类都直接或间接继承 `Object`，因此所有对象都默认拥有以下方法：
- `toString()`：返回对象的字符串表示
- `equals()`：判断两个对象内容是否相等
- `hashCode()`：返回对象的哈希值

默认实现基于内存地址，实际开发中通常需要重写。

**重写示例**
```java
public class Student {
    private String name;
    private int id;

    @Override
    public String toString() {
        return "Student{name=" + name + ", id=" + id + "}";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Student)) return false;
        Student other = (Student) obj;
        return this.name.equals(other.name) && this.id == other.id;
    }
}
```

#### 5.8.2 异常继承体系
Java中所有异常都继承自 `Throwable`，分为 `Exception`（可捕获的业务异常）和 `Error`（系统级错误）。`IOException`、`RuntimeException` 都是 `Exception` 的子类，开发者也可以自定义异常类，继承 `Exception` 即可。

---

## 第六章 接口（Interface）
对应课件：Lecture 12 + Tutorial 12

### 6.1 继承的局限性
Java是单继承语言，一个类只能有一个父类。但现实中很多对象存在跨类别的共同行为，例如蝙蝠和飞机都会飞，但蝙蝠属于动物、飞机属于交通工具，无法通过同一个父类继承 `fly` 方法。

接口就是为解决这个问题设计的：定义行为契约，不限制类的继承体系，实现行为的跨类复用。

### 6.2 接口的定义与实现
接口只定义方法签名，不提供方法实现。类使用 `implements` 关键字实现接口，必须实现接口的所有方法。
```java
interface Flying {
    void fly();
}

class Bat extends Animal implements Flying {
    public void fly() { /* 飞行实现 */ }
}
class Airplane extends Vehicle implements Flying {
    public void fly() { /* 飞行实现 */ }
}
```
注意：接口中的方法默认是public的，实现类必须将方法声明为 `public`。

接口可以作为类型使用，所有实现了该接口的类的对象，都可以赋值给接口类型的变量：
```java
void makeThemFly(ArrayList<Flying> flyingObjects) {
    for (Flying f : flyingObjects) {
        f.fly();
    }
}
```
该方法可以接收任何实现了 `Flying` 接口的对象，完全不关心对象的父类是什么。

### 6.3 接口的典型应用
#### 6.3.1 可迭代与迭代器接口
Java标准库的 `Iterable` 和 `Iterator` 就是最经典的接口：
```java
interface Iterator<T> {
    T next();
    boolean hasNext();
}
interface Iterable<T> {
    Iterator<T> iterator();
}
```
所有实现了 `Iterable` 接口的集合，都可以用for-each循环遍历。for-each语法本质就是调用 `iterator()` 方法获取迭代器，然后循环调用 `hasNext` 和 `next`。

#### 6.3.2 访问者模式（Visitor Pattern）
迭代器是“迭代器持有遍历逻辑，外部处理元素”；访问者模式相反：“集合持有遍历逻辑，访问者处理元素”。

**示例：树的访问者**
```java
interface TreeVisitor<T> {
    void visitNode(T root);
    void visitEmptyTree();
}
abstract class Tree<T> {
    abstract void accept(TreeVisitor<T> visitor);
}
```
树的子类实现 `accept` 方法，将自身传入visitor的对应方法。不同的visitor实现不同的处理逻辑（求和、打印、查找等），无需修改树的代码。

### 6.4 函数式接口（Functional Interface）
只包含一个抽象方法的接口，称为函数式接口。
```java
interface UnaryFunction {
    double apply(double x);
}
```
基于该接口可以实现通用的 `map` 方法，将函数应用到列表的每个元素上：
```java
ArrayList<Double> map(UnaryFunction f, ArrayList<Double> a) {
    ArrayList<Double> res = new ArrayList<Double>();
    for (double x : a) {
        res.add(f.apply(x));
    }
    return res;
}
```

### 6.5 Lambda表达式
对于函数式接口，无需显式编写类来实现，可以直接用Lambda表达式创建接口对象：
```java
System.out.println(map(x -> Math.sin(x), a));
```
`x -> Math.sin(x)` 就是Lambda表达式，等价于一个实现了 `UnaryFunction` 的匿名类对象，`apply` 方法的逻辑就是计算 `sin(x)`。Lambda大幅简化了函数式代码的写法。

### 6.6 Tutorial 12 补充内容
#### 6.6.1 钻石问题（Diamond Problem）
多实现继承会导致钻石问题：类D继承B和C，B和C都继承A并重写了A的方法，那么D调用该方法时，使用B的实现还是C的实现？同时还会导致状态字段重复。

接口完美解决了这个问题：接口只定义方法契约，不包含字段和具体实现，因此没有状态冗余和实现歧义。Java允许一个类实现多个接口，实现了“类型的多继承”，规避了实现多继承的问题。

#### 6.6.2 继承 vs 接口
| 继承（extends） | 接口（implements） |
| :--- | :--- |
| 是“is-a”关系，核心是代码复用 | 是“can-do”关系，核心是行为契约 |
| 只能单继承 | 可以多实现 |
| 父类提供默认实现 | 接口不提供实现（默认方法除外） |

最佳实践：用继承复用公共代码，用接口定义能力契约，两者结合