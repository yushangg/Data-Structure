#include<stdio.h>

int main() {
	int i = 5;
	do {
		switch (i % 2) {
		case 0:
			i--;
			break; //break跳出switch语句，继续执行switch语句后面的语句
		case 1:
			i--;
			continue; // continue 直接跳过本次的循环，直接进行循环条件的判断
		}
		i -= 2;
		printf("i=%d", i);
	}while(i > 0)
}

//输出结果是 “i=1”
