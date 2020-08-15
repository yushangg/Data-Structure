/*
双向冒泡
Q2
*/
void BuddleSort(ElemType a[], int n) {
	int low = 0, high = n - 1;
	bool flag = true;	//这里的标识位感觉没有起到什么作用
	while (low < high && flag == true) {
		flag = false;
		for (i = low; i < high; i++) {	// i的上线是n - 2
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				flag = true;
			}
		}
		high--;
		for (i = high; i > low; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				flag = true;
			}
		}
		low++;
	}
}