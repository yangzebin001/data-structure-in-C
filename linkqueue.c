#include <stdio.h>
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkNode;

typedef struct LinkQueue{
	LinkNode front,rear;
}LinkQueue;

LinkQueue * InitQueue(){
	LinkQueue * Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	if(!Q) return 0;
	Q->front = Q->rear = (LinkNode)malloc(sizeof(LNode)); 
	if(!Q->front) return 0;
	
	Q->front->next = NULL;
	return Q;
} 	

void DestoryQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	free(Q);
}

void ClearQueue(LinkQueue *Q){
	LinkNode p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
}

int QueueLength(LinkQueue Q){
	int i = 0;
	LinkNode p;
	p = Q.front;
	while(Q.rear != p){
		i++;
		p = p->next;
	}
	return i;
}

int EmptyQueue(LinkQueue Q){
	if(Q.front->next == NULL){
		return 1;
	}else{
		return -1;
	}
}

void Print(LinkQueue Q){
	int i = 0;
	LinkNode p;
	p = Q.front;
	while(Q.rear != p){
		i++;
		printf("%d\n",p->next->data);
		p = p->next;
	}
}

int GetQueueHead(LinkQueue Q, ElemType *e){
	LinkNode p;
	if(Q.front == Q.rear){
		return -1;
	}
	p = Q.front->next;
	*e = p->data;
	return 1;
}

void EnQueue(LinkQueue *Q, ElemType e){
	LinkNode p = (LinkNode)malloc(sizeof(LNode));
	if(!p) return 0;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p; 
}

int DeQueue(LinkQueue *Q, ElemType *e){
	LinkNode p;
	if(Q->front == Q->rear) return -1;
	p = Q->front->next;
	
	*e = p->data;
	printf("%d\n",e);
	Q->front->next = p->next;
	if(Q->rear == p){
		Q->rear = Q->front;
	}
	free(p);
	return 1;
	
	
}

int main(){
	LinkQueue *Q;
	Q = InitQueue();
	int a;
	a = EmptyQueue(*Q);
	printf("the queue is empty?  %d\n",a);
	a = 1;
	EnQueue(Q,a);
	a = 2;
	EnQueue(Q,a);
	
	Print(*Q);

	DeQueue(Q,&a); 
	
	Print(*Q);
	printf("the pop data is %d\n",a);
	
	a = 3;
	EnQueue(Q,a);
	a = 4;
	EnQueue(Q,a);
	
	a = QueueLength(*Q);
	printf("the queue length is %d\n",a);
	
	GetQueueHead(*Q,&a);
	
	printf("the queuehead data is %d\n",a);
	
	DeQueue(Q,&a); 
	printf("the pop data is %d\n",a);
	Print(*Q);
	DeQueue(Q,&a); 
	printf("the pop data is %d\n",a);
	
	ClearQueue(Q);
	
	a = EmptyQueue(*Q);
	printf("the queue is empty?  %d\n",a);
	
	DestoryQueue(Q);
	
} 
