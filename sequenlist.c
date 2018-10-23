#include <stdio.h>
#define MAXSIZE 100
struct sequenlist{
	int a[MAXSIZE];
	int len;
};
int Length (struct sequenlist *L){
	return L->len;
}

void Insert(struct sequenlist *s, int x, int index){
	int j;
	if(s->len >= MAXSIZE){
		printf("overflow\n");
	}else if((index<1) || (index > s->len+1)){
		printf("position is not correct!\n");
	}else {
		for(j = s->len;j>=index;j--)
			s->a[j+1] = s->a[j];
		s->a[index] = x;
		s->len++; 
	}
}

int Delete(struct sequenlist *s, int index){
	int j,data;
	if((index < 1) || index > s->len){
		printf("position is not correct!\n");
	}else{
		data = s->a[index];
		for(j = index + 1; j <= s->len; j++)
			s->a[j-1] = s->a[j];
		s->len--;
	}
	return data;
}

void Setnull(struct sequenlist *s) {
	
	s->len = 0;
}

int Locate(struct sequenlist *s, int x){
	int j = 0;
	while((j < s->len) && (s->a[j] != x)){
		j++;
	}
	if(j < s->len){
		return j;	
	}else {
		return -1;	
	} 
}

int Get(struct sequenlist *s, int index){
	if((index < 0) || (index >= s->len)){
		return NULL;	
	}else{
		return s->a[index];
	}
	
}


int main(){
	struct sequenlist s;
	s.a[0] = 1;
	s.a[1] = 4;
	s.a[2] = 5; 
	s.len = 3;
	int i,j,data,locate,data2;
	Insert(&s,3,1);
	data = Delete(&s,2); 
	
	i = Length(&s);
	printf(" the length of s is %d\n deleted data is %d\n",i,data);
	for(j = 0; j < s.len; j++){
		printf("%d ",s.a[j]);	
	}
	printf("\n");
	locate = Locate(&s,3);
	printf("3 located in s is %d",locate);
	printf("\n");
	data2 = Get(&s,0);
	printf("index 0 in s is %d",data2);
} 
