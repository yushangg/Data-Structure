#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//tail interplotation 
void createLinkListR(LNode*& head) {
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	LNode* p = NULL, * r = head;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		p = (LNode*)malloc(sizeof(LNode));
		p->next = NULL;
		cin >> p->data;
		r->next = p;
		r = p;
	}
}

//first interplotation
void createLinkListH(LNode*& head) {
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	LNode* p = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		p = (LNode*)malloc(sizeof(LNode));
		p->next = NULL;
		cin >> p->data;
		p->next = head->next;
		head->next = p;
	}
}

//find and delete target node
void findDelete(LNode *head, int target) {
	LNode *r = head;
	while (r->next->data != target) {
		r = r->next;
	}
	r->next = r->next->next;
}

//merge two nodelist
void merge(LNode* a, LNode* b, LNode*& c) {
	LNode* p = a->next;
	LNode* q = b->next;
	LNode* r; //tail node
	c = a;
	c->next = NULL;
	free(b); 
	r = c; //use a node as the head node
	while (p != NULL && q != NULL) {		
		if (p->data <= q->data) {
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	if (p != NULL) {
		r->next = p;
	}
	if (q != NULL) {
		r->next = q;
	}
}

//divide the array into two parts: left <= comp , right > comp
void partition(int arr[], int n, int comp) {
	int i = 0, j = n - 1;
	int temp = arr[i];
	while (i < j) {
		while (i < j && arr[j] >= comp) {
			--j;
		}
		if (i < j) {
			arr[i] = arr[j];
			++i;
		}
		while (i < j && arr[i] < comp) {
			++i;
		}
		if (i < j) {
			arr[j] = arr[i];
			--j;
		}
	}
	arr[i] = temp;
}


void print(LNode* head) {
	while (head->next != NULL) {
		cout << head->next->data << " ";
		head = head->next;
	}
}

void print2(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
} 

int main() {
	LNode *a;
	createLinkListR(a);
	print(a);
	findDelete(a, 2);
	print(a);
	return 0;
//	int arr[] = {2, 1, -7, -3, 5, 6, -1};
//	partition(arr, 7, 1);
//	print2(arr, 7);
//	return 0;
	
}
