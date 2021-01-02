#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define t(k) ((k) + 2)
#define p(k) ((k) + n + 2)

int n, m, k;
int node;
int G[2005][2005]; //s:0, t:1, tool k: k+2, product k: n + 2 + k

vector<vector<int> > adja;


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
        int l = adja[now].size();
        for(int i = 0; i < l; i++){
            if(G[now][adja[now][i]] && !visit[adja[now][i]]){
                path[adja[now][i]] = now;
                visit[adja[now][i]] = 1;
                if(adja[now][i] == 1){
                    done = 1;
                    break;
                }
                q.push(adja[now][i]);
            }
        }
    }
    if(!done) return 0;

    //for(int i = 0; i < node; i++) printf("%d ", path[i]);
    //printf("\n");
    //for(int i = 0; i < node; i++) printf("%d ", visit[i]);
    //printf("\n");

    int tmp = 1;
    while(tmp != 0){
        G[path[tmp]][tmp] -= 1;
        G[tmp][path[tmp]] += 1;
        tmp = path[tmp];
    }
    return 1;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    node = n+m+2;
    adja.resize(node);

    for(int i = 0; i < n; i++){
        G[0][t(i)] = 1;
        adja[0].push_back(t(i));
        adja[t(i)].push_back(0);
    }
    for(int i = 0; i < m; i++){
        G[p(i)][1] = 1;
        adja[1].push_back(p(i));
        adja[p(i)].push_back(1);
    } 
    int ans = 0;
    
    for(int i = 0; i < k; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if(G[t(u)][p(v)] || G[p(v)][t(u)]){}
        else{
            G[t(u)][p(v)] = 1;
            adja[t(u)].push_back(p(v));
            adja[p(v)].push_back(t(u));
            bfs();
            if(G[p(v)][t(u)]) ans ++;
        }
        printf("%d\n", ans);
    }
}