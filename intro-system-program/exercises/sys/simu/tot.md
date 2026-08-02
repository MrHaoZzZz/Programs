# ISP Final Exam - Paper 1

**Course:** INTRODUCTION TO SYSTEMS PROGRAMMING - A  
**Date:** Thursday, July 9, 2026  
**Total Points:** 100

---

## Exercise 1 (5 points)

Consider the following recursive function:

```java
static int mystery(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * mystery(n - 1);
    }
}
```

What does `mystery(4)` return?

a) It will return 1  
b) It will return 4  
c) It will return 24  
d) It will return 120  
e) It will produce a runtime error because of integer overflow  
f) It will never return because the recursion doesn't terminate

---

## Exercise 2 (6 points)

Consider the following recursive function:

```java
static int f(int n) {
    if (n == 0) {
        return 0;
    } else {
        int digit = n % 10;
        n = n / 10;
        return digit + f(n);
    }
}
```

What does `f(12345)` return?

a) It will return 1  
b) It will return 5  
c) It will return 15  
d) It will return 12345  
e) It will produce a runtime error because the local variable `digit` is used after the recursive call  
f) It will never return because `f(n)` calls `f(n/10)` and this enters an infinite loop

---

## Exercise 3 (8 points)

Complete the following recursive function that calculates the sum of digits of a positive integer using recursion.

**Precondition:** `n >= 0`

```java
static int sumOfDigits(int n) {
    // TODO: Complete this function
}
```

---

## Exercise 4 (8 points)

Complete the following recursive function that generates all binary strings of length n. For example, `allBinaryStrings(2)` should return a list containing `["00", "01", "10", "11"]`.

**Precondition:** `n >= 0`

```java
ArrayList<String> allBinaryStrings(int n) {
    ArrayList<String> result = new ArrayList<String>();
    if (n == 0) {
        result.add("");
    } else {
        // TODO: Complete this method
    }
    return result;
}
```

---

## Exercise 5 (6 points)

Consider the following class representing a node in a doubly-linked list:

```java
class Node {
    int element;
    Node next;
    Node prev;
}
```

Complete the following function `removeLast` that removes the last node from a linked list. The function receives a node which is part of a linked list (not necessarily the first node). You must first find the beginning of the list, then remove the last node.

```java
static void removeLast(Node p) {
    // TODO: Complete this function
}
```

---

## Exercise 6 (8 points)

Complete the `addAtBeginning` method of the linked list class. The method inserts a new node with element `x` at the beginning of the list.

```java
class List {
    private Node first;
    
    // TODO: Complete this method
    void addAtBeginning(int x) {
        // TODO: Implementation
    }
    
    private class Node {
        int element;
        Node next;
    }
}
```

---

## Exercise 7 (6 points)

Consider the following binary tree representation:

```java
class TreeNode<T> {
    T key;
    TreeNode<T> leftChild;
    TreeNode<T> rightChild;
}
```

Complete the following function `countNodes` that returns the number of nodes in the binary tree.

```java
static <T> int countNodes(TreeNode<T> root) {
    // TODO: Complete this function
}
```

---

## Exercise 8 (8 points)

Complete the following function `mirrorTree` that receives a binary tree and modifies it so that it becomes its mirror image (left and right subtrees are swapped at every node).

```java
static <T> void mirrorTree(TreeNode<T> root) {
    // TODO: Complete this function
}
```

---

## Exercise 9 (6 points)

Consider the following classes:

```java
class A {
    void print() {
        System.out.print("A");
    }
}

class B extends A {
    void print() {
        System.out.print("B");
    }
}

class C extends B {
    void print() {
        super.print();
        System.out.print("C");
    }
}
```

What will this code print when executed from the main method?

```java
A obj1 = new C();
B obj2 = new B();
obj1.print();
obj2.print();
```

a) It will print AA  
b) It will print ACB  
c) It will print BC  
d) It will print BAC  
e) It will print CBB  
f) It will not run because `obj1` is of type `A` which does not have a `print()` method

---

## Exercise 10 (6 points)

Consider the following classes:

```java
class Animal {
    void speak() {
        System.out.print("Animal");
    }
}

class Dog extends Animal {
    void speak() {
        System.out.print("Dog");
    }
}

class Cat extends Animal {
    void speak() {
        System.out.print("Cat");
    }
}
```

