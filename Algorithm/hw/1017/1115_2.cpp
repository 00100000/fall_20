#include <cstdio>
#define LL long long int
using namespace std;

LL in[500005];
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
    void ask(node* cur, int st, int ed, LL &nn, LL &yn, LL &ny, LL &yy);
    void update(node* cur, int pos, LL val);
};

void stree::btree(){
    head = new node;
    head -> st = 0;
    head -> ed = n - 1;
    head -> mid = (n - 1) / 2;

    if(head -> st == head -> ed){
        head -> daddy = NULL;
        head -> lchild = NULL;
        head -> rchild = NULL;

        head -> nn = 0;
        head -> yn = -1;
        head -> ny = -1;
        head -> yy = in[head -> st];
        return;
    }
    else if(head -> st + 1 == head -> ed){
        head -> daddy = NULL;
        head -> lchild = add_nodes(head, head -> st, head -> st);
        head -> rchild = add_nodes(head, head -> ed, head -> ed);

        head -> nn = 0;
        head -> yn = in[head -> st];
        head -> ny = in[head -> ed];
        head -> yy = -1;
        return;
    }

    head -> daddy = NULL;
    head -> lchild = add_nodes(head, 0, head -> mid);
    head -> rchild = add_nodes(head, head -> mid + 1, n-1);

    // nn, yn, ny, yy
    //
    LL lnn = head -> lchild -> nn;
    LL lyn = head -> lchild -> yn;
    LL lny = head -> lchild -> ny;
    LL lyy = head -> lchild -> yy;

    LL rnn = head -> rchild -> nn;
    LL ryn = head -> rchild -> yn;
    LL rny = head -> rchild -> ny;
    LL ryy = head -> rchild -> yy;

    LL val, ans;

    //
    ans = 0;
    val = (lnn + rnn);
    ans = val > ans ? val : ans;
    val = (lnn + ryn) * (ryn >= 0);
    ans = val > ans ? val : ans;
    val = (lny + rnn) * (lny >= 0);
    ans = val > ans ? val : ans;
    head -> nn = ans;
    //
    ans = 0;
    val = (lyn + rnn) * (lyn >= 0);
    ans = val > ans ? val : ans;
    val = (lyn + ryn) * (lyn >= 0) * (ryn >= 0);
    ans = val > ans ? val : ans;
    val = (lyy + rnn) * (lyy >= 0);
    ans = val > ans ? val : ans;
    head -> yn = ans;
    // 
    ans = 0;
    val = (lnn + rny) * (rny >= 0);
    ans = val > ans ? val : ans;
    val = (lnn + ryy) * (ryy >= 0);
    ans = val > ans ? val : ans;
    val = (lny + rny) * (rny >= 0) * (lny >= 0);
    ans = val > ans ? val : ans;
    head -> ny = ans;
    // 
    ans = 0;
    val = (lyn + rny) * (lyn >= 0) * (rny >= 0);
    ans = val > ans ? val : ans;
    val = (lyn + ryy) * (ryy >= 0) * (lyn >= 0);
    ans = val > ans ? val : ans;
    val = (lyy + rny) * (rny >= 0) * (lyy >= 0);
    ans = val > ans ? val : ans;
    head -> yy = ans;
    //
    return;
}

