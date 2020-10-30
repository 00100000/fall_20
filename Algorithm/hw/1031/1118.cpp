#include <cstdio>
#include <vector>
using namespace std;

class node{
public:
    int val;
    int l;
    int r;
    int mid;

    node* daddy;
    node* lchild;
    node* rchild;
};

class stree{
public:
    int n;
    node* head;
    vector<int> in;

    void build();
    node* addnode(node* cur, int i, int j);

    int query(node* cur, int i, int j);
    void update(node* cur, int pos, int val);
};

void stree::build(){
    //printf("build...\n");
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);

    head = new node;
    head -> l = 0;
    head -> r = n - 1;
    head -> mid = (n-1) / 2;

    head -> daddy = NULL;
    head -> lchild = addnode(head, 0, head -> mid);
    head -> rchild = addnode(head, (head -> mid) + 1, n-1);

    head -> val = (head -> lchild -> val) + (head -> rchild -> val);
}

node* stree::addnode(node* cur, int i, int j){
    //printf("add i:%d, j:%d\n", i, j);
    node* add = new node;
    add -> l = i;
    add -> r = j;
    add -> mid = (i + j) / 2;
    add -> daddy = cur;

    if(i == j){
        add -> lchild = NULL;
        add -> rchild = NULL;
        add -> val = in[i];
        return add;
    }

    add -> lchild = addnode(add, i, add -> mid);
    add -> rchild = addnode(add, (add -> mid + 1), j);
    add -> val = (add -> lchild -> val) + (add -> rchild -> val);
    return add;
}

int stree::query(node* cur, int i, int j){
    if(i > j) return query(cur, 0, j) + query(cur, i, n-1);
    if(cur -> l == i && cur -> r == j) return cur -> val;
    if(j <= cur -> mid) return query(cur -> lchild, i, j);
    if(i > cur -> mid) return query(cur -> rchild, i, j);
    return query(cur -> lchild, i, cur -> mid) + query(cur -> rchild, (cur -> mid) + 1, j);
}

void stree::update(node* cur, int pos, int val){
    if(pos == cur -> l && pos == cur -> r){
        cur -> val = val;
        return;
    }

    if(pos <= cur->mid) update(cur->lchild, pos, val);
    else update(cur->rchild, pos, val);

    cur -> val = (cur -> lchild -> val) + (cur -> rchild -> val);
}

int main(){
    stree tree;
    int m;
    scanf("%d%d", &tree.n, &m);
    //printf("no problem\n");
    tree.build();
    while(m--){
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        if(!i) tree.update(tree.head, j, k);
        else printf("%d\n", tree.query(tree.head, j, k));
    }
}