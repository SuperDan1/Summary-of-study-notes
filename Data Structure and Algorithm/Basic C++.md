# 第1章 C++回顾
[TOC]
## 函数与参数
* 传值函数
    * a、b、c是函数的**形参**（formal parameter）
    * 2、x、y是对应的**实参**（actual parameter）
    * 函数执行前，把实参复制给形参，复制过程是由形参类型的**复制构造函数**（copy parameter）完成；若实参和形参的类型不同，进行**类型转换**
    * 函数结束时，形参类型的**析构函数**（destructor）负责**释放**形式参数

```C++
int abc(int  a, int  b, int  c)
{
    return a + b * c;
}

int main()
{
    z = abc(2,  x,  y);
    return 0;
}
```

* **模板函数**：一段通用代码，**参数类型**是一个**变量**，值由编译器来确定——通过这种方式，int、float、double等不同类型变量的同一功能可以用一段代码实现
    * **TODO**：优势

```C++
template<class T>
T abc(T  a, T  b, T  c)
{
    return a + b * c; 
}
```

* **引用参数**
    * **形参**会**增加**程序的**运行时间**
        * 函数调用时，类型T的复制构造函数便把相应地实参分别复制给形参a、b、c
        * 函数返回时，类型T的析构函数被启用，以释放形式参数
    * 使用引用参数，函数调用时，不会复制实参的值，而是用引用参数x、y、z**代替**a、b、c，所以函数返回时也不会调用析构函数
    * **TODO**：作用
    
```C++
template<class T>
T abc(T&  a, T&  b, T&  c)
{
    return a + b * c; 
}
```

* **常量引用参数**（const parameter）：指明的引用参数不能被函数修改
    * 关键字const指明函数不可修改的引用参数，函数头告诉用户改函数不会修改实参
    * **TODO**：作用
    
```C++
template<class T>
T abc(const T&  a,  const T&  b,  const T&  c)
{
    return a + b * c; 
}
```

* 返回值：函数可以返回一个值、一个引用或一个常量引用
    * 返回一个值：返回的对象被**复制**到**调用环境**中；因为函数计算的表达式结果被存储在一个局部的临时变量中，当函数结束时，临时变量（局部变量和传值参数）所占用的空间将被释放
    * 引用返回：返回的是类型T的一个引用` T& mystery(int i, T& z)`
   ` return z`返回引用
   
    * const型引用`const T& mystery(int i, T& z)`
    ` return z`返回常量引用

* **重载函数**：定义多个同名函数的机制
    * 一个函数的**签名**（signature）由函数的**形参类型**及**形参个数**确定的；如第一个函数的签名是（int，int，int）
    * C++可以定义两个或更多的同名函数，但是任何两个同名的函数不能有同样的签名

## 异常
* 异常：表示程序出现错误的信息，例如：4/0
    * 异常类型：0除数、非法参数值、非法输入值、数组下标越界等
    * C++具有一个异常类的层次结构，**类exception**是**基类**
        * C++的动态内存分配操作符new，在得不到内存空间分配时，就抛出类型为bad_alloc的异常，bad_alloc是一种从基类exception派生的
        * 确定一个对象类型的C++函数typeid，在遇到NULL对象时，就会抛出类型为bad_typeid的异常，而bad_typeid是基类exception派生的

```C++
int abc(int a, int b, int c)
{
    if (a <= 0 || b <=0 || c <=0)
        throw "ALL parameters should be > 0";
   return a + b * c;
}
```

* 处理异常：一段代码抛出的异常由包含这段代码的**try块**来处理；紧跟try块之后的**catch块**
    * catch块的参数为要捕捉的异常的类型 `catch(char *e){ }`
        * `catch(bad_alloc e){ }` 表示捕捉的异常类型是bad_alloc
        * `catch(excpetion& e){ }` 捕捉的异常类型是**基类型exception以及所有从exception派生的类型**
        * `catch(...){}` **捕捉所有异常**，不管是什么类型

```C++
int main()
{
    try {cout << abc(2, 0, 4) << endl;}
    catch (char* e)
    {
        cout << "An exception has been thrown" << endl
        cout << e << endl;
        return 1;
    }
    return 0;
}
```

## 动态存储空间分配
* 操作符new：进行**动态分配**或运行时存储分配，**值**是一个**指针**，指向所分配空间
    * **声明**一个指针变量：`int *y`;
    * 当程序需要整数时，为这个整数动态**分配存储空间**：`y = new int;`
    * 在动态分配的空间**存储**一个整数值`*y = 10;`
    

 合并三个步骤

```C++
int *y = new int;
*y = 10;
```

或
```C++
int *y = new int(10);
```

或
```C++
int *y；
y = new int(10);
```

