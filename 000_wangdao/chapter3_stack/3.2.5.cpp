#define maxsize 50
typedef struct {
	ElemType data[maxsieze];
	int front, rear;
}SqQueue;

/*
Q1
��ѭ�������У�����tag�����������ӵ�ʱ����tagΪ1�����ӵ�ʱ����tagΪ0��
��Ϊֻ�г��Ӳ����ſ��ܵ��¶ӿգ�ֻ����Ӳ����ſ��ܵ��¶�����
��ʼ��ʱ����tag=0��front=rear=0

SqQueue Q;
�ӿ������Q.front == Q.rear && Q.tag == 0
���������Q.front == Q.rear && Q.tag == 1
���Ӳ�����
		Q.data[Q.rear] = x;
		Q.rear = (Q.rear + 1) % maxsize;
		Q.tag = 1;
���Ӳ�����
		x = Q.data[Q.front];
		Q.front = (Q.front + 1) % maxsize;
		Q.tag = 0;
*/
