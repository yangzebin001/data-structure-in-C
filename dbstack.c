#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;


typedef int DbElemType;
typedef struct {
	DbElemType data[MAXSIZE];
	int top1;
	int top2;
}DbStack;

void InitStack(DbStack *s);
void PrintStack(DbStack *S);
Status Push(DbStack *S, DbElemType e, int stackNumber);
Status Pop(DbStack *S, DbElemType *e, int stackNumber);

Status ClearStack(DbStack *S);
int StatckLength(DbStack *S);
Status StackEmpty(DbStack *S);
Status GetTop(DbStack *S,DbElemType *e, int stackNumber);

void InitStack(DbStack *s){
	s->top1 = -1;
	s->top2 = MAXSIZE;
//	S->data[0]	= 0;
}

void PrintStack(DbStack *S){
	int i;
	if(S->top1 == -1 && S->top2 == MAXSIZE){
		printf("this stack is empty");
		return 0;
	}
	for(i = 0; i < MAXSIZE; i++){
		printf("%d\n",(*S).data[i]);
	}
	
}

Status Push(DbStack *S, DbElemType e, int stackNumber){
	if(S->top1 == S->top2) return ERROR;
	if(stackNumber == 1){
		S->top1++;
		S->data[S->top1] = e;
	}else if(stackNumber == 2){
		S->top2--;
		S->data[S->top2] = e;
	}

	return OK;
}

Status Pop(DbStack *S, DbElemType *e, int stackNumber){
//	if(S->top1 == -1 || S->top2 == MAXSIZE) return ERROR;
	if(stackNumber == 1 && S->top1 > -1){
		*e = S->data[S->top1];
		S->top1--;
	}else if(stackNumber == 2 && S->top2 < MAXSIZE){
		*e = S->data[S->top2];
		S->top2++;
	}
	
	
	return OK;
}

Status CleatStack(DbStack *S){
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

Status StackEmpty(DbStack *S){
	if(S->top1 < 0 && S->top2 > MAXSIZE -1){
		return TRUE;
	}else{
		return FALSE;
	}
}

int StatckLength(DbStack *S){
	return S->top1 + 1 + MAXSIZE - S->top2;
} 

Status GetTop(DbStack *S,DbElemType *e, int stackNumber){
	if(S->top1 < 0 && S->top1 > MAXSIZE -1){
		return ERROR;
	}else if(stackNumber == 1){
		*e = S->data[S->top1];
		return OK;
	}else if(stackNumber == 2){
		*e = S->data[S->top2];
		return OK;
	}
}


int main(){
	DbStack s;
	int i;
	for(i = 0; i < MAXSIZE; i++){
		s.data[i] = 0;
	}
	int e,length;
	InitStack(&s);
	Push(&s,231,1);
//	Pop(&s,&e,1); 
	Push(&s,564,2);
	Push(&s,531,2);
	Pop(&s,&e,2);
	Pop(&s,&e,2);
	GetTop(&s,&e,1);
	PrintStack(&s);
	length = StatckLength(&s);
	printf("get pop data is %d\n",e);
	printf("the stack length is %d\n",length);
	CleatStack(&s);
	PrintStack(&s);
} 





