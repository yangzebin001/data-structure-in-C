#include <stdio.h>

#define MAXSIZE 10
typedef int ElemType;

typedef struct seqqueue{
	ElemType data[MAXSIZE];
	int front,reart;
}Squeue, *Queue;

void InitQueue(Queue e){
//	(*e)->front = (*e)->reart = MAXSIZE -1;
	e->front =  MAXSIZE - 1;
	e->reart = MAXSIZE - 1;
	int length = MAXSIZE-1;
	while(length-- >= 0){
		e->data[length] = 0;
	}
}

void EnQueue(Queue e,ElemType x){
	if((e->reart + 1) % MAXSIZE == e->reart){
		printf("overflow\n");
	}else{
		e->reart = (e->reart + 1) % MAXSIZE;
		e->data[e->reart] = x;
	}
}

void DeQueue(Queue e, ElemType *x){
	if(e->front == e->reart){
		printf("overflow\n");	
	}else{
		
		e->front = (e->front + 1) % MAXSIZE;
		*x = e->data[e->front];
	}
	
}

ElemType GetHead(Queue e){
	if(e->front == e->reart) return NULL;
	return e->data[(e->front + 1) % MAXSIZE];
}

int IsEmpty(Queue e){
	return e->front == e->reart; 
}

void Print(Queue e){
	int i;
	for(i = 0; i < MAXSIZE; i++){
		printf("%d\n",e->data[i]);
	}
}

int main(){
	Squeue e;
	InitQueue(&e);
	int a = 111;
	EnQueue(&e, a);
	a = 223;
	EnQueue(&e, a);
	a = 343;
	EnQueue(&e, a);
	Print(&e);
	DeQueue(&e, &a);
	Print(&e);
	printf("the dequeue data is %d\n",a);
	DeQueue(&e, &a);
	Print(&e);
	printf("the dequeue data is %d\n",a);
	a = GetHead(&e); 
	printf("the head data is %d\n",a);
	DeQueue(&e, &a);
	a = IsEmpty(&e);
	printf("is empty ? %d\n",a);
	return 0;
} 
