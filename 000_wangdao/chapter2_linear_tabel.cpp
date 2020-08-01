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
bool merge(SqList& L1, SqList& L2, SqList &L) {
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