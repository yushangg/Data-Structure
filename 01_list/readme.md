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
#### 顺序表动态存储数据结构
```C
[in SqList.h]
# define LISTINCREMENT  10          //(默认)增补空间量
typedef struct {
    ElemType  *elem;           // 存储数据元素的一维数组
    int length;                // 线性表的当前长度
    int listsize;              // 当前分配的数组容量（以ElemType为单位）
    int incrementsize;        // 增补空间量（以ElemType为单位）
} SqList;
```
-----------------------------

#### 顺序表初始化操作
```C
[in SqList.h]
void InitList_Sq( SqList &L, int maxsize=LIST_INIT_SIZE, int incresize=LISTINCREMENT ) // 构造一个最大容量为maxsize的顺序表 L
{      
     L.elem=(ElemType *)malloc(maxsize*sizeof(ElemType)); // 分配一个最大容量为maxsize的数组空间
     if(!L.elem)  exit(1);           // 存储分配失败
      L.length=0;                    // 顺序表中当前所含元素个数为 0
      L.listsize=maxsize;            // 该顺序表可以容纳maxsize个数据元素
      L.incrementsize=incresize;     // 需要时可扩容incresize个元素空间
}// InitList_Sq
```
-----------------------------
#### 顺序表求表长操作
```C
[in SqList.h]
int ListLength_Sq(SqList L)
{
    return L.length;
}// ListLength_Sq
```
-----------------------------
#### 判断顺序表是否为空
```C
[in SqList.h]
bool ListEmpty_Sq(SqList L)
{
    if(L.length==0)
    return true;
    else return false;
}
```
-----------------------------
#### 顺序表定位元素(返回与e值相等的元素下标)
```C
[in SqList.h]
int LocateElem_Sq( SqList L, ElemType e)
{  
    for(int i=0;i<L. length;i++)
    if(L.elem[i]==e)  return i;   // 找到满足判定的数据元素为第 i 个元素
    return -1;                     // 该线性表中不存在满足判定的数据元素
 }//LocateElem_Sq
```
-----------------------------
#### 顺序表前插
在顺序表L的第i个元素之**前**插入新的元素e，若表中当前容量不足，则按预定义的增量扩容
```C
[in SqList.h]
bool ListInsert_Sq(SqList &L, int i, ElemType e)
{   
    int j;
        if(i<0||i>L.length)  return false;  // i值不合法
        if(L.length>=L.listsize)           // 当前存储空间已满，增补空间
        {                   
            L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
            if(!L.elem) exit(1);                   // 存储分配失败
            L.listsize+=L.incrementsize;           // 当前存储容量增加
        }
    for(j=L.length;j>i;j--)                // 被插入元素之后的元素左移
        L.elem[j]=L.elem[j-1];             

    L.elem[i]=e;                           // 插入元素e
    L.length++;                            // 表长增1
    return true;   
}// ListInsert_Sq
```
-----------------------------
#### 顺序表后插
在顺序表L的第i个元素之**后**插入新的元素e，若表中当前容量不足，则按预定义的增量扩容
```C
[in SqList.h]
bool ListInsert_Sq(SqList &L, int i, ElemType e)
{   
    int j;
        if(i<0||i>L.length)  return false;  // i值不合法
        if(L.length>=L.listsize)           // 当前存储空间已满，增补空间
        {                   
            L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
            if(!L.elem) exit(1);                   // 存储分配失败
            L.listsize+=L.incrementsize;           // 当前存储容量增加
        }
    int target=i+1;
    for(j=L.length;j>target;j--)                // 被插入元素之后的元素左移
        L.elem[j]=L.elem[j-1];             
        
    L.elem[target]=e;                           // 插入元素e
    L.length++;                            // 表长增1
    return true;   
}// ListInsert_Sq
```
-----------------------------

#### 顺序表尾插
在顺序表L的最后一个元素之**后**插入新的元素e，若表中当前容量不足，则按预定义的增量扩容
```C
[in SqList.h]
bool ListInsert_Sq(SqList &L, int i, ElemType e)
{   
    int j;
        if(i<0||i>L.length)  return false;  // i值不合法
        if(L.length>=L.listsize)           // 当前存储空间已满，增补空间
        {                   
            L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
            if(!L.elem) exit(1);                   // 存储分配失败
            L.listsize+=L.incrementsize;           // 当前存储容量增加
        }           
    L.elem[L.length]=e;                           // 插入元素e
    L.length++;                            // 表长增1
    return true;   
}// ListInsert_Sq
```

-----------------------------

#### 顺序表查插
在递增有序顺序表L中查找插入新的元素e，首先需要找到在哪插
```C
[in SqList.h]
bool ListInsert_Sq_1(SqList &L, ElemType e)
{   
// 若表中当前容量不足，则按预定义的增量扩容
      int i,j;
      if(L.length>=L.listsize)  {          // 当前存储空间已满，增补空间
          L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
          if(!L.elem) exit(1);                   // 存储分配失败
          L.listsize+=L.incrementsize;           // 当前存储容量增加
        }
      for(i=0;i<L.length&&e>L.elem[i];i++); //让下标移动到应该插入的位置之前
	  for(j=L.length;j>i;j--)                // 被插入元素之后的元素左移
        L.elem[j]=L.elem[j-1];
      L.elem[i]=e;                           // 插入元素e
      L.length++;                            // 表长增1
      return true;   
}// ListInsert_Sq
```