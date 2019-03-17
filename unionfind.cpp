#include<iostream>
#define maxn 10005
using namespace std;

int father[maxn],rank[maxn];

void Init(int N){
	for(int i = 1; i <= N; i++){
		father[i] = i;
		rank[i] = 1;
	}
}

int find_set(int node){
	return node == father[node] ? node : father[node] = find_set(father[node]);
}

bool _union(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if(x == y) return false;
	if(rank[x] < rank[y]){
		father[x] = y;
		rank[y] += rank[x];
	}else{
		father[y] = x;
		rank[x] += rank[y];
	}
	return true;
}

bool issame(int x, int y){
	return find_set(x) == find_set(y);
}

int main(){
	Init(100);
	_union(2,3);
	_union(3,4);
	int ans = find_set(4);
	
	_union(5,6);
	_union(5,7);
	_union(5,8);
	
	bool ans1 = issame(5,4);
	cout << ans << endl; 
	cout << ans1 <<endl;
	
	_union(8,2);
	ans1 = issame(5,4);
	cout << ans1 << endl; 
	return 0;
}
 
