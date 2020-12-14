#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node_{
    int v;
    struct node_* next;
}node;
node adja[100005];
node Tadja[100005];

int f[100005];
int visi[100005];
int Tvisi[100005];
vector<int> Tpri;
priority_queue<int> ans;
int tim;
int cnt;

void add_edge(int u, int  v){
    if(u == v) return;
    //
    node* cur = &adja[u];
    while(cur -> next && cur -> next -> v < v){
        cur = cur -> next;
    }
    node* newnode = new node;
    newnode -> v = v;
    newnode -> next = cur -> next;
    cur -> next = newnode;
    //
    cur = &Tadja[v];
    while(cur -> next && cur -> next -> v < v){
        cur = cur -> next;
    }
    node* newnode1 = new node;
    newnode1 -> v = u;
    newnode1 -> next = cur -> next;
    cur -> next = newnode1;
}

bool cmp(const int &a, const int &b){
    return f[a] > f[b];
}

void dfs(int in){
    tim ++;
    visi[in] = 1;
    
    node* cur = &adja[in];
    while(cur -> next){
        cur = cur -> next;
        if(!visi[cur -> v]) dfs(cur -> v);
    }
    tim ++;
    f[in] = tim;
}

void Tdfs(int in){
    cnt ++;
    Tvisi[in] = 1;

    node* cur = &Tadja[in];
    while(cur -> next){
        cur = cur -> next;
        if(!Tvisi[cur -> v]) Tdfs(cur -> v);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    //
    tim = 0;
    for(int i = 0; i < n; i++){
        if(!visi[i]){
            dfs(i);
        }
    }
    //
    Tpri.resize(n);
    for(int i = 0; i < n; i++) Tpri[i] = i;
    sort(Tpri.begin(), Tpri.end(), cmp);
    for(int i = 0; i < n; i++){
        if(!Tvisi[Tpri[i]]){
            cnt = 0;
            Tdfs(Tpri[i]);
            ans.push(cnt);
        }
    }
    //
    ans.pop();
    if(ans.empty()) printf("0\n");
    else printf("%d\n", ans.top());
}