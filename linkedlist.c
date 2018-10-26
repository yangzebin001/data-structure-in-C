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
	//移动指针到要结点的位置的前一个结点 
	while(p && j < i){
		p = p->next;
		++j;
	}
	if(!p || j>i){
		return ERROR;
	}
	//创建新结点 
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	//将 上一个结点的next赋给新结点的next； 
	s->next = p->next;
	//将新节点的地址赋给上一个结点 
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L, int i,ElemType *e){
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	//移动指针到要删除的位置 
	while(p->next && j < i){
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i){
		return ERROR;
	}
	//将该结点的next保存下来 
	q = p->next;
	//将要删除的前一个结点的next赋与要被删除结点的next 
	p->next = q->next;
	//保存数据 
	*e = q->data;
	//释放该结点 
	free(q);
	return OK;
}
//建立带表头节点的单链表（头插法） 
void CreateListHead(LinkList *L, int n){
	LinkList p;
	int i;
	srand(time(0));
	//头结点 
	*L = (LinkList)malloc(sizeof(Node));
	(*L) ->next = NULL;
	//头插法----每次都向第一个节点前插入节点。 
	for(i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 +1; //随机生成100以内的数字
		
		
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//建立带表头节点的单链表（尾插法）
void CreateListTail(LinkList *L, int n){
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	//r为指向尾部的结点 
	r = *L;
	for(i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		//将刚创建好的结点插到r之后 
		r->next = p;
		//将r更新为尾结点 
		r = p; 
	} 
	
	//将r结点的next置为NULL 
	r->next = NULL;
} 

Status ClearList(LinkList *L){
	LinkList p,q;
	//指向第一个结点（除了头结点） 
	p = (*L)->next;
	//清除结点 
	while(p){
		q = p->next;
		free(p);
		p = q;
	} 
	//将头结点的next置NULL 
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
