#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TreeNode * Position;
typedef struct TreeNode  *SearchTree;

struct TreeNode{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
}; 

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T); 
Position FindMax(SearchTree T); 

SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);

void Print(SearchTree T, int n);

void Print(SearchTree T, int n){
	if(T != NULL){
		int i = 1;
		for(; i <= n; i++){
			printf("\t");
		}
		
		printf("%d\n",T->Element);
		Print(T->Left,i);
		Print(T->Right,i);
	}
}

SearchTree MakeEmpty(SearchTree T){
	if(T != NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}


Position Find(ElementType X, SearchTree T){
	if(T == NULL){
		return NULL;
	}
	if(X < T->Element){
		return Find(X,T->Left); 
	}else if(X > T->Element){
		return Find(X, T->Right);
	}else{
		return T;
	}
}


Position FindMin(SearchTree T){
	if(T != NULL){
		while(T->Left != NULL)
			T = T->Left;
	}
	return T;
	
}

Position FindMax(SearchTree T){
	if(T == NULL){
		return NULL;
	}
	if(T->Right == NULL){
		return T;
	}else {
		return FindMax(T->Right);
	}
	
}

SearchTree Insert(ElementType X, SearchTree T){
	
	//if tree is null create and return a one-node tree.
	if(T == NULL){
		
		T = (SearchTree *)malloc(sizeof(struct TreeNode));
		if(T == NULL){
			printf("create tree failed!");
			return 0;
			
		}else{
			T->Element = X;
			T->Left = T->Right =  NULL;
		}
	}else if(X < T->Element){ //X < T's Emement ?    and carry X to T's nextNode.
		T->Left = Insert(X, T->Left);
	}else if(X > T->Element){
		T->Right = Insert(X, T->Right);
	}
	
	//Else X is in the tree already, we'll do nothing.
	
	//return created Node.
	return T;
}

SearchTree Delete(ElementType X, SearchTree T){
	//create a temp treenode.
	Position TmpCell;
	
	if(T == NULL){
		printf("Element not found");
		return 0;
	}else if(X < T->Element){
		T->Left = Delete(X, T->Left);
	}else if(X > T->Element){
		T->Right = Delete(X, T->Right);
	}	
	else if(T->Left && T->Right){ //Two children
		// replace with smallest in right subtree
		
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		
		
		T->Right = Delete(T->Element, T->Right);
	}else{   //one or zero children
		TmpCell = T;
		if(T->Left == NULL){  //also handles 0 children
			
			T = T->Right; 
		}else if(T->Right == NULL){
			T = T->Left; 
		}
		free(TmpCell);
	}
	
	return T;
}




int main(){
	SearchTree t = NULL;
	t = Insert(34,t);
	t = Insert(21,t);
	t = Insert(54,t);
	t = Insert(61,t);
	t = Insert(45,t);
	t = Insert(19,t);
	t = Insert(25,t);
	t = Insert(5,t);
	t = Insert(-1,t);
	Print(t,1);
	
	t = Delete(54,t); 
	t = Delete(5,t); 
	Print(t,1);
	
	t = Delete(34,t); 
	Print(t,1);
	
	t = MakeEmpty(t);
	if(t == NULL){
		printf("the tree is empty"); 
	} 
	return 0;
}
