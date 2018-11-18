#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct AVLTreeNode * Position;
typedef struct AVLTreeNode  *AVLTree;

struct AVLTreeNode{
	ElementType Element;
	AVLTree Left;
	AVLTree Right;
	int Height;
}; 

AVLTree MakeEmpty(AVLTree T);
Position Find(ElementType X, AVLTree T);
Position FindMin(AVLTree T); 
Position FindMax(AVLTree T); 

AVLTree Insert(ElementType X, AVLTree T);
AVLTree Delete(ElementType X, AVLTree T);

static int Max(int a, int b){
	return a > b ? a : b;
}

//返回一个结点所在的高度 
static int Height(Position P){
	if(P == NULL){
		return -1;
	}else{
		return P->Height;	
	}
}

/* This function can be called only if K2 has a left child*/ 
/* Perform a rotate between a node(K2) and its left child*/
/* Update heights, then return new root*/
static Position SingleRotateWithLeft(Position K2){
	Position K1;
	
	//单旋转 
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	
	//更新子树高度 
	K2->Height = Max(Height(K2->Left),Height(K2->Right)) + 1; 
	K1->Height = Max(Height(K1->Left),K2->Height) + 1;
	return K1; 
}


static Position SingleRotateWithRight(Position K2){
	Position K1;
	
	//单旋转 
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	
	//更新子树高度 
	K2->Height = Max(Height(K2->Left),Height(K2->Right)) + 1; 
	K1->Height = Max(Height(K1->Left),K2->Height) + 1;
	return K1; 
}

/* This function can be called only if K3 has a left */
/* Child and K3's left child has a right child */
/* Do the left-right double rotaion */
/* Update heights, then return new root */
static Position DoubleRotateWithLeft(Position K3){
	/* Rotate between K1 and k2 */
	K3->Left = SingleRotateWithRight(K3->Left);
	
	/* Rotate between K3 and K2 */
	return SingleRotateWithLeft(K3);
} 


static Position DoubleRotateWithRight(Position K3){
	/* Rotate between K1 and k2 */
	K3->Right = SingleRotateWithLeft(K3->Right);
	
	/* Rotate between K3 and K2 */
	return SingleRotateWithRight(K3);
} 


void Print(AVLTree T, int n){
	if(T != NULL){
		n++;
		Print(T->Left,n);
		int i;
		for(i = 2; i < n;i++){
			printf("\t");
		}
		printf("%d\n",T->Element);
		
		Print(T->Right,n);
		
	} 
}

AVLTree MakeEmpty(AVLTree T){
	if(T != NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}


Position Find(ElementType X, AVLTree T){
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

Position FindMin(AVLTree T){
	if(T != NULL){
		while(T->Left != NULL)
			T = T->Left;
	}
	return T;
	
}

Position FindMax(AVLTree T){
	if(T == NULL){
		return NULL;
	}
	if(T->Right == NULL){
		return T;
	}else {
		return FindMax(T->Right);
	}
	
}



//向AVL树中插入一个元素 
AVLTree Insert(ElementType X, AVLTree T){
	if(T == NULL){
		T = malloc(sizeof(struct AVLTreeNode));
		if(T == NULL){
			printf("create node failed!");
			return 0;
		}else{
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}else if(X < T->Element){
		T->Left = Insert(X, T->Left);
		if(Height(T->Left) - Height(T->Right)== 2){
			if(X < T->Left->Element){
				T = SingleRotateWithLeft(T);
			}else{
				T = DoubleRotateWithLeft(T);
			}
		}
	}else if(X > T->Element){
		T->Right = Insert(X,T->Right);
		if(Height(T->Right) - Height(T->Right) == 2){
			if(X > T->Right->Element){
				T = SingleRotateWithRight(T);
			}else{
				T = DoubleRotateWithRight(T);
			}
		}
	} 
	/* Else X is in the tree already; we'll do nothing */
	//更新树高度
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	
	return T; 
	
}

int main(){
	AVLTree t = NULL;
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
} 
