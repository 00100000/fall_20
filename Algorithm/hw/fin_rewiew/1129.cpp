#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int n, m, q;
int adja[5005][5005];
int op[500005][3]; // i, j, success
int pre[5005][2];
int visit[5005];

void swap(int &a, int &b){int t = a; a = b; b = t;}
void bfs();
void update(int u, int v);
int query(int id);

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if(u > v) swap(u, v);
        adja[u][v] ++;
    }
    for(int i = 0; i < q; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if(u > v) swap(u, v);
        if(u > 0 && adja[u][v]){
            adja[u][v] --;
            op[i][2] = 1;
        }
        op[i][0] = u;
        op[i][1] = v;
    }
    bfs();
    stack<int> s;
    for(int i = q-1; i >= 0; i--){
        if(op[i][0] < 0) s.push( query(op[i][1]) );
        else if(op[i][2]) update(op[i][0], op[i][1]);
    }
    while(!s.empty()){
        printf("%d\n", s.top());
        s.pop();
    }
}

void bfs(){
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            int cnt = 1;
        }
    }
}

void update(int u, int v){
    while(pre[u][0] != u) u = pre[u][0];
    while(pre[v][0] != v) v = pre[v][0];
    if(u != v){
        pre[u][1] += pre[v][1];
        pre[v][0] = u;
    }
}

int query(int id){
    while(pre[id][0] != id) id = pre[id][0];
    return pre[id][1];
}