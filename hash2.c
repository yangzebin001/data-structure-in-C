#include <stdio.h>
#include "hashquad.h"

enum KindOfEntry{Legitimate, Empty, Deleted};

struct HashEntry{
	ElementType Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl{
	int TableSize;
	Cell * TheCells; 
};

int NextPrime(int a){
    int data = a,i;
    if(data <= 2) return 2;
    
    for(i = 2; i <= ((int)sqrt(data) +1);i++){
        if((data % i) == 0){
            i = 2-1;
            data++;
            continue;
        }
    }
    return data;
	
}


HashTable InitializeTable(int TableSize){
	HashTable H;
	int i;
	
	if(TableSize < MinTableSize){
		printf("The tableszie is too small!");
		return 0;
	}

	H = malloc(sizeof(struct HashTbl));
	
	H->TableSize = NextPrime(TableSize);
	
	H->TheCells = malloc(sizeof(Cell) * H->TableSize);
	if(H->TheCells == NULL){
		printf("memory error!");
		return 0;
	}
	
	for(i = 0; i < H->TableSize; i++){
		H->TheCells[i].Info =  Empty;
	}
	
	return H;
	 
}

int Hash(int Key, int TableSize){
	return Key % TableSize;
}


//平方探测散列法的find例程 
Position Find(ElementType Key, HashTable H){
	Position CurrentPos;
	int CollisionNum;
	
	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while(H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key){
		
		//平方探测函数：F(i) = F(i - 1) + 2i -1 
		
		CurrentPos += 2 * ++CollisionNum -1;
		if(CurrentPos >= H->TableSize){
			CurrentPos -= H->TableSize;
		}  
	}
	return CurrentPos;
}

void Insert(ElementType Key, HashTable H){
	Position Pos;
	Pos = Find(Key, H);
	
	
	if(H->TheCells[Pos].Info != Legitimate){
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}

}



HashTable Rehash(HashTable H){
	int i, OldSize;
	Cell *OldCells;
	
	OldCells = H->TheCells;
	OldSize = H->TableSize;
	
	H = InitializeTable(2 * OldSize);
	
	for(i = 0; i < OldSize; i++){
		if(OldCells[i].Info == Legitimate){
			Insert(OldCells[i].Element, H);
		}
	}
	free(OldCells);
	return H;
}

void Traverse(HashTable H){
	int number = H->TableSize,i;
	for(i = 0; i < number; i++){
		if(H->TheCells[i].Info != Legitimate){
			printf("NULL\n");
		}else if(H->TheCells[i].Info == Legitimate){
			printf("%d\n",H->TheCells[i].Element);
		}
	}
}

int main(){
	HashTable h;
	h = InitializeTable(10); 
	Insert(125,h);
	Insert(5,h);
	Insert(2,h);
	Insert(1,h);
	Insert(0,h);
	
	Insert(13,h);
	Insert(45,h);
	
	Insert(32,h);
	Insert(4214,h);
	
	Insert(42,h);
	Insert(421,h);

	h = Rehash(h);
	Traverse(h);
} 
