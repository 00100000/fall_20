#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define t(k) ((k) + 2)
#define p(k) ((k) + n + 2)
#define rt(k) ((k) - 2)
#define tp(k) ((k) - n - 2)
#define INF 1e9

int n, m, k;
int node;
int G[2005][2005]; //s:0, t:1, tool k: k+2, product k: n + 2 + k




int bfs(){
    //printf("bfs\n");
    vector<int> visit;
    vector<int> path;
    visit.resize(node);
    path.resize(node);

    queue<int> q;
    q.push(0);
    visit[0] = 1;
    //q.push(u);
    //visit[u] = 1;
    int done = 0;
    while(!q.empty()){
        //printf("bfs\n");
        int now = q.front();
        q.pop();
        for(int i = 0; i < node; i++){
            if(G[now][i] && !visit[i]){
                path[i] = now;
                visit[i] = 1;
                if(i == 1){
                    done = 1;
                    break;
                }
                q.push(i);
            }
        }
    }
    if(!done) return 0;

    //for(int i = 0; i < node; i++) printf("%d ", path[i]);
    //printf("\n");
    //for(int i = 0; i < node; i++) printf("%d ", visit[i]);
    //printf("\n");

    int tmp = 1;
    int min = INF;
    while(tmp != 0){
        if(G[path[tmp]][tmp] < min) min = G[path[tmp]][tmp];
        tmp = path[tmp];
    }
    tmp = 1;
    while(tmp != 0){
        G[path[tmp]][tmp] -= min;
        G[tmp][path[tmp]] += min;
        tmp = path[tmp];
    }
    return 1;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    node = n+m+2;
    for(int i = 0; i < n; i++){
        //scanf("%d", &G[0][t(i)]);
        G[0][t(i)] = 1;
    }
    for(int i = 0; i < m; i++){
        //scanf("%d", &G[p(i)][1]);
        //ans += G[p(i)][1];
        G[p(i)][1] = 1;
    } 
    int ans = 0;
    
    for(int i = 0; i < k; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if(G[t(u)][p(v)] || G[p(v)][t(u)]){}
        else{
            G[t(u)][p(v)] = 1;
            bfs();
            if(G[p(v)][t(u)]) ans ++;
        }
        //int ans = 0;
        //for(int i = 0; i < m; i++) ans += G[1][p(i)];
        printf("%d\n", ans);
    }
}