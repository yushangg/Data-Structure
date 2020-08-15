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
