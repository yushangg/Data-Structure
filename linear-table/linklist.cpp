#include <iostream>
#include <stdlib.h>
using namespace std;
/*
In this cpp, wo define a linked list with a head node.
When the linked list is null, head->next = null;
*/

//definition of structure of node 
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//tail interplotation; insert new node into the end of the linked list 
//use '*&' to make sure changes made in this function can be saved
void createLinkListR(LNode*& head) {
	//normally used to initialize the node space
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	//LNode* r used as a node to store new tail node(inserted one), LNode* p used as a temporary variable to save the old tail node 
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

//first interplotation; insert new node into the head of the linked list
//just like the above function, only one needed to take care, the head node always piints to the first node
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

//find and delete target node; in this simple function, target node default exists 
void findDelete(LNode *head, int target) {
	LNode *r = head;
	while (r->next->data != target) {
		r = r->next;
	}
	r->next = r->next->next;
}

//merge two linked lists(adcending order) into a adecendign order linked list; defalut with head node
//take care the symbol in front of the a, b, c 
void merge(LNode* a, LNode* b, LNode*& c) {
	LNode* p = a->next;
	LNode* q = b->next;
	LNode* r; //tail node
	c = a;
	c->next = NULL;
	//small trick, free the storage
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
	//concatenate left part of the linked list for save time
	if (p != NULL) {
		r->next = p;
	}
	if (q != NULL) {
		r->next = q;
	}
}

//---------------------------------still confused about this function   !!!!!!!!!!!!!!!!!!!!!!!!!!!!
//divide the array into two parts: left <= comp , right > comp
void partition(int arr[], int n, int comp) {
	int i = 0, j = n - 1;
	int temp = arr[i];
	while (i < j) {
		while (i < j && arr[j] > comp) {
			--j;
		}
		if (i < j) {
			arr[i] = arr[j];
			++i;
		}
		while (i < j && arr[i] <= comp) {
			++i;
		}
		if (i < j) {
			arr[j] = arr[i];
			--j;
		}
	}
	arr[i] = temp;
}

//used to print all values of linked list(default with head node)
void print(LNode* head) {
	while (head->next != NULL) {
		cout << head->next->data << " ";
		head = head->next;
	}
}

//used to print all values of array
void print2(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
} 

//used to test
int main() {
//	LNode *a;
//	createLinkListR(a);
//	print(a);
//	findDelete(a, 2);
//	print(a);
//	return 0;
//	int arr[] = {-2, 1, -7, -3, 5, 6, -1};
//	partition(arr, 7, 1);
//	print2(arr, 7);
	return 0;	
}
