#include <cstdio>
using namespace std;
int in[500005];

class node{
public:
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
};

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
    if(st == cur -> st && ed == cur -> ed){
        node* a = new node;
        a -> nn = cur -> nn;
        a -> ny = cur -> ny;
        a -> yn = cur -> yn;
        a -> yy = cur -> yy;
        return a;
    }
    if(ed <= cur -> mid) return look(cur -> lchild, st, ed);
    if(st > cur -> mid) return look(cur -> rchild, st, ed);

    node* ln = look(cur -> lchild, st, cur -> mid);
    node* rn = look(cur ->rchild, cur -> mid + 1, ed);
    node* a = qmerge(ln, rn);
    delete ln;
    delete rn;

    return a;
}

void stree::merge(node* me){
    node* ln = me -> lchild;
    node* rn = me -> rchild;

    node* a = qmerge(ln, rn);
    me -> nn = a -> nn;
    me -> ny = a -> ny;
    me -> yn = a -> yn;
    me -> yy = a -> yy;
    delete a;
}

node* stree::qmerge(node* ln, node* rn){
    node* a = new node;

    //nn
    int tmp = 0;
    //nn nn
    if(ln -> nn >= 0 && rn -> nn >= 0)
        tmp = tmp > (ln -> nn + rn -> nn) ? tmp : ln -> nn + rn -> nn;
    //nn yn
    if(ln -> nn >= 0 && rn -> yn >= 0)
        tmp = tmp > (ln -> nn + rn -> yn) ? tmp : ln -> nn + rn -> yn;
    //ny nn
    if(ln -> ny >= 0 && rn -> nn >= 0)
        tmp = tmp > (ln -> ny + rn -> nn) ? tmp : ln -> ny + rn -> nn;
    a -> nn = tmp;

    //ny
    tmp = 0;
    //nn ny
    if(ln -> nn >= 0 && rn -> ny >= 0)
        tmp = tmp > (ln -> nn + rn -> ny) ? tmp : ln -> nn + rn -> ny;
    //ny ny
    if(ln -> ny >= 0 && rn -> ny >= 0)
        tmp = tmp > (ln -> ny + rn -> ny) ? tmp : ln -> ny + rn -> ny;
    //nn yy
    if(ln -> nn >= 0 && rn -> yy >= 0)
        tmp = tmp > (ln -> nn + rn -> yy) ? tmp : ln -> nn + rn -> yy;
    a -> ny = tmp;

    //yn
    tmp = 0;
    //yn nn
    if(ln -> yn >= 0 && rn -> nn >= 0)
        tmp = tmp > (ln -> yn + rn -> nn) ? tmp : ln -> yn + rn -> nn;
    //yn yn
    if(ln -> yn >= 0 && rn -> yn >= 0)
        tmp = tmp > (ln -> yn + rn -> yn) ? tmp : ln -> yn + rn -> yn;
    //yy nn
    if(ln -> yy >= 0 && rn -> nn >= 0)
        tmp = tmp > (ln -> yy + rn -> nn) ? tmp : ln -> yy + rn -> nn;
    a -> yn = tmp;

    //yy
    tmp = 0;
    //yn ny
    if(ln -> yn >= 0 && rn -> ny >= 0)
        tmp = tmp > (ln -> yn + rn -> ny) ? tmp : ln -> yn + rn -> ny;
    //yy ny
    if(ln -> yy >= 0 && rn -> ny >= 0)
        tmp = tmp > (ln -> yy + rn -> ny) ? tmp : ln -> yy + rn -> ny;
    //yn yy
    if(ln -> yn >= 0 && rn -> yy >= 0)
        tmp = tmp > (ln -> yn + rn -> yy) ? tmp : ln -> yn + rn -> yy;
    a -> yy = tmp;

    return a;
}