#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define LL long long
#define INF 1000000000

typedef struct node_{
    int to;
    int w;
    bool operator<(const struct node_& r)const{
        return this->w > r.w;
    }
}node;

int n, m;
vector< vector<node> > adja;
LL d[10005];
int visit[10005];

void dijkstra(int in){
    priority_queue<node> pq;
    node tmp;
    tmp.to = in;
    tmp.w = 0;

    d[in] = 0;
    pq.push(tmp);
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        if(!visit[tmp.to]){
            visit[tmp.to] = 1;
            int l = adja[tmp.to].size();
            for(int i = 0; i < l; i++){
                if(d[adja[tmp.to][i].to] > adja[tmp.to][i].w + d[tmp.to]){
                    d[adja[tmp.to][i].to] = adja[tmp.to][i].w + d[tmp.to];
                    node p;
                    p.to = adja[tmp.to][i].to;
                    p.w = d[adja[tmp.to][i].to];
                    pq.push(p);
                }
            }
        }
    }
}

int main(){
    // input
    int u, v, w;
    scanf("%d%d%d%d%d", &n, &m, &u, &v, &w);
    adja.resize(n);
    int x, y, weight;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &x, &y, &weight);
        node tmp;
        tmp.to = y;
        tmp.w = weight;
        adja[x].push_back(tmp);
    }
    // u
    LL uv, uw;
    for(int i = 0; i < n; i++){
        d[i] = INF;
        visit[i] = 0;
    }
    dijkstra(u);
    uv = d[v];
    uw = d[w];
    // v
    LL vu, vw;
    for(int i = 0; i < n; i++){
        d[i] = INF;
        visit[i] = 0;
    }
    dijkstra(v);
    vu = d[u];
    vw = d[w];
    // w
    LL wu, wv;
    for(int i = 0; i < n; i++){
        d[i] = INF;
        visit[i] = 0;
    }
    dijkstra(w);
    wu = d[u];
    wv = d[v];
    // print
    LL a1 = uv + vw + wu;
    LL a2 = vu + uw + wv;
    if(a1 >= INF && a2 >= INF) printf("-1\n");
    else printf("%lld\n", a1 < a2 ? a1 : a2);
}