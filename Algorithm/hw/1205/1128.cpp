#include <cstdio>
#include <vector>
using namespace std;

int n;

void build(int now, int st, int ed, vector<int>* tree, vector<int>* in);
int q(int tg, int qst, int qed, int st, int ed, vector<int>* tree);

int main(){
    vector<int> tree;
    vector<int> in;
    scanf("%d", &n);
    tree.resize(2*n);
    in.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    build(1, 0, n-1, &tree, &in);
}

void build(int now, int st, int ed, vector<int>* tree, vector<int>* in){
    if(st == ed){
        tree[now] = in[st];
        return;
    }
    else{
        int mid = (st + ed) / 2;
        build(now * 2, st, mid, tree, in);
        build(now * 2 + 1, mid + 1, ed, tree, in);
        tree[now] = tree[now*2] > tree[now*2+1] ? tree[now*2] : tree[now*2+1];
    }
}

int q(int tg, int qst, int qed, int st, int ed, vector<int>* tree, vector<int>* in){
    if()
}