What will this code print?

```java
ArrayList<Animal> animals = new ArrayList<Animal>();
animals.add(new Dog());
animals.add(new Cat());
animals.add(new Animal());

for (Animal a : animals) {
    a.speak();
}
```

a) It will print AnimalAnimalAnimal  
b) It will print DogCatAnimal  
c) It will print DogCatDog  
d) It will print AnimalDogCat  
e) It will produce a runtime error  
f) It will not compile

---

## Exercise 11 (8 points)

Define a class `LoggingCounter` that extends `Counter`. The `increment()` method should behave exactly as in `Counter` but additionally print a message "Counter incremented" each time it is called.

```java
class Counter {
    protected int value;
    
    Counter() {
        this.value = 0;
    }
    
    void increment() {
        this.value++;
    }
    
    int getValue() {
        return this.value;
    }
}

// TODO: Define LoggingCounter class
```

---

## Exercise 12 (6 points)

Consider the following interface:

```java
interface Filter<T> {
    boolean accept(T element);
}
```

Define a class `PositiveFilter` that implements `Filter<Integer>` and accepts only positive integers.

```java
// TODO: Define PositiveFilter class
```

---

## Exercise 13 (8 points)

Complete the following function `filter` that receives a `Filter` and an `ArrayList`, and returns a new `ArrayList` containing only the elements that are accepted by the filter.

```java
static <T> ArrayList<T> filter(Filter<T> filter, ArrayList<T> list) {
    // TODO: Complete this function
}
```

---

## Exercise 14 (6 points)

Define a class `RangeIterator` that implements `Iterator<Integer>` and generates all integers from `start` (inclusive) to `end` (exclusive).

```java
// TODO: Define RangeIterator class
```

---

## Exercise 15 (5 points)

What is the purpose of buffering in input/output operations?

a) To compress data before writing to disk  
b) To reduce the number of system calls by reading/writing data in chunks  
c) To encrypt data for security  
d) To convert data between different encodings  
e) To automatically close files when the program ends  
f) To make files larger for better performance

---

## Exercise 16 (6 points)

Consider the following code for reading a file:

```java
try {
    FileInputStream fis = new FileInputStream("data.txt");
    int b = fis.read();
    fis.close();
} catch (IOException e) {
    System.out.println("Error reading file");
}
```

What is the problem with this code?

a) The file will not be closed if an exception occurs  
b) It should use `FileReader` instead of `FileInputStream`  
c) The `read()` method should be called in a loop  
d) The `catch` block should not print a message  
e) The file name must be enclosed in double quotes  
f) There is no problem; the code is correct

---

## Answer Key

**Exercise 1:** c) 24  
**Exercise 2:** c) 15  
**Exercise 3:** See solution below  
**Exercise 4:** See solution below  
**Exercise 5:** See solution below  
**Exercise 6:** See solution below  
**Exercise 7:** See solution below  
**Exercise 8:** See solution below  
**Exercise 9:** b) ACB  
**Exercise 10:** b) DogCatAnimal  
**Exercise 11:** See solution below  
**Exercise 12:** See solution below  
**Exercise 13:** See solution below  
**Exercise 14:** See solution below  
**Exercise 15:** b) To reduce the number of system calls by reading/writing data in chunks  
**Exercise 16:** a) The file will not be closed if an exception occurs

---

## Solutions for Code Exercises

### Exercise 3 - Solution
```java
static int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + sumOfDigits(n / 10);
    }
}
```

### Exercise 4 - Solution
```java
ArrayList<String> allBinaryStrings(int n) {
    ArrayList<String> result = new ArrayList<String>();
    if (n == 0) {
        result.add("");
    } else {
        ArrayList<String> rest = allBinaryStrings(n - 1);
        for (String s : rest) {
            result.add("0" + s);
            result.add("1" + s);
        }
    }
    return result;
}
```

### Exercise 5 - Solution
```java
static void removeLast(Node p) {
    // Find the first node
    while (p.prev != null) {
        p = p.prev;
    }
    // If list is empty
    if (p == null) return;
    // If only one node
    if (p.next == null) return;
    // Traverse to last node
    Node current = p;
    while (current.next != null) {
        current = current.next;
    }
    // Remove last node
    if (current.prev != null) {
        current.prev.next = null;
    }
}
```

