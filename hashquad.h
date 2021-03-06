#ifndef _HashQuad_H
#define MinTableSize 2


typedef unsigned int Index;
typedef int ElementType;
typedef Index Position;

struct HashTbl;

typedef struct HashTbl * HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);
int Hash(int Key, int TableSize);
int NextPrime(int a);

void Traverse(HashTable H);


#endif 
