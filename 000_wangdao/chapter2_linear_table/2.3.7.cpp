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
	if (L->next == x) {
		p = L;
		L = L->next;
		free(p);
		deleteX(L, x);
	}
	else {
		deleteX(L->next, x);
	}
}