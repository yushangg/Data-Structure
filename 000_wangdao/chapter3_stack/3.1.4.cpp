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
