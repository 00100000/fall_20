#include <cmath>
#include <cstdio>
#include<iostream>
#define LL long long int
using namespace std;

int in[1000005];

class node{
	public:
		int st;
		int ed;
		int mid;
		
		node* daddy;
		node* lchild;
		node* rchild;
		
		int max;
};

class stree{
	public:
		node* head;
		int n;
		void build();
		node* addnode(node* dad, int i, int j);
		int query(node* cur, int i, int j);
};

int main(){
	stree tree;
    int m;
    scanf("%d%d", &tree.n, &m);
    for(int i = 0; i < tree.n; i++) scanf("%d", &in[i]);
    tree.build();
    while(m--){
    	int i, j;
    	scanf("%d%d", &i, &j);
    	printf("%d\n", tree.query(tree.head, i, j));
	}
}

void stree::build(){
	head = addnode(NULL, 0, n-1);
}

node* stree::addnode(node* dad, int i, int j){
	//printf("%d %d\n", i, j);
	node* a = new node;
	a->st = i;
	a->ed = j;
	a->mid = (i + j)/2;
	a->daddy = dad;
	if(i == j){
		a -> max = in[i];
		//printf("%d\n", a->max);
		a -> lchild = NULL;
		a -> rchild = NULL;
		return a;
	}
	a->lchild = addnode(a, i, a->mid);
	a->rchild = addnode(a, a->mid + 1, j);
	a->max = a->lchild->max > a->rchild->max ? a->lchild->max : a->rchild->max;
	//printf("%d\n", a->max);
	return a;
}

int stree::query(node* cur, int i, int j){
	if(cur -> st == i && cur -> ed == j) return cur -> max;
	if(j <= cur -> mid) return query(cur->lchild, i, j);
	if(i > cur -> mid) return query(cur -> rchild, i, j);
	int a1 = query(cur->lchild, i, cur -> mid);
	int a2 = query(cur->rchild, cur -> mid + 1, j);
	return a1 > a2 ? a1 : a2;
}