node* stree::add_nodes(node* cur, int st, int ed){
    node* newnode = new node;

    newnode -> st = st;
    newnode -> ed = ed;
    int mid = (st + ed) / 2;
    newnode -> mid = mid;

    if(st == ed){
        newnode -> daddy = cur;
        newnode -> lchild = NULL;
        newnode -> rchild = NULL;

        newnode -> nn = 0;
        newnode -> yn = -1;
        newnode -> ny = -1;
        newnode -> yy = in[st];
        //printf("st:%d, ed:%d, nn:%lld, yn:%lld, ny:%lld, yy:%lld\n", newnode->st, newnode->ed, newnode->nn, newnode->yn, newnode->ny, newnode->yy);
        return newnode;
    }
    else if(st + 1 == ed){
        newnode -> daddy = cur;
        newnode -> lchild = add_nodes(newnode, st, st);
        newnode -> rchild = add_nodes(newnode, ed, ed);

        newnode -> nn = 0;
        newnode -> yn = in[st];
        newnode -> ny = in[ed];
        newnode -> yy = -1;
        //printf("st:%d, ed:%d, nn:%lld, yn:%lld, ny:%lld, yy:%lld\n", newnode->st, newnode->ed, newnode->nn, newnode->yn, newnode->ny, newnode->yy);
        return newnode;
    }

    newnode -> daddy = cur;
    newnode -> lchild = add_nodes(newnode, st, mid);
    newnode -> rchild = add_nodes(newnode, mid + 1, ed);

    //
    LL lnn = newnode -> lchild -> nn;
    LL lyn = newnode -> lchild -> yn;
    LL lny = newnode -> lchild -> ny;
    LL lyy = newnode -> lchild -> yy;

    LL rnn = newnode -> rchild -> nn;
    LL ryn = newnode -> rchild -> yn;
    LL rny = newnode -> rchild -> ny;
    LL ryy = newnode -> rchild -> yy;

    LL val, ans;

    //
    ans = 0;
    val = (lnn + rnn);
    ans = val > ans ? val : ans;
    val = (lnn + ryn) * (ryn >= 0);
    ans = val > ans ? val : ans;
    val = (lny + rnn) * (lny >= 0);
    ans = val > ans ? val : ans;
    newnode -> nn = ans;
    //
    ans = 0;
    val = (lyn + rnn) * (lyn >= 0);
    ans = val > ans ? val : ans;
    val = (lyn + ryn) * (lyn >= 0) * (ryn >= 0);
    ans = val > ans ? val : ans;
    val = (lyy + rnn) * (lyy >= 0);
    ans = val > ans ? val : ans;
    newnode -> yn = ans;
    // 
    ans = 0;
    val = (lnn + rny) * (rny >= 0);
    ans = val > ans ? val : ans;
    val = (lnn + ryy) * (ryy >= 0);
    ans = val > ans ? val : ans;
    val = (lny + rny) * (rny >= 0) * (lny >= 0);
    ans = val > ans ? val : ans;
    newnode -> ny = ans;
    // 
    ans = 0;
    val = (lyn + rny) * (lyn >= 0) * (rny >= 0);
    ans = val > ans ? val : ans;
    val = (lyn + ryy) * (ryy >= 0) * (lyn >= 0);
    ans = val > ans ? val : ans;
    val = (lyy + rny) * (rny >= 0) * (lyy >= 0);
    ans = val > ans ? val : ans;
    newnode -> yy = ans;
    //
    //printf("st:%d, ed:%d, nn:%lld, yn:%lld, ny:%lld, yy:%lld\n", newnode->st, newnode->ed, newnode->nn, newnode->yn, newnode->ny, newnode->yy);
    return newnode;
}

void stree::ask(node* cur, int st, int ed, LL &nn, LL &yn, LL &ny, LL &yy){
    //if(st < cur -> st) st = cur -> st;
    //if(ed > cur -> ed) ed = cur -> ed;
    //printf("%d %d\n", st, ed);

    if(cur -> st == st && cur -> ed == ed){
        nn = cur -> nn;
        ny = cur -> ny;
        yn = cur -> yn;
        yy = cur -> yy;
        return;
    }
    if(ed <= cur -> mid){
        ask(cur -> lchild, st, ed, nn, yn, ny, yy);
        return;
    }
    if(st > cur -> mid){
        ask(cur -> rchild, st, ed, nn, yn, ny, yy);
        return;
    }

    LL lnn;
    LL lyn;
    LL lny;
    LL lyy;
    ask(cur -> lchild, st, cur->mid, lnn, lyn, lny, lyy);

    LL rnn;
    LL ryn;
    LL rny;
    LL ryy;
    ask(cur -> rchild, (cur->mid)+1, ed, rnn, ryn, rny, ryy);

    LL val, ans;

    //
    ans = 0;
    val = (lnn + rnn);
    ans = val > ans ? val : ans;
    val = (lnn + ryn) * (ryn >= 0);
    ans = val > ans ? val : ans;
    val = (lny + rnn) * (lny >= 0);
    ans = val > ans ? val : ans;
    nn = ans;
    //
    ans = 0;
    val = (lyn + rnn) * (lyn >= 0);
    ans = val > ans ? val : ans;
    val = (lyn + ryn) * (lyn >= 0) * (ryn >= 0);
    ans = val > ans ? val : ans;
    val = (lyy + rnn) * (lyy >= 0);
    ans = val > ans ? val : ans;
    yn = ans;
    // 
    ans = 0;
    val = (lnn + rny) * (rny >= 0);
    ans = val > ans ? val : ans;
    val = (lnn + ryy) * (ryy >= 0);
    ans = val > ans ? val : ans;
    val = (lny + rny) * (rny >= 0) * (lny >= 0);
    ans = val > ans ? val : ans;
    ny = ans;
    // 
    ans = 0;
    val = (lyn + rny) * (lyn >= 0) * (rny >= 0);
    ans = val > ans ? val : ans;
    val = (lyn + ryy) * (ryy >= 0) * (lyn >= 0);
    ans = val > ans ? val : ans;
    val = (lyy + rny) * (rny >= 0) * (lyy >= 0);
    ans = val > ans ? val : ans;
    yy = ans;

    return;
}

