#include<stdio.h>

int main() {
	int i = 5;
	do {
		switch (i % 2) {
		case 0:
			i--;
			break; //break����switch��䣬����ִ��switch����������
		case 1:
			i--;
			continue; // continue ֱ���������ε�ѭ����ֱ�ӽ���ѭ���������ж�
		}
		i -= 2;
		printf("i=%d", i);
	}while(i > 0)
}

//�������� ��i=1��

/*
while �� do while����������� �� do while ����ִ��һ��Ȼ���ٶ� while�е����������жϣ�
								 while ������Ҫ���ж�������Ȼ���ٽ���ѭ��

��forѭ���У�ִ��ѭ������Ҫ�ж�ѭ��������������ѭ�������Ż�ִ��ѭ���� 
*/ 