### Exercise 6 - Solution
```java
void addAtBeginning(int x) {
    Node newNode = new Node();
    newNode.element = x;
    newNode.next = this.first;
    this.first = newNode;
}
```

### Exercise 7 - Solution
```java
static <T> int countNodes(TreeNode<T> root) {
    if (root == null) {
        return 0;
    } else {
        return 1 + countNodes(root.leftChild) + countNodes(root.rightChild);
    }
}
```

### Exercise 8 - Solution
```java
static <T> void mirrorTree(TreeNode<T> root) {
    if (root == null) {
        return;
    }
    // Swap children
    TreeNode<T> temp = root.leftChild;
    root.leftChild = root.rightChild;
    root.rightChild = temp;
    // Recurse on children
    mirrorTree(root.leftChild);
    mirrorTree(root.rightChild);
}
```

### Exercise 11 - Solution
```java
class LoggingCounter extends Counter {
    @Override
    void increment() {
        super.increment();
        System.out.println("Counter incremented");
    }
}
```

### Exercise 12 - Solution
```java
class PositiveFilter implements Filter<Integer> {
    @Override
    public boolean accept(Integer element) {
        return element > 0;
    }
}
```

### Exercise 13 - Solution
```java
static <T> ArrayList<T> filter(Filter<T> filter, ArrayList<T> list) {
    ArrayList<T> result = new ArrayList<T>();
    for (T element : list) {
        if (filter.accept(element)) {
            result.add(element);
        }
    }
    return result;
}
```

### Exercise 14 - Solution
```java
class RangeIterator implements Iterator<Integer> {
    private int current;
    private int end;
    
    RangeIterator(int start, int end) {
        this.current = start;
        this.end = end;
    }
    
    @Override
    public boolean hasNext() {
        return this.current < this.end;
    }
    
    @Override
    public Integer next() {
        return this.current++;
    }
}
```

---

# ISP Final Exam - Paper 2

**Course:** INTRODUCTION TO SYSTEMS PROGRAMMING - A  
**Date:** Thursday, July 9, 2026  
**Total Points:** 100

---

## Exercise 1 (5 points)

Consider the following recursive function:

```java
static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
```

What does `gcd(48, 18)` return?

a) It will return 2  
b) It will return 6  
c) It will return 12  
d) It will return 18  
e) It will produce a runtime error due to stack overflow  
f) It will never return because the recursion doesn't terminate

---

## Exercise 2 (6 points)

Consider the following recursive function:

```java
static int f(int n) {
    if (n <= 1) {
        return n;
    } else {
        return f(n - 1) + f(n - 2);
    }
}
```

What does `f(6)` return?

a) It will return 5  
b) It will return 8  
c) It will return 13  
d) It will return 21  
e) It will produce a runtime error because of stack overflow  
f) It will never return because the recursion doesn't terminate

---

## Exercise 3 (8 points)

Complete the following recursive function that calculates the power of a number: `x^n`. You may assume `n >= 0`.

```java
static int power(int x, int n) {
    // TODO: Complete this function
}
```

---

## Exercise 4 (8 points)

Complete the following recursive function that generates all substrings of a given string. For example, `allSubstrings("abc")` should return `["", "a", "b", "c", "ab", "ac", "bc", "abc"]`.

```java
ArrayList<String> allSubstrings(String s) {
    // TODO: Complete this function
}
```

---

## Exercise 5 (6 points)

Consider the following class representing a node in a singly-linked list:

```java
class Node {
    int element;
    Node next;
}
```

Complete the following function `findLast` that returns the last element in the linked list. The function receives a node which is part of a linked list (not necessarily the first node). You must first find the beginning of the list.

```java
static int findLast(Node p) {
    // TODO: Complete this function
}
```

---

## Exercise 6 (8 points)

Complete the `addAtIndex` method of the linked list class. The method inserts a new node with element `x` at the given position `i`. Positions range from 0 to `n` (inclusive), where `n` is the length of the list. You may assume `0 <= i <= n`.

