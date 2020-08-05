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
		p->next = pre->next;   
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