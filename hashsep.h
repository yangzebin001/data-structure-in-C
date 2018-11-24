#ifndef _HashSep_H

typedef int ElementType;

struct ListNode;
typedef struct ListNode * Position;
struct HashTbl;
typedef struct HashTbl * HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key,HashTable H);
void TraverseNode(Position P);
void Traverse(HashTable H);
int NextPrime(int TableSize);

int Hash(int Key, int TableSize);

#endif 
