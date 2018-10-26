#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
} Node; 

typedef struct Node *LinkList;


Status GetElem(LinkList *L, int i, ElemType *e){
	int j;
	j = 1;
	LinkList p;
	p = (*L)->next;
	while(p && j < i){
		p = p->next;
		++j;
	}
	if(!p || j > i){
		return ERROR;
	}
	*e = p->data;
	return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e){
	int j;
	j = 1;
	LinkList p,s;
	p = *L;
	//�ƶ�ָ�뵽Ҫ����λ�õ�ǰһ����� 
	while(p && j < i){
		p = p->next;
		++j;
	}
	if(!p || j>i){
		return ERROR;
	}
	//�����½�� 
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	//�� ��һ������next�����½���next�� 
	s->next = p->next;
	//���½ڵ�ĵ�ַ������һ����� 
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L, int i,ElemType *e){
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	//�ƶ�ָ�뵽Ҫɾ����λ�� 
	while(p->next && j < i){
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i){
		return ERROR;
	}
	//���ý���next�������� 
	q = p->next;
	//��Ҫɾ����ǰһ������next����Ҫ��ɾ������next 
	p->next = q->next;
	//�������� 
	*e = q->data;
	//�ͷŸý�� 
	free(q);
	return OK;
}
//��������ͷ�ڵ�ĵ�����ͷ�巨�� 
void CreateListHead(LinkList *L, int n){
	LinkList p;
	int i;
	srand(time(0));
	//ͷ��� 
	*L = (LinkList)malloc(sizeof(Node));
	(*L) ->next = NULL;
	//ͷ�巨----ÿ�ζ����һ���ڵ�ǰ����ڵ㡣 
	for(i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 +1; //�������100���ڵ�����
		
		
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//��������ͷ�ڵ�ĵ�����β�巨��
void CreateListTail(LinkList *L, int n){
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	//rΪָ��β���Ľ�� 
	r = *L;
	for(i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		//���մ����õĽ��嵽r֮�� 
		r->next = p;
		//��r����Ϊβ��� 
		r = p; 
	} 
	
	//��r����next��ΪNULL 
	r->next = NULL;
} 

Status ClearList(LinkList *L){
	LinkList p,q;
	//ָ���һ����㣨����ͷ��㣩 
	p = (*L)->next;
	//������ 
	while(p){
		q = p->next;
		free(p);
		p = q;
	} 
	//��ͷ����next��NULL 
	(*L)->next = NULL;
	return OK;
} 
void PrintList(LinkList *L){
	LinkList p,q;
	int nox = 1;
	p = (*L)->next;
	if(!p){
		printf("this linklist is empty!");
		return 0;
	}
	while(p){
		printf("%d  %d\n",nox++,p->data);
		p = p->next;
	}
	
} 


int main(){
	LinkList a;
	int dedata,getdata;
		
	CreateListTail(&a,5); 
	PrintList(&a);
	
	GetElem(&a,3,&getdata); 
	printf("No.3 Node data is %d\n",getdata);
	
	ListDelete(&a,2,&dedata);
	PrintList(&a);
	printf("deleted data is %d\n",dedata);
	
	GetElem(&a,3,&getdata); 
	printf("new No.3 Node data is %d\n\n",getdata);
	
	ListInsert(&a,4,99); 
	ListInsert(&a,4,98); 
	ListInsert(&a,4,97); 
	ListInsert(&a,4,96); 
	PrintList(&a);
	ClearList(&a);
	PrintList(&a); 
	
	return 0;
} 
