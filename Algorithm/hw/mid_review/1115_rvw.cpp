#include <cstdio>
using namespace std;
int in[500005];

typedef struct node_{
    int st;
    int ed;
    int mid;

    node* daddy;
    node* lchild;
    node* rchild;

    int nn;
    int ny;
    int yn;
    int yy;
}node;

class stree{
    public:
    node* head;
    int n;

    void build();
    node* add(node* daddy, int st, int ed);

    void update(int pos, int val);
    void change(node* cur, int pos, int val);

    int query(int st, int ed);
    node* look(node* cur, int st, int ed);

    void merge(node* me);
    node* qmerge(node* ln, node* rn);
};

int main(){
    stree tree;

    int m;
    scanf("%d%d", &tree.n, &m);
    for(int i = 0; i < tree.n; i++) scanf("%d", &in[i]);
    tree.build();

    while(m--){
        int task;
        scanf("%d", &task);
        if(task){
            int st, ed;
            scanf("%d%d", &st, &ed);
            printf("%d\n", tree.query(st, ed));
        }
        else{
            int pos, val;
            scanf("%d%d", &pos, &val);
            tree.update(pos, val);
        }
    }
}

void stree::build(){
    head = add(NULL, 0, n-1);
}

node* stree::add(node* daddy, int st, int ed){
    node* ad = new node;
    ad -> st = st;
    ad -> ed = ed;
    ad -> mid = (st + ed) / 2;

    ad -> daddy = daddy;
    if(st == ed){
        ad -> lchild = NULL;
        ad -> rchild = NULL;
        ad -> nn = 0;
        ad -> ny = -1;
        ad -> yn = -1;
        ad -> yy = in[st];
        return ad;
    }

    ad -> lchild = add(ad, st, ad -> mid);
    ad -> rchild = add(ad, ad -> mid + 1, ed);
    if(st + 1 == ed){
        ad -> nn = 0;
        ad -> ny = in[ed];
        ad -> yn = in[st];
        ad -> yy = -1;
        return ad;
    }

    merge(ad);
    return ad;
}

void stree::update(int pos, int val){
    change(head, pos, val);
}

void stree::change(node* cur, int pos, int val){
    if(cur -> st == cur -> ed){
        cur -> yy = val;
        return;
    }

    if(pos <= cur -> mid) change(cur -> lchild, pos, val);
    else change(cur -> rchild, pos, val);

    if(cur -> st + 1 == cur -> ed){
        if(pos == cur -> st) cur -> yn = val;
        else cur -> ny = val;
        return;
    }
    merge(cur);
    return;
}

int stree::query(int st, int ed){
    node* a = look(head, st, ed);
    int ans = a -> nn;
    if(a -> ny > ans) ans = a -> ny;
    if(a -> yn > ans) ans = a -> yn;
    if(a -> yy > ans) ans = a -> yy;
    return ans;
}

node* stree::look(node* cur, int st, int ed){
    if(st == cur -> st && ed == cur -> ed) return cur;
    if(ed <= cur -> mid) return look(cur -> lchild, st, ed);
    if(st > cur -> mid) return look(cur -> rchild, st, ed);
    node* ln = look(cur -> lchild, st, cur -> mid);
    node* rn = look(cur ->rchild, cur -> mid + 1, ed);
    return qmerge(ln, rn);
}

void stree::merge(node* me){
    //
}

node* stree::qmerge(node* ln, node* rn){
    node* a = new node;
    //
    delete ln;
    delete rn;
    return a;
}