```java
class List {
    private Node first;
    
    void addAtIndex(int i, int x) {
        // TODO: Complete this method
    }
    
    private class Node {
        int element;
        Node next;
    }
}
```

---

## Exercise 7 (6 points)

Consider the following binary tree representation:

```java
class TreeNode<T> {
    T key;
    TreeNode<T> leftChild;
    TreeNode<T> rightChild;
}
```

Complete the following function `treeHeight` that returns the height of the binary tree (the number of nodes on the longest path from root to leaf). An empty tree has height 0.

```java
static <T> int treeHeight(TreeNode<T> root) {
    // TODO: Complete this function
}
```

---

## Exercise 8 (8 points)

Complete the following function `collectLeaves` that returns an `ArrayList` containing all the leaf nodes (nodes with no children) in the binary tree.

```java
static <T> ArrayList<T> collectLeaves(TreeNode<T> root) {
    // TODO: Complete this function
}
```

---

## Exercise 9 (6 points)

Consider the following classes:

```java
class X {
    void method() {
        System.out.print("X");
    }
}

class Y extends X {
    void method() {
        System.out.print("Y");
        super.method();
    }
}

class Z extends Y {
    void method() {
        System.out.print("Z");
    }
}
```

What will this code print when executed from the main method?

```java
X obj1 = new Z();
Y obj2 = new Y();
obj1.method();
obj2.method();
```

a) It will print ZY  
b) It will print ZX  
c) It will print YXYX  
d) It will print ZYX  
e) It will print ZXY  
f) It will not run because `obj1` is of type `X` which does not have a `method()`

---

## Exercise 10 (6 points)

Consider the following classes:

```java
class Vehicle {
    void start() {
        System.out.print("Vehicle");
    }
}

class Car extends Vehicle {
    void start() {
        System.out.print("Car");
    }
}

class Bike extends Vehicle {
    void start() {
        System.out.print("Bike");
    }
}
```

What will this code print?

```java
Vehicle v1 = new Car();
Vehicle v2 = new Bike();
v1.start();
v2.start();
```

a) It will print VehicleVehicle  
b) It will print CarBike  
c) It will print VehicleBike  
d) It will print CarVehicle  
e) It will produce a runtime error  
f) It will not compile

---

## Exercise 11 (8 points)

Define a class `LimitedCounter` that extends `Counter`. The `increment()` method should only increment the counter up to a maximum value (specified in the constructor). If the counter is already at the maximum, `increment()` should have no effect.

```java
class Counter {
    protected int value;
    
    Counter() {
        this.value = 0;
    }
    
    void increment() {
        this.value++;
    }
    
    int getValue() {
        return this.value;
    }
}

// TODO: Define LimitedCounter class
```

---

## Exercise 12 (6 points)

Consider the following interface:

```java
interface Predicate<T> {
    boolean test(T element);
}
```

Define a class `EvenPredicate` that implements `Predicate<Integer>` and tests whether an integer is even.

```java
// TODO: Define EvenPredicate class
```

---

## Exercise 13 (8 points)

Complete the following function `allMatch` that receives a `Predicate` and an `ArrayList`, and returns `true` if all elements in the list satisfy the predicate, and `false` otherwise.

```java
static <T> boolean allMatch(Predicate<T> predicate, ArrayList<T> list) {
    // TODO: Complete this function
}
```

---

## Exercise 14 (6 points)

Define a class `FibonacciIterator` that implements `Iterator<Integer>` and generates the Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, ...

```java
// TODO: Define FibonacciIterator class
```

---

## Exercise 15 (5 points)

Which of the following is the correct way to handle resources properly in Java?

a) Using `try` block without `catch` or `finally`  
b) Using `try-with-resources` statement  
c) Using `Thread.sleep()` to wait for resources  
d) Using `System.gc()` to free resources  
e) Using `finalize()` method in the class  
f) Using `Runtime.getRuntime().freeMemory()`

---

## Exercise 16 (6 points)

Consider the following code that writes to a file:

```java
FileOutputStream fos = new FileOutputStream("output.txt");
fos.write(65);
fos.write(66);
fos.write(67);
fos.close();
```

What is the problem with this code?

