## 一些定义

### **数据(Data)**
- 是客观事物的符号表示，在计算机科学中指输入到计算机中被计算机程序加工处理的符号的总称。
- 对计算机科学而言：数据的含义极其广泛，如一个数值，一句话，一篇文章，一幅图画，一段声音，一段视频等，都是数据。

### **数据元素(Data element)**
- 数据的基本单位，也即数据这个集合中的一个客体。也叫实体。
- 在计算机中通常被作为一个整体考虑。
- 例如：一个人，一次通讯，一场球赛，一场报告，一个梦...

### **数据项(Record)**
- 每一个数据元素可以只有一个数据项(field)
- 数据项有很多其它称呼，在不同数据结构中，有结点(node), 顶点(vertex)等称呼。
- 数据项是数据的不可分割的最小单位。
- 在数据库里，数据元素叫"元组",或"行"，数据项叫"记录"。
- 数据、数据元素、数据项是包含关系[数据[数据元素[数据项]]]。

### **数据对象(Data Object)**
- 性质相同的数据元素集合
- 是数据的一个子集，可以是有限的，也可以是无限的。

### **关系(Relation)**
- 数据元素之间的某种相关性
- 用尖括号表示有向关系<a,b>
- 用圆括号表示无向关系(a,b)

### **数据结构(Data Structure)**
- 是相互之间存在一种或多种特定关系的数据元素的集合。
- 数据元素之间的关系称为结构，因此数据结构是带“结构”的数据元素的集合。
- 形式化定义为一个二元组 Data_Structure = (D,R)
- D是数据元素的有限集，R是D上的关系的有限集, 每个关系都是从D到D的关系(映射)

### **数据的逻辑结构**
- 数据元素之间的相互关系，与数据的存储无关。
- 集合，线性结构，树形结构，图形结构...
- 例如下例是一个城市之间的线性结构:
```C
City = (D,R)
D = {Beijing,Shanghai,Wuhan,Xian,Nanjing}
R = {r}
r={<Beijing,Shanghai>,<Shanghai,Wuhan>,<Wuhan,Xian>,<Xian,Nanjing>}
```

### **数据的存储结构**
- 又称为物理结构
- 指数据及其逻辑结构在计算机中的表示
- 分为顺序存储结构与链式存储结构
- 其中链式存储结构
- 缺点：利用率较低，空间开销较大
- 优点：进行插入、删除等运算时不必移动结点，仅需修改结点值

### [例:单链表的数据结构]
```C
# define STACK_INIT_SIZE 100    //(默认)最大存储容量
# define STACKINCREMENT       //(默认)的增补空间
typedef struct Node{         //定义一个结构体Node,表示该结构体中每一个数据元素的"结构".
    ElemType  data;          //表示每个数据元素(也就是结点)中的数据部分(数据域)
    struct Node *next;       //表示每个数据元素(也就是结点)中的指针部分(指针域), 注意，这是一个指向另一个结点的指针
} LNode, * LinkList            //定义了两个结构体变量，LNode表示一个结点，*LinkList表示指向这类结点的一个指针
```
------------------
### [例：如何使用以上数据结构]
```C
void InitList_L(LinkList &L)   //参数是赋值一个叫L结构体，该结构体的类型是LinkList
{
		L=(LNode *)malloc(sizeof(LNode));  // 申请存放一个结点数据所需要的存储空间
		if(!L)   exit(1);             // 存储空间分配失败
        L->next=NULL;                // 存储空间分配成功，表头结点的指针域置空
}// InitList_L
```
### **数据运算**
- 施加于数据的操作，包括"存储"、"查找"、"插入"、"删除"、"修改"、"合并"、"排序"等

### **数据类型**
- C/C++中的概念
- 一组值的集合及定义与这个值集上的一组操作的总称
- 规定了该类型数据的取值范围和对这些数据所能采取的操作
- 例如：int a,b;

