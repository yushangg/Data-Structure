#define maxsize 50
typedef struct {
	ElemType data[maxsieze];
	int front, rear;
}SqQueue;

/*
Q1
在循环队列中，设置tag变量，当进队的时候置tag为1，出队的时候置tag为0（
因为只有出队操作才可能导致队空，只有入队操作才可能导致队满）
初始的时候，置tag=0，front=rear=0

SqQueue Q;
队空情况：Q.front == Q.rear && Q.tag == 0
队满情况：Q.front == Q.rear && Q.tag == 1
进队操作：
		Q.data[Q.rear] = x;
		Q.rear = (Q.rear + 1) % maxsize;
		Q.tag = 1;
出队操作：
		x = Q.data[Q.front];
		Q.front = (Q.front + 1) % maxsize;
		Q.tag = 0;
*/
