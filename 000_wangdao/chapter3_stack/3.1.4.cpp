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
ǰ��εĽ����ջ�󣬺ͺ��εĿ�ʼ�Ƚ�
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