* 一维数组
    * 数组的大小在编译时可能还是未知的，随着函数调用的变化而变化，适合对数组进行动态存储分配
    * 在运行时创建一个一维浮点型数组x，必须把x**声明**为一个浮点型指针，然后为数组分配足够的空间`float *x = new float[n];`
    * 操作符new为n个浮点数分配了存储空间，并返回第一个浮点数空间的指针；访问数组元素`x[0]`、`x[1]`、`x[n-1]`

* 异常处理：计算机没有足够的内存可以分配，抛出一个类型为bad_alloc的异常

```C++
float *x;
try{x = new float [n];}
catch(bad_alloc e)
{
    // 仅当new失败时才会进入
    cerr << "Out of Memory" <<endl;
    exit(1);
}
```

* 操作符delete：动态分配的存储空间不再需要时可以用delete释放空间
    * 释放`*y` ：`delete y;`
    * 释放一维数组x：`delete []x;`

* 二维数组
    * 二维数组的两位大小在编译时是已知：`char c[7][5];`
    * 如果编译时有一维的大小是未知的，那么必须在运行时利用操作符new来创建，假设列数为5

```C++
char (*c) [5];
try{c = new char [n] [5];}
catch(bad_alloc)
{
    // 仅当new失败时才会进入
    cerr << "Out of Memory" <<endl;
    // 非正常运行导致退出程序
    exit(1);
}
```

* 创建二维数组：看做是由若干行所构成的结构，每一行都是用**new**创建的**一维数组**；**指向每一行的指针保存在另外一个一维数组之中**
    * x[0]、x[1]、x[2]分别指向第0行、第1行和第2行的首元素；`x[0:2]` 是指向字符的指针，x本身是一个**指向指针的指针**，`char **x;`
![2b3fa91e7e026de488c0cfc2159f2405.png](en-resource://database/1322:1)

```C++
template <class T>
bool make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{// 创建二维数组
    try{
            // 创建行指针
            x = new T *[numberOfRows];

            // 为每一行分配空间
            for (int i = 0;i < numberOfRows;i++)
            {
                x[i] = new T [numberOfColumns]
            }
            return true;
        }
    catch (bad_alloc){return false;}
}
```

释放二维数组空间

```C++
template <class T>
void delete2dArray(T ** &x, int numberOfRows)
{// 删除二维数组x
    
    // 删除行数组空间
    for (int i = 0; i < numberOfRows; i++)
        delete [] x[i];
    
    // 删除行指针
    delete [] x;
    x = NULL;
}
```

## 自有数据类型
* 类currency
    * 公有（public）部分所声明的是用来操作类对象（或实例）的成员函数（方法）；对类的用户是可见的，是用户与类对象进行交互的唯一手段
    * 私有（private）部分所声明的是用户不可见的数据成员（如简单变量、数组及其他可赋值的结构）和成员函数
    * 公有部分的第一个函数与类名相同，这种命称与类名相同的成员函数称为**构造函数**（constructor），用来指令创建类对象的方法，**没有返回值**；创建类对象时，构造函数被**自动调用**
    * ~类名的成员函数称为**析构函数**（destructor），每当类调用结束时，析构函数**自动调用**来**删除**这个对象

```C++
class currency
{
public:
// 构造函数
currency();
// 析构函数
~currency(){};
//函数
private:
// 成员函数
};
```

* 友元和保护性类成员
    * 对于一个类的**私有成员**，**仅有类的成员函数**才能**直接访问**
    * 定义类的**友元**（friend）可以**直接访问**该类的所有成员
        > class cuurency
        > {
        >         friend ....
        >         public:
        >     }
        
     * **保护性成员**（protected）类似于私有成员，但是**派生类**可以访问**基类的保护性成员**

* 文件currency.h包含了类的声明和实现细节，在文件头，应加上
> #ifdef Currency_
> #define Currency_

文件尾加上
> endif

包含在这组语句之内的代码只编译一次

## 异常类illegaParameterValue

## 递归函数（recursive function）
* 递归主要包含两部分
    * **基础部分** ：直接定义的，不用递归求解——递归停止条件
    * **递归部分**

* **例题**：输出n个不同元素的所有排列，公有$n!$种排列
    * 实例：a、b、c
    > 输出：abc、acb、bac、bca、cab、cba
    
```C++
template<class T>
void permutation(T list[], int k, int m)
{// 生成list[k:m]的所有排列
    if (k == m)
        cout << list[m];
    else
    for (int i = k; i <= m; i++)
    {
        swap(list[k], list[i]);
        permutation(list, k+1, m)
        swap(list[k], list[i]);
    }
}
```



## 标准模板库
* C++模板库（STL）是一个**容器**、**适配器**、**迭代器**、**函数对象**和**算法**的集合

## 测试与调试