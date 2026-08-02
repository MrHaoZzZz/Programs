[题目传送门](https://www.luogu.com.cn/problem/P5740)
# 前言
上了大学之后，感觉暂时不用沉迷于算法竞赛了。现在写代码完全是本着学习新东西去的。学了好多以前没用过的STL。

看了这题之后，我第一时间想到的是类，因为每次看那种介绍类的文章都是用student来举例的。所以试着学习了一下类。

**注意：** 本文内容可能不适用于算法竞赛，仅供拓展学习。算法竞赛的各位同学还是直接用结构体比较好。
# 讲解
既然要用类来写，首先肯定要定义一个类。
```cpp
class Student
{
    //... ...
} ;//注意结尾要有分号
```
现在已经定义了一个类，接下来往里面定义关于这个类（学生）的变量:`name`、`chi`、`math`和`eng`，分别表示学生的名字、语文成绩、数学成绩和英语成绩。

既然抱着学习的心态，那就把这些变量放在`private`里面。
```cpp
class Student
{
    private :
      string name ;
      int chi , math , eng ;
} ;
```
好了，现在定义好了关于`Student`类的变量。因为这些变量是`private`类型的，我们无法直接访问这些变量，只能通过函数来访问这些变量。所以我们需要定义一些函数来访问这些变量。而且我们需要在main()函数中直接使用这些函数，所以这些函数必须得是`public`中的。接下来思考我们访问这些变量的目的，无非是赋值和读取它们的值。好了，我们可以开始继续写了。

我们先写用于赋值的函数。
```cpp
void setData( string na , int c , int m , int e )
{
    name = na ;
    chi = c ;
    math = m ;
    eng = e ;
}
```
好了，我们现在可以通`setData()`来给变量赋值了。那么我们需要对这些变量进行什么操作呢？让我们读一下题。
> 总分最高的学生就是最厉害的，请输出最厉害的学生各项信息（姓名、各科成绩）。

题目要求我们计算学生的总成绩来找出那个最厉害的学生。所以我们需要一个函数来计算学生的总成绩。
```cpp
int getTot()
{
    return chi + math + eng ;
}
```
好了，我们暂时可能只需要这些。这个时候，整个类的定义长这样。
```cpp
class Student
{
    private :
        string name ;
        int chi , math , eng ;
    public :
        void setData( string na , int c , int m , int e )
        {
            name = na ;
            chi = c ;
            math = m ;
            eng = e ;
        }
        int getTot()
        {
            return chi + math + eng ;
        }
} ;
```
现在开始写`main()`。
```cpp
int main()
{
    int n ;
    cin >> n ;
    Student stu[1005] ;//我们定义的类可以当作一种数据类型
    for ( int i = 0 ; i < n ; i ++ )
    {
        string na ;
        int c , m , e ;
        cin >> na >> c >> m >> e ;
        stu[i].setData( na , c , m , e ) ;//类似于结构体，只不过点后面是函数名
    }
    Student maxstu = stu[0] ;
    for ( int i = 1 ; i < n ; i ++ )
    {
        if ( stu[i].getTot > maxstu[i].getTot() )
        {
            maxstu = stu[i] ;//同类的对象之间可以直接用等于号赋值
        }
    }
    //... ...
    return 0 ;
}
```
OK，现在我们已经基本写完了，只需要输出我们的答案就行了。
```cpp
cout << maxstu.name << ' ' << maxstu.chi << ' ' << maxstu.math << maxstu.eng << endl ;
```
好了，补上输出，结束！开始编译。
```zsh
mr_haozi@Mr-HaoZis-MacBook-Air P5740 % g++ 1.cpp -o 1
1.cpp:54:20: error: 'name' is a private member of 'Student'
   54 |     cout << maxstu.name << ' ' << maxstu.chi << ' ' << maxstu.math << maxstu.eng << endl ;
      |                    ^
1.cpp:9:16: note: declared private here
    9 |         string name ;
      |                ^
1.cpp:54:42: error: 'chi' is a private member of 'Student'
   54 |     cout << maxstu.name << ' ' << maxstu.chi << ' ' << maxstu.math << maxstu.eng << endl ;
      |                                          ^
1.cpp:10:13: note: declared private here
   10 |         int chi , math , eng ;
      |             ^
1.cpp:54:63: error: 'math' is a private member of 'Student'
   54 |     cout << maxstu.name << ' ' << maxstu.chi << ' ' << maxstu.math << maxstu.eng << endl ;
      |                                                               ^
1.cpp:10:19: note: declared private here
   10 |         int chi , math , eng ;
      |                   ^
1.cpp:54:78: error: 'eng' is a private member of 'Student'
   54 |     cout << maxstu.name << ' ' << maxstu.chi << ' ' << maxstu.math << maxstu.eng << endl ;
      |                                                                              ^
1.cpp:10:26: note: declared private here
   10 |         int chi , math , eng ;
      |                          ^
4 errors generated.
```
发现报错了。明明一切都看起来没错，但是为什么会报错呢？让我们观察一下报错提示。
>`1.cpp:54:20: error: 'name' is a private member of 'Student'`

这是因为，一个类的`private`数据不能像结构体一样直接访问。我们必须要通过函数来访问。现在我们需要再在`public`里面补充一个用来输出的函数。
```cpp
string output()
{
    return name + " " + to_string( chi ) + " " + to_string( math ) + " " + to_string( eng ) ;
}
```
那么`main()`函数里面的输出就要这样子写。
```cpp
cout << maxstu.output() << endl ;
```
重新编译一下，顺利完成。
# AC代码
```cpp
#include <iostream>
#include <string>

using namespace std ;

class Student
{
    private :
        string name ;
        int chi , math , eng ;
    public :
        void setData( string na , int c , int m , int e )
        {
            name = na ;
            chi = c ;
            math = m ;
            eng = e ;
        }
        int getTot()
        {
            return chi + math + eng ;
        }
        string output()
        {
            return name + " " + to_string( chi ) + " " + to_string( math ) + " " + to_string( eng ) ;
        }
} ;

int main()
{
    int n ;
    Student stu[1005] ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        string na ;
        int c , m , e ;
        cin >> na >> c >> m >> e ;
        stu[i].setData( na , c , m , e ) ;
    }
    Student maxstu = stu[0] ;
    for ( int i = 1 ; i < n ; i ++ )
    {
        if ( stu[i].getTot() > maxstu.getTot() )
        {
            maxstu = stu[i] ;
        }
    }
    cout << maxstu.output() << endl ;
    return 0 ;
}
```
# 附言
因为我也是第一次学习类，所以可能有些错误或者不严谨的地方，请大家指正。