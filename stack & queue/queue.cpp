
//first in first out
int queue[maxSize];
int front = 0, rear = 0;
//In
queue[++rear] = x;
//out
x = queue[++front];

//circular queue
//In 
rear = (rear + 1) % maxSize;
queue[rear] = x;
//out
front = (front +  1) % maxSize;
x = queue[front];


//deque 
