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

/*
while 和 do while的最大区别是 ： do while 至少执行一次然后再对 while中的条件进行判断；
								 while 则是需要先判断条件，然后再进行循环

在for循环中，执行循环体需要判断循环条件，满足了循环条件才会执行循环体 

一般情况下，使用if...else 需要加上{}来区分代码块，但是有些情况下没有写{}，
那么就需要 “else与前面最近的且尚未配对的if配对”这个规则。 
*/ 
