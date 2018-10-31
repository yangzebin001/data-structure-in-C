#include <stdio.h>

typedef int ElemType;  

typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkList;

//初始化表
void InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(struct LNode));
	
	if(!*L) return 0;
	//指针域为空 
	(*L)->next = *L;
} 
//彻底销毁表 
void DestroyList(LinkList *L){
	LinkList q;
	while(*L){
		q = (*L)->next;
		free(*L);
		*L = q;
	}
} 
//初始化为空表状态 
void ClearList(LinkList L){
	LinkList p,q;
	if(L->next == L) return 0;
	p = L->next;
	while(p != L){
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L;
}
//判断是否为空表 
int ListEmpty(LinkList L){
	return L->next == L;
} 
//返回链表的长度（不带头结点） 
int ListLength(LinkList L){
	int length = 0;
	LinkList p = L->next;
	while(p != L){
		length++;
		p = p->next;
	}
	return length;
}
//从链表中得到第i个位置的数据 
int GetElem(LinkList L,int i,ElemType *e){
	int j = 1;
	LinkList p = L->next;
	while(p != L && j<i){
		p = p->next;
		j++;
	}
	if(p == L || j > i) return -1;
	*e = p->data;
	return 0;
	
}
//返回链表中数据所在的位置 
int LocateElem(LinkList L, ElemType e){
	int i = 0;
	LinkList p = L->next;
	while(p != L){
		i++;
		if(p->data == e){
			return i;
		}
		p = p->next;
	}
	return 0;
}
//取得链表中结点数据的上一个结点数据 
int PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e){
	LinkList q, p = L->next;
	while(p->next != L){
		q = p->next;
		if(q->data == cur_e){
			*pre_e = p->data;
			return 1;
		}
		p = q;
	}
	return 0;
}
// //取得链表中结点数据的下一个结点数据 
int NextElem(LinkList L, ElemType cur_e, ElemType *next_e){
	LinkList p = L->next;
	while(p->next != L){
		if(p->data == cur_e){
			*next_e = p->next->data;
			return 1;	
		}
		p = p->next;
	}
	return 0;
}
//插入一个结点 
int ListInsert(LinkList L, int i, ElemType e){
	int j = 0;
	LinkList p = L, s;
	while(p && j < i-1){
		p = p->next;
		j++;
	}
	if(!p || j > i-1){
		return -1;
	}
	s = (LinkList)malloc(sizeof(struct LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}


//删除一个结点 
int ListDelete(LinkList L, int i, ElemType *e){
	int j = 0;
	LinkList p = L, q;
	while(p->next && p->next != L && j < i-1){
		p = p->next;
		j++;
	}
	if(!p->next || p->next == L || j > i-1){
		return 0;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return 1;
}

 
void PrintList(LinkList *L){
	LinkList p,q;
	int nox = 1;
	p = (*L)->next;
	if(p == (*L)){
		printf("this linklist is empty!");
		return 0;
	}
	while(p != (*L)){
		printf("%d  %d\n",nox++,p->data);
		p = p->next;
	}
	
} 


int main(){
	LinkList l;
	int a;
	InitList(&l);
	ListInsert(l,1,123);
	ListInsert(l,1,845);
	ListInsert(l,2,8);
	PrintList(&l);
	
	ListDelete(l,2,&a);
	PrintList(&l);
	printf("\n%d",a);
	a = ListLength(l);
	printf("\n%d",a);
	GetElem(l,2,&a);
	printf("\n%d",a);
	a = LocateElem(l,123);
	printf("\n%d",a);
	PriorElem(l,123,&a);
	printf("\n%d",a);
	NextElem(l,845,&a);
	printf("\n%d\n",a);
	ClearList(l);
	PrintList(&l);
} 
