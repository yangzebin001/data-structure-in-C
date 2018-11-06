#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;


typedef int SElemType;
typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack *s);
void PrintStack(SqStack *S);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);

Status ClearStack(SqStack *S);
int StatckLength(SqStack *S);
Status StackEmpty(SqStack *S);
Status GetTop(SqStack *S,SElemType *e);

void InitStack(SqStack *s){
	s->top = -1;
//	S->data[0]	= 0;
}

void PrintStack(SqStack *S){
	int length = S->top;
	if(length < 0) {
		printf("this stack is empty!");
	}
	int i = 0;
	while(0 <= length){
		printf("%d\n",S->data[i++]);
		length--;
	}
}

Status Push(SqStack *S, SElemType e){
	if(S->top == MAXSIZE -1) return 0;
	S->top++;
	S->data[S->top] = e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e){
	if(S->top == -1) return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

Status CleatStack(SqStack *S){
	S->top = -1;
	return OK;
}

Status StackEmpty(SqStack *S){
	if(S->top < 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

int StatckLength(SqStack *S){
	return S->top + 1;
} 

Status GetTop(SqStack *S,SElemType *e){
	if(S->top < 0){
		return ERROR;
	}else{
		*e = S->data[S->top];
		return OK;
	}
}


int main(){
	
	SqStack s;
	InitStack(&s);
	Push(&s,1);
	Push(&s,343);
	PrintStack(&s);
	int a,length,status,top;
	length = StatckLength(&s);
	printf("length is %d\n",length);
	GetTop(&s,&top);
	printf("the top element is %d\n",top);
	Pop(&s,&a);
	Pop(&s,&a);
	length = StatckLength(&s);
	printf("%d length is %d\n",a,length);
	PrintStack(&s);
	status = Pop(&s,&a);
	printf("%d\n",status);
	CleatStack(&s);
	PrintStack(&s);
} 





