//definition of sequence table
typedef struct{
	int *data;
	int length;
	int maxSize;
}SqList;

//Q1
int Delete(SqList& L) {
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

//Q3
void Delete(SqList &L, int x){
	int i = 0, j = L.length - 1;
	while (i <= j) {
		if (L.data[i] == x && L.data[j] != x) {
			L.data[i] = L.data[j];
			j--;
			L.length -= 1;
		}
	}
}

//Q4
bool Delete(SqList& L, int s, int t) {
	if (s >= t || L.length == 0) {
		return false;
	}
	//common occasions, assume the ascending
	int i = 0, j = L.length - 1;
	while (L.data[i] < s) {
		i++;
	}
	while (L.data[j] > t) {
		j--;
	}
	for (int k = 0; k < L.length - j; k++) {
		L.data[i + k] = L.data[j + k];
	}
	L.length -= j - i + 1;
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

