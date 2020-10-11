#include <cstdio>
#include <vector>
#define LL long long int
using namespace std;

LL max_one(LL a, LL b, LL c){
    a = a > b ? a : b;
    a = a > c ? a : c;
    return a;
}

class node{
public:
    node* daddy;
    node* lchild;
    node* rchild;

    int st;
    int ed;

    LL yy;
    LL yn;
    LL ny;
    LL nn;
};

class stree{
public:
    node* head;

    void btree(int n, LL* in);
    node* add_nodes(node* cur, int st, int ed, LL* in);
    void ask(node* cur, int st, int ed, LL &nn, LL &ny, LL &yn, LL &yy);
    void update(int pos, LL val);
};

void stree::btree(int n, LL* in){
    head = new node;
    head->st = 0;
    head->ed = n-1;
    head->daddy = NULL;
    int mid = (n-1)/2;
    head->lchild = add_nodes(head, 0, mid, in);
    head->rchild = add_nodes(head, mid+1, n-1, in);

    node* add = head;
    add->nn = max_one(add->lchild->nn + add->rchild->nn,
            add->lchild->ny + add->rchild->nn,
            add->lchild->nn + add->rchild->yn);
        add->ny = max_one(add->lchild->nn + add->rchild->ny,
            add->lchild->ny + add->rchild->ny,
            add->lchild->nn + add->rchild->yy);
        add->yn = max_one(add->lchild->yn + add->rchild->nn,
            add->lchild->yy + add->rchild->nn,
            add->lchild->yn + add->rchild->yn);
        add->yy = max_one(add->lchild->yn + add->rchild->ny,
            add->lchild->yy + add->rchild->ny,
            add->lchild->yn + add->rchild->yy);
    return;
}

node* stree::add_nodes(node* cur, int st, int ed, LL* in){
    node* add = new node;
    if(ed == st){
        add->daddy = cur;
        add->lchild = NULL;
        add->rchild = NULL;

        add->st = st;
        add->ed = ed;

        add->nn = 0;
        add->ny = 0;
        add->yn = 0;
        add->yy = in[st];
    }
    else{
        int mid = (st + ed)/2;
        add->daddy = cur;
        add->lchild = add_nodes(add, st, mid, in);
        add->rchild = add_nodes(add, mid+1, ed, in);

        add->st = st;
        add->ed = ed;

        add->nn = max_one(add->lchild->nn + add->rchild->nn,
            add->lchild->ny + add->rchild->nn,
            add->lchild->nn + add->rchild->yn);
        add->ny = max_one(add->lchild->nn + add->rchild->ny,
            add->lchild->ny + add->rchild->ny,
            add->lchild->nn + add->rchild->yy);
        add->yn = max_one(add->lchild->yn + add->rchild->nn,
            add->lchild->yy + add->rchild->nn,
            add->lchild->yn + add->rchild->yn);
        add->yy = max_one(add->lchild->yn + add->rchild->ny,
            add->lchild->yy + add->rchild->ny,
            add->lchild->yn + add->rchild->yy);
    }
    return add;
}

void stree::ask(node* cur, int st, int ed, LL& nn, LL &ny, LL &yn, LL &yy){
    if(ed > cur->ed) ed = cur->ed;
    if(st < cur->st) st = cur->st;
    if(cur->st == st &&  cur->ed == ed){
        nn = cur->nn;
        ny = cur->ny;
        yn = cur->yn;
        yy = cur->yy;
        return;
    }
    node left, right;
    ask(cur->lchild, st, ed, left.nn, left.ny, left.yn, left.yy);
    ask(cur->rchild, st, ed, right.nn, right.ny, right.yn, right.yy);
    nn = max_one(left.nn + right.nn, left.ny + right.nn, left.nn + right.yn);
    yn = max_one(left.yn + right.nn, left.yy + right.nn, left.yn + right.yn);
    ny = max_one(left.nn + right.ny, left.ny + right.ny, left.nn + right.yy);
    yy = max_one(left.yn + right.ny, left.yy + right.ny, left.yn + right.yy);
    return;
}

void stree::update(int pos, LL val){
    node* add = head;
    while(add->st != add->ed){
    }
    while(add != head){
    }
    return;
}

int main(){
    int m, n;
    scanf("%d%d", &n, &m);
    LL in[100005];
    for(int i = 0; i < n; i++)
        scanf("%lld", &in[i]);
    
    stree tree;
    tree.btree(n, in);

    while(m--){
        int task;
        scanf("%d", &task);
        if(!task){ // update
            int pos;
            LL val;
            scanf("%d%lld", &pos, &val);
            tree.update(pos, val);
        }
        else{
            int st, ed;
            scanf("%d%d", &st, &ed);
            if(st == 0 && ed == n-1){
                LL ans = (tree.head)->nn > (tree.head)->ny ? (tree.head)->nn : (tree.head)->ny;
                ans = ans > (tree.head)->yn ? ans : (tree.head)->yn;
                ans = ans > (tree.head)->yy ? ans : (tree.head)->yy;
                printf("%lld\n", ans);
            }
            else{
                LL nn, ny, yn, yy;
                tree.ask(tree.head, st, ed, nn, ny, yn, yy);
                LL ans;
                ans = nn > ny ? nn : ny;
                ans = ans > yn ? ans : yn;
                ans = ans > yy ? ans : yy;
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}