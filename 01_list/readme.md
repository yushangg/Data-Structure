## 线性表(linear list，简称list)

### 定义
- 是**n(n≥0)**个**相同类型**的**数据元素**构成的**有限**序列。

#### 数学表示
- (a1，a2，…，an)
- 其中，n为线性表的长度，当n=0时，表示线性表是一个空表，即表中不包含任何元素。
- 对任意一对相邻元素<ai,ai+1>（1≤i<n），ai称为ai+1的**前驱**，ai+1称为ai的**后继**
-------------
#### 注意事项
- 线性表除第一个和最后一个元素之外，每一格数据元素只有一个前驱和一个后继
- 分有序线性表（顺序表）和无序线性表（链表），有序线性表的元素按照值的递增顺序排列；无序线性表在元素的值与位置之间没有特殊的联系
- 元素含义无所谓，可以指任何东西，但元素类型必须相同

------------------
#### 抽象数据类型ADT
```C
ADT List
{
    Data:
    Operation:
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
## 顺序表

#### 定义
- 顺序存储结构：用一组地址连续的存储单元依次存储**数据结构**(在这里是线性表)里各个元素，这种存储结构称为线性表的顺序存储结构。
- 顺序表：按照顺序存储结构存储的线性表。
-----------------------------
#### 数学表示
- 同线性表
- 求址
    - 每个元素占用k个存储单元，则<br>
    LOC(ai) =  LOC(a1) + (i-1)*k   (1≤i ≤n)<br>
    LOC(ai+1)= LOC(ai)+k       (1≤i ≤n)<br>

#### 注意事项
- 访问顺序表中任意元素的时间都相等，具有这一特点的存储结构称为**随机存取结构**。

#### 顺序表静态存储数据结构
```C
[in SqList.h]
# define LIST_INIT_SIZE 100    //(默认)最大存储容量
typedef struct {
    ElemType  elem [LIST_INIT_SIZE];   //存储数据元素的一维数组
    int length;                        //线性表的当前长度
} SqList;
```