void stree::update(node* cur, int pos, LL val){
    if(pos == cur -> st && pos == cur -> ed){
        in[pos] = val;
        cur -> yy = val;

        //printf("st:%d, ed:%d, nn:%lld, yn:%lld, ny:%lld, yy:%lld\n", cur->st, cur->ed, cur->nn, cur->yn, cur->ny, cur->yy);

        return;
    }
    if(pos == cur -> st && (cur -> st) + 1 == cur -> ed){
        cur -> lchild -> yy = val;
        in[pos] = val;
        cur -> yn = val;
        //cur -> yy = -1;

        //printf("st:%d, ed:%d, nn:%lld, yn:%lld, ny:%lld, yy:%lld\n", cur->st, cur->ed, cur->nn, cur->yn, cur->ny, cur->yy);

        return;
    }
    if(pos == cur -> ed && (cur -> st) + 1 == cur -> ed){
        cur -> rchild -> yy = val;
        in[pos] = val;
        cur -> ny = val;
        //cur -> yy = -1;

        //printf("st:%d, ed:%d, nn:%lld, yn:%lld, ny:%lld, yy:%lld\n", cur->st, cur->ed, cur->nn, cur->yn, cur->ny, cur->yy);

        return;
    }

    if(pos <= cur->mid) update(cur->lchild, pos, val);
    else update(cur->rchild, pos, val);

    //
    LL lnn = cur -> lchild -> nn;
    LL lyn = cur -> lchild -> yn;
    LL lny = cur -> lchild -> ny;
    LL lyy = cur -> lchild -> yy;

    LL rnn = cur -> rchild -> nn;
    LL ryn = cur -> rchild -> yn;
    LL rny = cur -> rchild -> ny;
    LL ryy = cur -> rchild -> yy;

    LL tmp, ans;

    //
    ans = 0;
    tmp = (lnn + rnn);
    ans = tmp > ans ? tmp : ans;
    tmp = (lnn + ryn) * (ryn >= 0);
    ans = tmp > ans ? tmp : ans;
    tmp = (lny + rnn) * (lny >= 0);
    ans = tmp > ans ? tmp : ans;
    cur -> nn = ans;
    //
    ans = 0;
    tmp = (lyn + rnn) * (lyn >= 0);
    ans = tmp > ans ? tmp : ans;
    tmp = (lyn + ryn) * (lyn >= 0) * (ryn >= 0);
    ans = tmp > ans ? tmp : ans;
    tmp = (lyy + rnn) * (lyy >= 0);
    ans = tmp > ans ? tmp : ans;
    cur -> yn = ans;
    // 
    ans = 0;
    tmp = (lnn + rny) * (rny >= 0);
    ans = tmp > ans ? tmp : ans;
    tmp = (lnn + ryy) * (ryy >= 0);
    ans = tmp > ans ? tmp : ans;
    tmp = (lny + rny) * (rny >= 0) * (lny >= 0);
    ans = tmp > ans ? tmp : ans;
    cur -> ny = ans;
    // 
    ans = 0;
    tmp = (lyn + rny) * (lyn >= 0) * (rny >= 0);
    ans = tmp > ans ? tmp : ans;
    tmp = (lyn + ryy) * (ryy >= 0) * (lyn >= 0);
    ans = tmp > ans ? tmp : ans;
    tmp = (lyy + rny) * (rny >= 0) * (lyy >= 0);
    ans = tmp > ans ? tmp : ans;
    cur -> yy = ans;
    //
    //printf("st:%d, ed:%d, nn:%lld, yn:%lld, ny:%lld, yy:%lld\n", cur->st, cur->ed, cur->nn, cur->yn, cur->ny, cur->yy);

    return;
}

int main(){
    int m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%lld", &in[i]);
    
    stree tree;
    tree.btree();
    //printf("built!---------------\n");

    while(m--){
        int task;
        scanf("%d", &task);
        if(!task){
            //update
            int ind;
            LL val;
            scanf("%d%lld", &ind, &val);
            tree.update(tree.head, ind, val);
            //printf("update---------------\n");
        }
        else{
            LL nn, yn, ny, yy;
            int st, ed;

            //printf("---------------------\n");
            scanf("%d%d", &st, &ed);
            tree.ask(tree.head, st, ed, nn, yn, ny, yy);

            LL ans = 0;
            ans = ans > nn ? ans : nn;
            ans = ans > yn ? ans : yn;
            ans = ans > ny ? ans : ny;
            ans = ans > yy ? ans : yy;

            printf("%lld\n", ans);
            //printf("---------------------\n");
        }
    }
}