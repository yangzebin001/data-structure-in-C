#include <stdio.h>

typedef int ElemType;  

typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkList;

//��ʼ����
void InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(struct LNode));
	
	if(!*L) return 0;
	//ָ����Ϊ�� 
	(*L)->next = *L;
} 
//�������ٱ� 
void DestroyList(LinkList *L){
	LinkList q;
	while(*L){
		q = (*L)->next;
		free(*L);
		*L = q;
	}
} 
//��ʼ��Ϊ�ձ�״̬ 
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
//�ж��Ƿ�Ϊ�ձ� 
int ListEmpty(LinkList L){
	return L->next == L;
} 
//��������ĳ��ȣ�����ͷ��㣩 
int ListLength(LinkList L){
	int length = 0;
	LinkList p = L->next;
	while(p != L){
		length++;
		p = p->next;
	}
	return length;
}
//�������еõ���i��λ�õ����� 
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
//�����������������ڵ�λ�� 
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
//ȡ�������н�����ݵ���һ��������� 
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
// //ȡ�������н�����ݵ���һ��������� 
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
//����һ����� 
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


//ɾ��һ����� 
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
