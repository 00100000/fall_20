#include <cstdio>
#include <stack>
using namespace std;

int n, m, q;
int adja[5005][5005];
int op[500005][3]; // i, j, success

void swap(int &a, int &b){int t = a; a = b; b = t;}
void bfs();
void update(int u, int v);
void query(int id);

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
    for(int i = q-1; i >= 0; i--)
}