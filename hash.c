#include "hashsep.h"
#include <stdio.h>
#include <stdlib.h>

#define MinTableSize 1

struct ListNode{
	ElementType Element;
	Position Next;
}; 

typedef Position List;

struct HashTbl{
	int TableSize;
	List *TheLists;
};

int NextPrime(int a){
    int data = a,i,flag = 0;
    if(data <= 2) return 2;
    
    for(i = 2; i <= sqrt(data); i++ ){
        if((data % i) == 0){
            i = 2;
            data++;
            continue;
        }
    }
    return data;
	
}

int Hash(int Key, int TableSize){
	return Key % TableSize;
}

HashTable InitializeTable(int TableSize){
	HashTable H;
	int i;
	if(TableSize < MinTableSize){
		printf("tablesize error");
		return NULL;
	}
	
	H = malloc(sizeof(struct HashTbl));
	if(H == NULL){
		printf("init hashtable fail"); 
		return NULL; 
	} 
	//H->TableSize = NextPrime(TableSize);
	H->TableSize = NextPrime(TableSize);
	
	H->TheLists = malloc(sizeof(List) * H->TableSize);
	
	if(H->TheLists == NULL){
		printf("init Thelists fail"); 
		return NULL;
	} 
	 
	for(i = 0; i < H->TableSize; i++){
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		if(H->TheLists[i] == NULL){
			printf("init Thelists fail"); 
			return NULL;
		}else{
			H->TheLists[i]->Next = NULL;
		}
	} 
	
	return H;
	 
}


Position Find(ElementType Key, HashTable H){
	Position P;
	List L;
	
	L = H->TheLists[Hash(Key,H->TableSize)];
	P = L->Next;
	while(P != NULL && P->Element != Key){
		P = P->Next;
	}
	return P;
}

void Insert(ElementType Key, HashTable H){
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	//not found key 
	if(Pos == NULL){
		NewCell = malloc(sizeof(struct ListNode));
		if(NewCell == NULL){
			printf("init NewCell fail"); 
			return NULL;
		} else{
			L = H->TheLists[Hash(Key,H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}	
}

void TraverseNode(Position P){
	while(P != NULL){
		printf("%d\t",P->Element);
		P = P->Next;
	}
	printf("\n");
}

void Traverse(HashTable H){
	int i = 0;
	for(;i < H->TableSize; i++){
		if(H->TheLists[i]->Next == NULL){
			printf("NULL\n");
		}else{
			TraverseNode(H->TheLists[i]->Next);
		}
	}
}

int main(){

	HashTable h;
	h = InitializeTable(6);
	Insert(5,h);
	Insert(15,h);
	Insert(3,h);
	Insert(2,h);
	Traverse(h);
	Position p;
	p = Find(3,h);
	
	
	TraverseNode(p);
}