a) The file name must be "output.dat"  
b) The `write()` method should receive a `String` parameter  
c) It should use `FileWriter` instead of `FileOutputStream`  
d) The code should handle `IOException` exceptions  
e) It should use `flush()` before `close()`  
f) There is no problem; the code is correct

---

## Answer Key

**Exercise 1:** b) 6  
**Exercise 2:** b) 8  
**Exercise 3:** See solution below  
**Exercise 4:** See solution below  
**Exercise 5:** See solution below  
**Exercise 6:** See solution below  
**Exercise 7:** See solution below  
**Exercise 8:** See solution below  
**Exercise 9:** d) ZYX  
**Exercise 10:** b) CarBike  
**Exercise 11:** See solution below  
**Exercise 12:** See solution below  
**Exercise 13:** See solution below  
**Exercise 14:** See solution below  
**Exercise 15:** b) Using `try-with-resources` statement  
**Exercise 16:** d) The code should handle `IOException` exceptions

---

## Solutions for Code Exercises

### Exercise 3 - Solution
```java
static int power(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * power(x, n - 1);
    }
}
```

### Exercise 4 - Solution
```java
ArrayList<String> allSubstrings(String s) {
    ArrayList<String> result = new ArrayList<String>();
    if (s.length() == 0) {
        result.add("");
    } else {
        // Get all substrings without first character
        ArrayList<String> rest = allSubstrings(s.substring(1));
        // Add all substrings from rest (not including first char)
        result.addAll(rest);
        // Add all substrings with first char
        for (String str : rest) {
            result.add(s.charAt(0) + str);
        }
    }
    return result;
}
```

### Exercise 5 - Solution
```java
static int findLast(Node p) {
    // Find the first node
    while (p.prev != null) {
        p = p.prev;
    }
    // Traverse to last node
    while (p.next != null) {
        p = p.next;
    }
    return p.element;
}
```

### Exercise 6 - Solution
```java
void addAtIndex(int i, int x) {
    Node newNode = new Node();
    newNode.element = x;
    
    if (i == 0) {
        newNode.next = this.first;
        this.first = newNode;
        return;
    }
    
    Node current = this.first;
    for (int pos = 0; pos < i - 1; pos++) {
        current = current.next;
    }
    newNode.next = current.next;
    current.next = newNode;
}
```

### Exercise 7 - Solution
```java
static <T> int treeHeight(TreeNode<T> root) {
    if (root == null) {
        return 0;
    } else {
        return 1 + Math.max(treeHeight(root.leftChild), treeHeight(root.rightChild));
    }
}
```

### Exercise 8 - Solution
```java
static <T> ArrayList<T> collectLeaves(TreeNode<T> root) {
    ArrayList<T> result = new ArrayList<T>();
    if (root == null) {
        return result;
    }
    if (root.leftChild == null && root.rightChild == null) {
        result.add(root.key);
    } else {
        result.addAll(collectLeaves(root.leftChild));
        result.addAll(collectLeaves(root.rightChild));
    }
    return result;
}
```

### Exercise 11 - Solution
```java
class LimitedCounter extends Counter {
    private int maxValue;
    
    LimitedCounter(int maxValue) {
        super();
        this.maxValue = maxValue;
    }
    
    @Override
    void increment() {
        if (this.value < this.maxValue) {
            super.increment();
        }
    }
}
```

### Exercise 12 - Solution
```java
class EvenPredicate implements Predicate<Integer> {
    @Override
    public boolean test(Integer element) {
        return element % 2 == 0;
    }
}
```

### Exercise 13 - Solution
```java
static <T> boolean allMatch(Predicate<T> predicate, ArrayList<T> list) {
    for (T element : list) {
        if (!predicate.test(element)) {
            return false;
        }
    }
    return true;
}
```

### Exercise 14 - Solution
```java
class FibonacciIterator implements Iterator<Integer> {
    private int prev;
    private int current;
    
    FibonacciIterator() {
        this.prev = 0;
        this.current = 1;
    }
    
    @Override
    public boolean hasNext() {
        return true; // Infinite stream
    }
    
    @Override
    public Integer next() {
        int result = this.prev;
        int next = this.prev + this.current;
        this.prev = this.current;
        this.current = next;
        return result;
    }
}
```