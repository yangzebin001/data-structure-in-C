#include <stdio.h>
#include <stdlib.h>
 
typedef int ElemType;  

typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkStack;
 
 
void InitList(LinkStack * L){
	*L = (LinkStack)malloc(sizeof(struct LNode));
	
	if(!*L) return 0;
	//Ö¸ÕëÓòÎª¿Õ 
	(*L)->next = NULL;
} 

void Push(LinkStack L, int x){
	LinkStack s,p;
	p = L;
	s = (LinkStack)malloc(sizeof(struct LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
}

void Pop(LinkStack L, int *e){
	LinkStack s;
	s = L->next;
	if(s != NULL){
		*e = s->data; 
		L->next = s->next;
		free(s);
	}
}

ElemType GetTop(LinkStack L){
	if(L->next != NULL){
		return L->next->data;
	}else{
		return NULL;
	}
}

int IsEmpty(LinkStack L){
	return L->next == NULL;
}

void MakeEmpty(LinkStack L){
	int e;
	if(L == NULL){
		return 0;
	}else{
		while(!IsEmpty(L)){
			Pop(L,&e); 
		}
	}
}

void Print(LinkStack L){
	LinkStack s = L->next;
	if(s == NULL){
		printf("this stack is empty.");
		return 0;
	}
	while(s){
		printf("data is %d\n",s->data);
		s = s->next; 
	}
}

int main(){
 	LinkStack L;
	InitList(&L);
	Push(L,111);
	int e;	
	Print(L);

	e = GetTop(L); 
	printf("%d\n",e);
	Pop(L,&e);
	printf("%d\n",e);
	MakeEmpty(L);
	Print(L);
	return 0;
} 
