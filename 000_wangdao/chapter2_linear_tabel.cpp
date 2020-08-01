//P19
//definition of sequence table
typedef struct{
	int *data;
	int length;
	int maxSize;
}SqList;

//Q1
int deleteMin(SqList& L) {
	//the Sqlist is empty or only has one elements
	if (L.lenght == 0 || L.length == 1) {
		return 0;
	}
	//length >= 2
	int i, min = 0;
	for (i = 1; i < L.length; i++) {
		if (L.data[i] <= L.data[min]) {
			min = i;
		}
	}
	int target = L.data[min];
	L.data[min] = L.data[L.length - 1];
	length--;
	return target;
}


//Q2
void exchange(SqList& L) {
	int i = 0, j = L.length - 1, temp;
	while (i <= j) {
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
		i++;
		j--;
	}
}

	//answer
void reverse(SqList& L) {
	for (int i = 0; i < L.length / 2; i++) {
		Elemtype temp;
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
}

//Q3
//a bit tedious
void Delete(SqList &L, int x){
	int i = 0, j = L.length - 1;
	while (i <= j) {
		if (L.data[i] == x && L.data[j] != x) {
			L.data[i] = L.data[j];
			i++;
			j--;
			L.length -= 1;
		}
		else if (L.data[i] == x && L.data[j] == x) {
			j--;
			L.length--;
		}
		else if (L.data[i] != x && L.data[j] == x) {
			i++;
			j--;
			L.length--;
		}
		else {
			i++;
		}
	}
}

	//answer 3:
void delX(SqList& L, Elemtype x) {
	int k = 0;		//number != x
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

void delX2(SqList& L, Elemtype x) {
	int k = 0;		//numbers == x
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == x) {
			k++;
		}
		else {
			L[i - k] = L[i];
		}
	}
	L.length -= k;
}

//Q4
bool Delete(SqList& L, int s, int t) {
	if (s >= t || L.length == 0) {
		return false;
	}
	//common occasions, assume the ascending
	int i = 0, j = L.length - 1;
	while (L.data[i] < s && i < L.length) {
		i++;
	}
	while (L.data[j] > t && j >= 0) {
		j--;
	}
	for (int k = 0; k < j - i + 1; k++) {
		L.data[i] = L.data[i + j - i + 1];
	}
	L.length -= j - i + 1;
	/*
	the above lines can also as belows
	for (	; j < L.length - 1; i++,j++) {
		L.data[i] = L.data[j + 1];
	}
	L.length = i;
	*/
	return true;
}

//Q5 
//delete ith element from list
bool listDelete(SqList& L, int i) {
	if (i < 1 || i > L.length) {
		return false;
	}
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

bool listDeleteBetween(SqList& L, int s, int t) {
	if (s >= t || L.length == 0) {
		return false;
	}
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] >= s && L.data[i] <= t) {
			listDelete(L, i + 1);
		}
	}
	return true;
}

	//answer 5:
void deleteBetween(SqList& L, Elemtype s, Elemtype t) {
	int k = 0;		//numbers of x(x > t || x < s)
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] > t || L.data[i] < s) {
			L.data[k] = L.data[i];
			k++;
		}
	}
}

void deleteBetween2(SqList& L, Elemtype s, Elemtype t) {
	int k = 0;		// numbers [s, t]
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] >= s && L.data[i] <= t) {
			k++;
		}
		else {
			L.data[i - k] = L.data[i];
		}
	}
	L.length -= k;
}

//Q6
//delete ith element from list, don not consider about error , delete repeating n elements from ith to  i + n th
void deleteList(SqList& L, int i, int n) {
	for (int j = 0; j < n; j++) {
		L.data[i - 1 + j] = L.data[i + j];
	}
	L.length -= n;
}

//consider moving n elements in one operation failed
void deleteRepeated(SqList& L) {
	int count = 0;
	for (int i = 0; i < L.length - 1; i++) {
		if (L.data[i] == L.data[i + 1]) {
			count++;
		}
		else {
			deleteList(L, i - count + 1, count);
			L.length = -count;
			count = 0;
		}
	}
}

	//answer 6:
