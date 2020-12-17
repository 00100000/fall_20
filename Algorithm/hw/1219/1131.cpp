#include <cstdio>
#include <queue>
#include <vector>
#define INF (1000000000)
#define MxN (10005)
using namespace std;

struct node{
    int num;
    int d;
    bool operator<(const node &r)const{
        return this -> d > r.d;
    }
};

struct edge{
    int v;
    int w;
};

vector<edge> adja[MxN];
int d[MxN];

void dijkstra(int u){
    node st;
    st.num = u;
    st.d = 0;
    priority_queue<node> q;
    q.push(st);
    while(!q.empty()){
        int now = q.top().num;
        q.pop();
        int nedge = adja[now].size();
        for(int i = 0; i < nedge; i++){
            if(d[adja[now][i].v] > d[now] + adja[now][i].w){
                d[adja[now][i].v] = d[now] + adja[now][i].w;
                node tmp;
                tmp.num = adja[now][i].v;
                tmp.d = d[adja[now][i].v];
                q.push(tmp);
            }
        }
    }
}

int main(){
    int n, m, u, v, w;
    scanf("%d%d%d%d%d", &n, &m, &u, &v, &w);
    for(int i = 0; i < m; i++){
        int p, q, w;
        scanf("%d%d%d", &p, &q, &w);
        edge tmp;
        tmp.v = q;
        tmp.w = w;
        adja[p].push_back(tmp);
    }
    //
    long long int uv, uw;
    for(int i = 0; i < n; i++) d[i] = INF;
    d[u] = 0;
    dijkstra(u);
    uv = d[v];
    uw = d[w];
    //
    long long vu, vw;
    for(int i = 0; i < n; i++) d[i] = INF;
    d[v] = 0;
    dijkstra(v);
    vu = d[u];
    vw = d[w];
    //
    long long int wv, wu;
    for(int i = 0; i < n; i++) d[i] = INF;
    d[w] = 0;
    dijkstra(w);
    wv = d[v];
    wu = d[u];
    //
    long long ans = uv+vw+wu;
    long long tmp = vu+uw+wv;
    if(tmp < ans) ans = tmp;
    if(ans >= (long long)INF) printf("-1\n");
    else printf("%lld\n", ans);
}