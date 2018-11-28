#include <stdio.h>
#include <stdlib.h>
#include "binheap.h"

struct HeapStruct{
	int Capacity;
	int Size;
	ElementType *Elements;
};

int IsFull(PriorityQueue H){
	return H->Capacity == H->Size; 
}
int IsEmpty(PriorityQueue H){
	return 0 == H->Size; 
}

PriorityQueue Initialize(int MaxElements){
	PriorityQueue H;
	
	if(MaxElements < MinPQSize){
		printf("the size is too small");
		return 0; 
	}
	H = malloc(sizeof(struct HeapStruct));
	if(H == NULL){
		printf("create heap fail");
		return 0;
	}
	
	H->Elements = malloc((MaxElements + 1 )* sizeof(ElementType));
	
	if(H->Elements == NULL){
		printf("Out of space!!");
		return 0;
	}
	
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	
	return H;
}

void Insert(ElementType X, PriorityQueue H){
	int i;
	if(IsFull(H)){
		printf("Priority queue is full");
		return;
	}
	
	for(i = ++(H->Size); H->Elements[i / 2] > X; i/=2){
		H->Elements[i] = H->Elements[i / 2];
	}
	H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H){
	int i, Child;
	ElementType MinElement, LastElement;
	
	if(IsEmpty(H)){
		printf("the heap is empty");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	
	for(i = 1; i *2 <= H->Size; i= Child){
		Child = i * 2;
		if(Child != H->Size && H->Elements[Child + 1] < H->Elements[Child]){
			Child++;
		}
		
		if(LastElement > H->Elements[Child]){
			H->Elements[i] = H->Elements[Child];
		}else{
			break;
		}
	}
	
	H->Elements[i] = LastElement;
	return MinElement;
}

void Traverse(PriorityQueue H){
	int i = 1;
	for(;i <= H->Size;i++){
		printf("%d ",H->Elements[i]);
	}
	printf("\n");
	
}


int main(){
	PriorityQueue H;
	int a;
	H = Initialize(10);
	Insert(2,H);
	Insert(5,H);

	Insert(1,H);
	Insert(4,H);
	Insert(7,H);
	Insert(13,H);
	Traverse(H);
	a = DeleteMin(H);
	
	Traverse(H);
	printf("%d",a);
	return 0;
} 
