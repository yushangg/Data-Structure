/*
ÿһ��ɨ����ջ�󣬼�顰I���͡�O���ĸ�����������ߵĸ�������ǰ�ߣ�error��
ɨ�����֮�󣬱Ƚ������ܵĸ��������������
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
ǰ��εĽ����ջ�󣬺ͺ��εĿ�ʼ�Ƚ�,һ���в���ȵĽ�������ѭ��
Q4
*/
typedef struct LNode {
	char data;
	struct LNode* next;
}LNode, * LinkList;

bool Judge(LinkList list, int n) {
	int i; // ��Ϊi����Ϊȫ�ֱ����ģ����Զ������ʼ
	char* s;
	s = (char*)malloc(sizeof(char) * (n / 2));
	LNode* p = list->next;
	for (i = 0; i < n / 2; i++) {	//n / 2����ȡ��
		*(s + i) = p->data;
		p = p->next;
	}
	i--;	//�ָ�����iֵ��s[i]�����һ���洢�ģ���������i - 0 + 1
	/*������Ľ���������������ʱ�����м�Ľ�㲻����Ƚ�*/
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
	int top[2];		//����ջ��ָ��
}stack;
stack s;

/*��ջ����*/
int push(int flag, int x) {
//flag = 1��ʾ��ߵ�s1ջ�� flag = 2��ʾ�ұߵ�s2ջ
	if (flag != 1 && flag != 2) {
		printf("ջ�ı�Ų���");
		return 0;
	}
	if (s.top[1] = s.top[0] + 1) {
		printf("ջ�Ѿ�����");
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

/*��ջ����*/
ElemType pop(int flag) {
	if (flag != 1 && flag != 2) {
		printf("ջ�ı�Ų���");
		exit(0);
	}
	if (flag == 1) {
		if (s.top[0] == -1) {
			printf("ջ��");
			return -1;
		}
		else
			return s.stack[s.top[0]--];
	}
	else if (flag == 2) {
		if (s.top[1] == maxsize) {
			printf("ջ��");
			return -1;
		}
		else
			return s.stack[s.top[1]++];
	}
}