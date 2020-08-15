// definition of linklist
typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode,*LinkList;

//Q1
void deleteX(LinkList& L, Elemtype x) {
	LNode* p;
	if (L == NULL) {
		return;
	}
	if (L->data == x) {
		p = L;
		L = L->next;
		free(p);
		deleteX(L, x);
	}
	else {
		deleteX(L->next, x);
	}
}

//Q2
void deleteX(LinkList& L, Elemtype x) {
	LNode* pre = L;
	LNode* p = L->next;
	LNode* q;
	while (p != NULL) {
		if (p->data == x) {
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else {
			pre = p;
			p = p->next;
		}//use pre to note pre LNode
	}
}

// tail insert
void deleteX_2(LinkList& L, Elemtype x) {
	LNode* q;
	LNode* r = L;
	LNode* p = L->next;
	while (p != NULL) {
		if (p->data == x) {
			q = p;
			p = p->next;
			free(q);
		}
		else {
			r->next = p;
			r = p;
			p = p->next;
		}
	}
}

//Q3
void reversePrint(LinkList& L) {
	if (L->next != NULL) {
		reversePrint(L->next);		// print the value of the latter node recursively
	}
	if (L != NULL) {
		print(L->data);
	}
}

//Q4
void deleteMin(LinkList& L) {
	if (L->next == NULL) {
		return;
	}
	LNode* p = L->next;
	Elemtype min = p->data;
	//find the min LNode
	while (p != NULL) {
		if (p->data < min) {
			min = p->data;
			p = p->next;
		}
	}
	//delete the target LNode
	p = L->next;
	LNode* pre = L;
	LNode* q;
	while (p->next != NULL) {
		if (p->data == min) {
			q = p;
			p = p->next;
			free(q);
		}
		else {
			pre = p;
			p = p->next;
		}
	}	
}

//answer
void DeleteMin(LinkList& L) {
	LNode* pre = L, * p = L->next;
	LNode* minpre = pre, * minp = p;		//use pre as the node before minLNode
	while (p != NULL) {
		if (p->data < pre->data) {
			minp = p;
			minpre = pre;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
	minpre->next = minp->next;
	free(minp);
}

//Q5
//consider using head insert 
void reverse(LinkList& L) {
	LNode* p, * r;
	p = L->next;
	L->next = NULL;
	//insert LNode p after the head LNode
	while (p != NULL) {
		r = p->next;		//restore LNode after p
		p->next = L->next;
		L->next = p;
		p = r;
	}
}

//a bit complicated, reverse the link
void Reverse(LinkList& L) {
	LNode* pre, * p = L->next, * r = p->next;
	p->next = NULL;
	while (r != NULL) {		//if r == NULL, then node p is the last node
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	L->next = p;
}

//Q6
void Sort(LinkList& L) {
	LNode* p = L->next, * pre;
	LNode* r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL) {
		r = p->next;		//use node r to store the node after p;
		pre = L;		//everytime compare from the head node
		while (pre->next != NULL && pre->next->data < p->data) {
			pre = pre->next;
		}
		p->next = pre->next;		//insert between pre node and "pre->next" node
		pre->next = p;
		p = r;
	}
}

//Q7
void Delete(LinkList& L, ElemType m, ElemType n) {
	LNode* pre = L, * p = L->next;
	while (p != NULL) {
		if (p->data > m && p->data < n) {
			LNode* q = p;
			pre->next = p->next;
			p = p->next;
			free(q);
		}
		else {
			pre = pre->next;
			p = p->next;
		}
	}
}

//Q8
/* 
two lists like a "Y", after the common node, every node is the same;
calulate the aba(len1 - len2), perform "longList = longList->next; "
then longList & shortList perform at the same time 
*/
int Length(LinkList L) {
	int res = 0;
	LNode* p = L->next;
	while (p != NULL) {
		res++;
		p = p->next;
	}
}

LinkNode* SearchFirstCommon(LinkList L2, LinkList L2) {
	int len1 = Length(L1), len2 = Length(L2);
	Linklist longList, shortList;
	int var;		// var = abs(len1 - len2)
	if (len1 >= len2) {
		longList = L1->next, shortList = L2->next;
		var = len1 - len2;
	}
	else {
		longList = L2->next, shortList = L1->next;
		var = len2 - len1;
	}
	for (int i = 0; i < var; i++) {
		longList = longList->next;
	}
	while (longList != NULL) {
		if (longList == shortList) {
			return longList;
		}
		else {
			longList = longList->next;
			shortList = shortList->next;
		}
	}
}

//Q9 
/*
consider using head insert function to build incremental list,
then print in new node order
*/

void Sort(LinkList& L) {		//like Q6
	LNode* p = L->next, * pre, * r;
	while (p != NULL) {
		r = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
void PrintIncrement(LinkList& L) {
	Sort(L);
	LNode* p = L->next;
	while (p != NULL) {
		q = p;
		print("%d ", p->data);
		p = p->next;
		free(q);
	}
}

/*
traverse the LinkList to find the min,
then print
*/
void Print(LinkList& L) {
	while (L->next != NULL) {
		LNode* minpre = L, * p = L->next;
		while (p->next != NULL) {
			if (p->next->data < minpre->next->data) {
				minpre = p;
			}
			p = p->next;
		}
		print(minpre->next->data);
		LNode* u = minpre->next;
		minpre->next = u->next;
		free(u);
	}
	free(L);
}


//Q10
void Segment(LinkList& A, LinkList& B) {
	LNode* p = A->next, *q, *r1 = A, *r2 = B;
	int i = 0;
	while (p != NULL) {
		if (i % 2 == 0) {
			r1->next = p;
			r1 = p;
		}
		else {
			r2->next = p;
			r2 = p;
		}
		i++;
		p = p->next;
	}
	r1->next = NULL;
	r2->next = NULL;
}

//Q11
void Segment(LinkList& L, LinkList& A, LinkList& B) {
	LNode* p = L->next, *ra = A;
	B->next = NULL;
	A->next = NULL
	while (p != NULL) {
		ra->next = p;
		ra = p;
		p = p->next;
		if (p != NULL) {
			q = p->next;
		}
		p->next = B->next;
		B->next = p;
		p = q;
	}
}

//Q12
void DeleteSame(LinkList& L) {
	LNode* p = L->next, * q;
	if (p == NULL) {
		return;
	}
	while (p->next != NULL) {
		q = p->next;
		if (p->data == q->data) {
			p->next = q->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}
}

//Q13
void  MergeList(LinkList& La, LinkList& Lb) {
	LNode* r, * pa = La->next, * pb = Lb->next;
	La->next = NULL:
	while (pa != NULL && pb != NULL) {
		if (pa->data <= pb->data) {
			r = pa->next;
			pa->next = La->next;
			La->next = pa;
			pa = r;
		}
		else {
			r = pb->next;
			pb->next = La->next;
			La->next = pb;
			pb = r;
		}
	}
	if (pa != NULL) {
		pb = pa;
	}
	while (pb != NULL) {
		r = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = r;
	}
	free(Lb);
}

//Q14
void GetCommon(LinkList& A, LinkList& B) {
	LNode* p = A->next, * q = B->next, * r, * s;
	LinkList C = (LinkList)malloc(sizeof(LNode));
	r = C;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			p = p->next;
		}
		else if (p->data > q->data) {
			q = q->next;
		}
		else {		//tail insert
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
	}
	r->next = NULL;
}

//Q15
LinkList Union(LinkList& La, LinkList& Lb) {
	LNode* pa = La->next, * pb = Lb->next, tmp;
	pc = La;
	while (pa != NULL && pb != NULL) {
		if (pa->data == pb->data) {
			pc->next = pa->data;
			pc = pa;
			pa = pa->next;
			tmp = pb;
			pb = pb->next;
			free(tmp);
		}
		else if (pa->data < pb->data) {
			tmp = pa;
			pa = pa->next;
			free(tmp);
		}
		else {
			tmp = pb;
			pb = pb->next;
			free(tmp);
		}
	}
	while (pa != NULL) {
		tmp = pa;
		pa = pa->next;
		free(tmp);
	}
	while (pb != NULL) {
		tmp = pb;
		pb = pb->next;
		free(tmp);
	}
	pc->next = NULL:
	free(Lb);
	return La;
}

//Q16 with head node
bool Pattern(LinkList& A, LinkList& B) {
	LNode* p = A->next, * q = B->next, * pre = p;
	while (p != NULL && q != NULL) {
		if (p->data != q->data) {
			pre = pre->next;
			p = pre;
			q = B->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
		if (q == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
}

//Q17
/*
设置两个工作指针，一个从左向右扫描，一个从右向左扫描，
直到这两个指针相遇(奇数个结点是指向同一个结点，偶数个结点是
p->next = q or q->prior = p)
*/
int Symmetry(LlinkList L) {
	LNode* p = L->next, * q = L->prior;
	while (p != q && q->next != p) {	//while循环里面的第二个条件，斟酌一下
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else {
			return 0;
		}
	}
	return 1;
}

/*
Q18
找到第一个链表的最后一个结点，然后将结点的后继变成第二个链表的第一个结点;
将第二个链表的最后一个结点指向第一个链表的头结点
*/
void Merge(LinkList& h1, LinkList& h2) {
	LNode* p = h1->next, * q = h2->next;
	while (p->next != h1) {
		p = p->next;
	}
	//当前p的后继是h1，p是尾结点
	p->next = q;
	while (q->next != h2) {
		q = q->next;
	}
	q->next = h1;
}

/*
Q19
对于循环单链表，在不空的时候进行循环，每一次循环都找到一个最小的结点并删除它
*/
void DeleteAllNode(LinkList& L) {
	//p, pre 是工作指针， minp 和  minpre作为中继的记录
	LNode* p, * pre, * minp, * minpre;
	while (L->next != L) {
		p = L->next;
		pre = L;
		minp = p;
		minpre = pre;
		while (p != L) {
			if (p->data < minp->data) {
				minp = p;
				minpre = pre;
			}
			pre = p;
			p = p->next;
		}
		//输出后将最小元素结点断开，并释放空间
		printf("%d", minp->data);
		minpre->next = minp->next;
		free(minp);
	}
	free(L);
}

/*
Q20

*/
DLinkList Locate(DLinkList& L, ElemType x) {
	DNode* p = L->next, * q;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	//跳出循环有两种情况。 1.没有找到x，来到了链表结尾； 2.找到了x
	if (p == NULL) {
		printf("ERROR");
		exit(0);
	}
	//找到了x元素，需要将结点访问频度+1， 并且移动到合适位置
	else {
		p->freq++;
		if (p->next != NULL) {
			p->next->pred = p->pred;
		}
		q = p->pred;
		//通过移动指针，最后p该移动q指向的结点后面
		while (q != NULL && q->freq <= p->freq) {
			q = q->pred;
		}
		//一个环
		p->next = q->next;
		q->next->pred = p;
		p->pred = q;
		q->next = p;
	}
	return p;
}

/*
使用两个工作指针，p和q，开始都指向第一个结点。p开始移动，q不动；
当p移动到了第k个结点时，p、q同时开始移动。
当p移动到了最后一个结点的时候，q的位置就是倒数第k个结点的位置
Q21
*/
typedef struct LNode {
	int data;
	struct LNode* link;
}LNode, * LinkList;

int Search(LinkList list, int k) {
	LNode* p = list->link, * q = list->link;
	int count = 0;
	while (p != NULL) {
		if (count < k) {
			p = p->link;
			count++;
		}
		else {
			p = p->link;
			q = q->link;
		}
		if (count < k) { // 链表自身的长度不够
			return 0;
		}
		else {
			printf("%d", q->data);
			return 1;
		}
	}
}


/*
求出两个链表的长度len1 和 len2，两者相减得到多出来的结点，
从这个结点之后开始同步向后，直到data域相同
Q22
*/
typedef struct LNode {
	char data;
	struct LNode* next;
}LNode, * LinkList;

/*求链表的长度*/
int Length(Linklist list) {
	int len = 0;
	while (list->next != NULL) {
		len++;
		list = list->next;
	}
}

/*找到共同后缀的起始地址*/
LNode* FindAddress(LinkList str1, LinkList str2) {
	int len1 = Length(str1), len2 = Length(str2);
	LNode* p = str1->next. * q = str2->next;
	while (len1 > len2) {
		p = p->next;
		len1--;
	}
	while (len1 < len2) {
		q = q->next;
		len2--;
	}
	while (p != NULL && q != NULL && p->next != q->next) {
		p = p->next;
		q = q->next;
	}
	return p->next;
}


/*
使用空间换时间的思想，利用一个辅助数组记录链表中已经出现的数值
Q23
*/
typedef struct LNode {
	int data;
	struct LNode* link;
}LNode, * LinkList;

void func(Linklist list, int n) {
	LNode* p = list->link, * temp;
	int* q;
	q = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		*(q + i) = 0;	//辅助数组初始化为0
	}
	while (p != NULL) {
		if (*(q + abs(p->data)) == 0) {
			p = p->link;
			*(q + abs(p->data) = 1;
		}
		else {
			temp = p->link;
			p->link = p->link->link;
			free(temp);
		}
	}
	free(q);
}

/*
设置快慢指针fast， low ，因为fast快于slow，所有当slow进入环之后，
fast不需要一周就可以追上slow。
设从头结点到入口的距离是a个结点，fast和slow相遇时候，距离入口是x个结点的长度
设环一圈是r个结点，fast和slow相遇的时候，fast已经在环里面n圈了
故 a + x = (a + x + n * r) / 2    ;  建立的依据是时间相同
---------> a = n * r - x
即可以设置两个指针，一个指向头节点，一个指向相遇点，同步移动，最后就会在入口点相遇
Q24
*/
LNode* FindLoopStart(LNode* head) {
	LNode* fast = head->next, * slow = head->next;
	while (fast->next != NULL && slow != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}
	if (slow == NULL || fast->next == NULL)
		return NULL;
	LNode* p1 = head, * p2 = slow;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}


/*
为了方便取得后半部分的元素，将后半段原地逆序
Q25
*/
typedef struct node {
	int data;
	struct node* next;
}NODE;
void ChangeList(NODE* head) {
	NODE* p = head->next, * q = head->next;
	while (q != NULL) {	//q比p快，q到达尾结点时，p是中间结点
		p = p->next;
		q = q->next;
		if (q->next != NULL)
			q = q->next;
	}
	q = p->next; //这一句之后，q是后半段的首个结点
	/*单链表原地逆序，使用头插法*/
	p->next = NULL; // 从空链表开始插入
	while (q != NULL) {
		NODE* tmp = q->next;
		q->next = p->next;
		p->next = q;
		q = tmp;
	}

	NODE* s = head->next;
	q = p->next;	//s和q分别指向前后两段的第一个数据结点
	while (q != NULL) {
		NODE* tmp = q->next;
		q->next = s->next;
		s->next = q;
		s = q->next;
		q = tmp;
	}
}
