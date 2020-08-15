/*
每一次扫描入栈后，检查“I”和“O”的个数，如果后者的个数大于前者，error；
扫描完毕之后，比较两个总的个数，相等则满足
Q3
*/
bool Judge(char A[]) {
	int i = 0, n1 = 0, n2 = 0;
	while (A[i++] != '\0') {
		if (A[i] == 'I') {
			n1++;
		}
		else if (A[i] == 'O') {
			n2++;
			if (n2 > n1) return false;
		}
	}
	if (n1 == n2)
		return true;
	else
		return false;
}


/*
前半段的结点入栈后，和后半段的开始比较,一旦有不相等的结点便跳出循环
Q4
*/
typedef struct LNode {
	char data;
	struct LNode* next;
}LNode, * LinkList;

bool Judge(LinkList list, int n) {
	int i; // 因为i是作为全局变量的，所以定义在最开始
	char* s;
	s = (char*)malloc(sizeof(char) * (n / 2));
	LNode* p = list->next;
	for (i = 0; i < n / 2; i++) {	//n / 2向下取整
		*(s + i) = p->data;
		p = p->next;
	}
	i--;	//恢复最后的i值，s[i]是最后一个存储的，结点个数是i - 0 + 1
	/*当链表的结点个数是奇数个的时候，最中间的结点不参与比较*/
	if (n % 2 == 1)
		p = p->next;
	while (p != NULL && p->data == *(s + i)) {
		i--;
		p = p->next;
	}
	if (i == -1)
		return true;
	else
		return false;
}


/*

Q5
*/
#define maxsize 100
typedef struct stack {
	ElemType stack[maxsize];
	int top[2];		//两个栈顶指针
}stack;
stack s;

/*入栈操作*/
int push(int flag, int x) {
//flag = 1表示左边的s1栈， flag = 2表示右边的s2栈
	if (flag != 1 && flag != 2) {
		printf("栈的编号不对");
		return 0;
	}
	if (s.top[1] = s.top[0] + 1) {
		printf("栈已经满了");
		return 0;
	}
	if (flag == 1) {
		s.stack[++s.top[0]] = x;
		return true;
	}
	else if (flag == 2) {
		s.stack[--s.top[1]] = x;
		return true;
	}
}

/*退栈操作*/
ElemType pop(int flag) {
	if (flag != 1 && flag != 2) {
		printf("栈的编号不对");
		exit(0);
	}
	if (flag == 1) {
		if (s.top[0] == -1) {
			printf("栈空");
			return -1;
		}
		else
			return s.stack[s.top[0]--];
	}
	else if (flag == 2) {
		if (s.top[1] == maxsize) {
			printf("栈空");
			return -1;
		}
		else
			return s.stack[s.top[1]++];
	}
}