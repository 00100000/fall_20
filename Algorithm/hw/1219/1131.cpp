// waaaaaaaaaa
#include <cstdio>
#include <queue>
#define INF 900000000000000
#define LL long long int
using namespace std;

typedef struct node_{
    int v;
    int w;
    struct node_* next;
}node;
node adja[10005];

LL d[10005];

void add_edge(int u, int  v, int w){
    node* cur = &adja[u];
    while(cur -> next && cur -> next -> v < v){
        cur = cur -> next;
    }
    node* newnode = new node;
    newnode -> v = v;
    newnode -> w = w;
    newnode -> next = cur -> next;
    cur -> next = newnode;
}

struct cmp
{
    bool operator()(int &a, int &b) const
    {
        return d[a] > d[b];
    }
};

int main(){
    int n, m;
    int check[3];
    scanf("%d%d%d%d%d", &n, &m, &check[0], &check[1], &check[2]);

    // input to adjacency list
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    
    
    // Dijkstra*3
    LL path[3][3] = {0};
    int yes[3][3][2] = {0};
    for(int i = 0; i < 3; i++){
        priority_queue<int, vector<int>, cmp> q;
        int s[10005] = {0};
        int pi[10005];

        for(int j = 0; j < n; j++){
            d[j] = INF;
        }
        d[check[i]] = 0;
        q.push(check[i]);
        s[check[i]] = 1;
        pi[check[i]] = check[i];
        
        while(!q.empty()){
            int u = q.top();

            q.pop();
            node* cur = &adja[u];
            while(cur -> next){
                cur = cur -> next;
                if((d[cur -> v] > d[u] + cur -> w)){
                    d[cur -> v] = d[u] + cur -> w;
                    pi[cur -> v] = u;
                    if(!s[cur->v]){
                        q.push(cur->v);
                        s[cur->v] = 1;
                    }
                } 
            }
        }
        //
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        //
        //printf("%d\n", check[i]);
        if(d[check[j]] < INF){
            path[i][j] = d[check[j]];
            yes[i][j][0] = 1;
            int cur = check[j];
            while(cur != pi[cur]){
                //printf("%d %d\n", cur, pi[cur]);
                if(cur == check[k]){
                    yes[i][j][1] = 1;
                    break;
                }
                cur = pi[cur];
            }
        }
        //printf("here\n");
        //
        if(d[check[k]] < INF){
            path[i][k] = d[check[k]];
            yes[i][k][0] = 1;
            int cur = check[k];
            while(cur != pi[cur]){
                //printf("%d %d\n", cur, pi[cur]);
                if(cur == check[j]){
                    yes[i][k][1] = 1;
                    break;
                }
                cur = pi[cur];
            }
        }
    }
    
    LL ans = -1;
    //ans = path[0][1] + path[1][2] + path[2][0];
    if(yes[0][1][0] && yes[1][2][0] && yes[2][0][0]){
        ans = path[0][1] + path[1][2] + path[2][0];
    }
    //ans = path[1][0] + path[2][1] + path[0][2];
    if(yes[1][0][0] && yes[2][1][0] && yes[0][2][0]){
        if(ans < 0 || ans > path[1][0] + path[2][1] + path[0][2])
            ans = path[1][0] + path[2][1] + path[0][2];
    }
    if(ans >= 0){
        if(yes[0][1][0] && yes[1][0][0] && yes[0][1][1]){
            if(ans > path[0][1] + path[1][0]) ans = path[0][1] + path[1][0];
        }
        if(yes[1][2][0] && yes[2][1][0] && yes[1][2][1]){
            if(ans > path[1][2] + path[2][1]) ans = path[1][2] + path[2][1];
        }
        if(yes[2][0][0] && yes[0][2][0] && yes[2][0][1]){
            if(ans > path[2][0] + path[0][2]) ans = path[2][0] + path[0][2];
        }
        if(yes[1][0][0] && yes[0][1][0] && yes[1][0][1]){
            if(ans > path[1][0] + path[0][1]) ans = path[1][0] + path[0][1];
        }
        if(yes[2][1][0] && yes[1][2][0] && yes[2][1][1]){
            if(ans > path[2][1] + path[1][2]) ans = path[2][1] + path[1][2];
        }
        if(yes[0][2][0] && yes[2][0][0] && yes[0][2][1]){
            if(ans > path[0][2] + path[2][0]) ans = path[0][2] + path[2][0];
        }
    }
    
    printf("%lld\n", ans);
}