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