bool deleleSame(SqList& L) {
	if (L.length == 0) {
		return false;
	}
	for (int i = 0, int j = 1; j < L.length; j++) {		//methon of insert sorting 
		if (L.data[i] != L.data[j]) {
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1;
	return true;
}

	//for unsorted list
bool deleteSameUnsorted(SqList& L) {
	if (L.length == 0) {
		return false;
	}
	int a[max] = {0};		//max >= max(L.data[i])
	int j = 0;
	for (int i = 0; i < L.length; i++) {
		if (a[L.data[i]]== 0) {
			a[L.data[i]]++;
			L.data[j++] = L.data[i];
		}
	}
	L.length = j;
}
//Q7
//asumming as the ascending
bool merge(SqList L1, SqList L2, SqList &L) {
	if (L1.length + L2.length > L.maxSize) {
		return false;
	}
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] <= L2.data[j]) {
			L.data[k] = L1.data[i];
			k++;
			i++;
		}
		else {
			L.data[k++] = L2.data[j++];
		}
	}
	while (i < L1.length) {
		L.data[k++] = L1.data[i++];
	}
	while (j < L2.length) {
		L.data[k++] = L2.data[j++];
	}
	L.length = k;
	return true;
}

//Q8
//reverse three times
void reverse(Elemtype A[], int left, int right, int arraySize) {
	// left, right is the array subscript; arraySize is the length of array
	if (left >= right || right >= arraySize) {
		reutrn;
	}
	for (int i = left; i < (right + left) / 2; i++) {
		Elemtype temp = A[i];
		A[i] = A[right - i];
		A[right - i] = temp;
	}
}

void reverse2(Elemtype A[], int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left, j = right;
	while (i < j) {
		Elemtype temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i++;
		j--;
	}
}

void exchage(Elemtype A[], int m, int n, int arraySize) {
	reverse(A, 0, m + n - 1, arraySize);
	reverse(A, 0, n - 1, arraySize);
	reverse(A, n, m + n - 1, arraySize);
}

//Q9
void find(Elemtype A[], Elemtype x, int& low, int& high, int &mid) {
	while (low <= high) {
		mid = (low + high) / 2;
		if (A[mid] == x) {
			break;
		}
		else if (A[mid] < x) {
			low = mid + 1;
		}
		else if (A[mid] > x) {
			high = mid - 1;
		}
	}
}
void fucntion(Elemtype A[], Elemtype x) {
	int low = 0, high = n - 1, mid = (low + high) / 2;
	find(A, low, high, mid);
	if (A[mid] == x && mid != n - 1) {
		Elemtype temp = A[mid];
		A[mid] = A[mid + 1];
		A[mid + 1] = temp;
	}
	// can not find x in array
	if (low > high) {
		for (int i = n - 1; i > high; i--) {
			A[i + 1] = A[i];
		}
		A[i + 1] = x;
	}
}

// Q10
void reverse(int A[], int from, int to) {
	if (from >= to) {
		return;
	}
	while (from <= to) {
		int temp = A[from];
		A[from] = A[to];
		A[to] = temp;
		from--;
		to++;
	}
}
void converse(int A[], int p) {
	reverse(A, 0, p - 1);
	reverse(A, p, n - 1);
	reverse(A, 0, n - 1);
}

//Q11
//time: O()
int mid(int A[], int B[]) {
	int[] C;
	int k = 0, i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (A[i] >= B[j]) {
			C[k++] = A[i++];
		}
		else {
			C[k++] = B[j++];
		}
		if (k == n) {
			return C[k - 1];
		}
	}
}

//Q12: first sort the array, then go on
int function(int A[]) {
	int k = 1, temp = 1, mid = A[0], sub = 0;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] == A[i + 1]) {
			sub = i;
			temp++;
		}
		if (temp > k) {
			mid = A[sub];
		}
	}
	if (temp > n / 2) {
		return mid;
	}
	else {
		return -1;
	}
}

//Q13
ing findMissMin(int A[], int n) {
	int i, *B;
	B = (int*)malloc(sizeof(int) * n);
	memset(B, 0, sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		if (A[i] > 0 && A[i] <= n) {
			B[A[i] - 1] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (B[i] == 0) break;
	}
	return i + 1;
}