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
	while (p->next != NULL) {
		if (p->next->data == min) {
			LNode* q = p;
			p = p->next->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}	
}

//Q5
void reverse(LinkList& L) {
	LNode* p = L->next;
	LNode* q;
	while (p->next != NULL) {
	}
}