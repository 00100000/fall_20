#include <cstdio>
#include <vector>
#define LL long long int
using namespace std;

LL in[100005];
int n;

class node{
public:
    int st;
    int ed;
    int mid;

    node* daddy;
    node* lchild;
    node* rchild;

    LL yy;
    LL yn;
    LL ny;
    LL nn; 
};

class stree{
public:
    node* head;

    void btree();
    node* add_nodes(node* cur, int st, int ed);
    void ask(node* cur, int st, int ed, LL &nn, LL &ny, LL &yn, LL &yy);
    void update(int pos, LL val);
};

void stree::btree(){
    head = new node;
    head -> st = 0;
    head -> ed = n - 1;
    head -> mid = (n - 1) / 2;

    head -> daddy = NULL;
    head -> lchild = add_nodes(head, 0, head -> mid);
    head -> rchild = add_nodes(head, head -> mid + 1, n-1);

    // nn, yn, ny, yy
}

node* stree::add_nodes(node* cur, int st, int ed){
    node* newnode = new node;

    newnode -> st = st;
    newnode -> ed = ed;
    int mid = (st + ed) / 2;
    newnode -> mid = mid;

    if(st == ed){
        //
        return newnode;
    }
    else if(st + 1 == ed){
        //
        return newnode;
    }

    newnode -> daddy = cur;
    //newnode -> lchild = add_nodes(newnode, )
}

int main(){
    int m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%lld", &in[i]);
    
    stree tree;
    tree.btree();
}