### **抽象数据类型ADT**
- 一个数学模型及定义在该模型上的一组操作
- 仅取决于它的一组逻辑特性，即数学特性
- 与存储结构无关
- 例如：对一个线性表，有如下ADT定义
```C
ADT List
{
    Data:           //数据元素之间的逻辑关系
    Operation:      //数据元素的基本操作
        InitList(&L)
        CreateList(&L)
        ListEmpty(L)
        ListLength(L)
        LocateElem(L,e)
        PriorElem(L,cur_e,&pre_e)
        NextElem(L,cur_e,&pre_e)
        ListInsert(&L,i,e)
        ListDelete(&L,i,&e)
        GetElem(L,i,&e)
        ListTraverse(L)
        DestroyList(&L)
    }//ADT List
```
------------------
### 算法(Algorithm)
- 是对特定问题求解的一种描述，是指令的有限序列，其中每一条指令表示一个或多个操作。
- 具有有穷性，确定性，可行性，输入和输出五个必要的特征。

### 数据结构与算法的关系
- 算法依赖于数据结构
- 数据结构影响算的选择和实现效率

------------------
## 从C到C++
- 头文件.h 中，通常包含数据结构与ADT的定义
- 源文件.cpp 中，通常包含对具体数据结构的使用操作


## #include "stdio.h"
- c语言标准输入输出流。该文件包含printf()等函数

## #include "stdlib.h"   
- c语言标准库。该文件包含malloc()、realloc()和free()等函数.malloc()分配内存、realloc()动态内存调整、free()释放内存

## #include<iostream>
- c++标准输入输出流，用了这个，就可以用cout和cin了
```c++
int a;
cin>>a;
cout<<"a = "<<a<<endl;
cout<<hello world<<endl;
```

## #include<iomanip>
- c++输入输出流控制文件，该文件包含cout,cin及setw()等函数，用了这个就不用iostream。setw()用来控制输出的间隔，在输出的时候分配了n个字符的输出宽度，默认 n个字符宽度中右对齐输出

### include "SqList.h"     
- 自定义的头文件，包括对自定义的数据结构的操作定义及操作。这是顺序表的头文件。

### 函数(分为)
```C++
int add (int x, const int y, const int &z)    //值参数，常值参数，常值引用参数, 返回值
{
   return x+y+z;
}

void main  //返回值为空
{  int t=6;
   add(4,5,t);
}
```
### 重载
```c++
#include<iostream>                 // 该文件包含标准输入输出流cout和cin
int max(int a,int b)                    // 函数1
{
    return(a>b?a:b);
}
float max(float a,float b,float c)       // 函数2
{
    float t=a;
    if(t<b) t=b;
    if(t<c) t=c;
    return t;
}

void main( )
{
    cout<<"max(2,3)="<<max(2,3)<<endl;
    cout<<"max(2.3,5.6,3.1)="<<max(2.3,5.6,3.1)<<endl;
}
```
### 类
```c++
#include<stdio.h>
public class student        //定义类
{
   private:      //表示以下为私有成员
   int num;
   char name[10];
   char sex;
   public:       //表示以下为公有成员
   student() //构造函数
   {
       num =10010;
       strcyp(name,"wanglin");
       sex = 'F';
   }
   ~student()//析构函数
   {}

   void display()       //定义函数
   {
      cout<<"num:"<<num<<endl;
      cout<<"name:"<<name<<endl;
      cout<<"sex:"<<sex<<endl;
   }
}
```
### 类的访问权限
```c++
private: 私有 -- 例如你的卧室，只有你能用
protected: 保护  --例如你家的厨房，你可以用，你家人（派生类）也可以用
public: 公有  --例如你家的客厅，所有人都可以用

```
### 继承与派生
```c++
class underg_student: public student   // 前面的子类由后面的派生类继承而来

```

### 变量的引用类型
```c++
#include<stdio.h>
void swap(int &p1,int &p2)  
{  
    int temp;
    temp=p1;
    p1=p2;
    p2=temp;}

void main( )
{
    int a=5,b=9;
    if(a<b) swap(a,b);
    printf("\na=%d,b=%d\n",a,b);
}
`````````
