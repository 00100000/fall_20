#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector< vector<int> > g, gT;
int f[100005];
int v[100005];
int vT[100005];
vector<int> pri;
int tim;
int cnt;


bool cmp(const int &a, const int &b) {return f[a] > f[b];}


void dfs(int in){
    tim ++;
    int l;
    l = g[in].size();
    for(int i = 0; i < l; i++){
        if(!v[g[in][i]]){
            v[g[in][i]] = 1;
            dfs(g[in][i]);
        }
    }
    tim ++;
    f[in] = tim;
}

void dfsT(int in){
    cnt ++;
    int l;
    l = gT[in].size();
    for(int i = 0; i < l; i++){
        if(!vT[gT[in][i]]){
            vT[gT[in][i]] = 1;
            dfsT(gT[in][i]);
        }
    }
}

int main(){
    // input
    scanf("%d%d", &n, &m);
    g.resize(n);
    gT.resize(n);
    int tmpu, tmpv;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &tmpu, &tmpv);
        g[tmpu].push_back(tmpv);
        gT[tmpv].push_back(tmpu);
    }
    
    // dfs1
    tim = 0;
    for(int i = 0; i < n; i++){
        if(!v[i]){
            v[i] = 1;
            dfs(i);
        }
    }

    // dfs2
    for(int i = 0; i < n; i++) pri.push_back(i);
    sort(pri.begin(), pri.end(), cmp);

    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        if(!vT[pri[i]]){
            cnt = 0;
            vT[pri[i]] = 1;
            dfsT(pri[i]);
            pq.push(cnt);
        }
    }
    
    // print
    pq.pop();
    if(pq.empty()) printf("0\n");
    else printf("%d\n", pq.top());
}