#include <stdio.h>

typedef int ElemType;  

typedef struct DuLNode{
	ElemType data;
	struct DuLNode *next, *prior; 
}DuLNode, *DuLinkList;

//��ʼ����
void InitList(DuLinkList *L){
	*L = (DuLinkList)malloc(sizeof(struct DuLNode));
	
	if(!*L) return 0;
	//ָ����Ϊ�� 
	(*L)->next = (*L)->prior = *L;
} 
//�������ٱ� 
void DestroyList(DuLinkList *L){
	DuLinkList q;
	while(*L){
		q = (*L)->next;
		free(*L);
		*L = q;
	}
} 
//��ʼ��Ϊ�ձ�״̬ 
void ClearList(DuLinkList L){
	DuLinkList p,q;
	p = L->next;
	while(p != L){
		q = p->next;
		free(p);
		p = q;
	}
	//��Ϊ˫������� 
	L->next = L->prior = L;
}
//�ж��Ƿ�Ϊ�ձ� 
int ListEmpty(DuLinkList L){
	if(L->next == L && L->prior == L) {
		return 1;
	}else{
		return 0;
	}
} 
//��������ĳ��ȣ�����ͷ��㣩 
int ListLength(DuLinkList L){
	int length = 0;
	DuLinkList p = L->next;
	while(p && p != L){
		length++;
		p = p->next;
	}
	return length;
}
//�������еõ���i��λ�õ����� 
int GetElem(DuLinkList L,int i,ElemType *e){
	int j = 1;
	DuLinkList p = L->next;
	while(p && j<i){
		p = p->next;
		j++;
	}
	if(!p || j > i) return -1;
	*e = p->data;
	return 0;
	
}
//�����������������ڵ�λ�� 
int LocateElem(DuLinkList L, ElemType e){
	int i = 0;
	DuLinkList p = L->next;
	while(p){
		i++;
		if(p->data == e){
			return i;
		}
		p = p->next;
	}
	return 0;
}
//ȡ�������н�����ݵ���һ��������� 
int PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e){
	DuLinkList p;
	p = L->next->next;
	while(p != L){
		if(p->data == cur_e){
			*pre_e = p->prior->data;
			return 1;
		}
		p = p->next;
	}
	return 0;
}
// //ȡ�������н�����ݵ���һ��������� 
int NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e){
	DuLinkList p = L->next;
	while(p->next && p){
		if(p->data == cur_e){
			*next_e = p->next->data;
			return 1;	
		}
		p = p->next;
	}
	return 0;
}
//���ص�i�����
DuLinkList GetElemP(DuLinkList L, int i){
	int j;
	DuLinkList p = L;
	if(i < 0 || i >ListLength(L))
		return NULL;
	for(j = 1; j <= i; j++){
		p = p->next;
	}
	return p;
} 

//����һ����� 
int ListInsert(DuLinkList L, int i, ElemType e){
	int j = 0;
	DuLinkList p, s;
	if(i < 0 || i >ListLength(L)+1)
		return NULL;
	p = GetElemP(L,i-1);
	if(!p) return 0;
	s = (DuLinkList)malloc(sizeof(struct DuLNode));
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	return 1;
}


//ɾ��һ����� 
int ListDelete(DuLinkList L, int i, ElemType *e){
	int j = 0;
	DuLinkList p;
	if(i < 1 || i >ListLength(L))
		return NULL;
	p = GetElemP(L,i); 
	if(!p) return 0;
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
}

 
int PrintList(DuLinkList *L){
	DuLinkList p,q;
	int nox = 1;
	p = (*L)->next;
	if(p == *L){
		printf("this DuLinkList is empty!");
		return 0;
	}
	while(p != *L){
		printf("%d  %d\n",nox++,p->data);
		p = p->next;
	}
	
} 


int main(){
	DuLinkList l;
	int a;
	InitList(&l);
	ListInsert(l,1,123);
	ListInsert(l,1,845);
	ListInsert(l,2,8);
	ListInsert(l,2,34);
	PrintList(&l);
	ListDelete(l,2,&a);
	printf("\nthe deleted No.2 Node data is %d\n",a);
	PrintList(&l);
	
	a = ListLength(l);
	printf("\nthe linklist length is %d",a);
	GetElem(l,2,&a);
	printf("\nthe No.2 node data is %d ",a);
	a = LocateElem(l,123);
	printf("\nthe node that data is 123 locate is %d ",a);
	PriorElem(l,123,&a);
	printf("\nthe prior node of node's data is 123 is'%d",a);
	NextElem(l,845,&a);
	printf("\nthe next node's data  that node's data is 845 is'%d\n",a);
	ClearList(l);
	PrintList(&l);
	ListEmpty ? printf("\nlinklist is cleared!") : printf("\nlinklist is not cleared!");
} 
