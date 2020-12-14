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
    /*
    for(int i = 0; i < n; i++){
        node* cur = &adja[i];
        printf("%d: ", i);
        while(cur -> next){
            cur = cur -> next;
            printf("%d ", cur -> v);
        }
        printf("\n");
    }
    */
    
    // Dijkstra*3
    LL path[3][3] = {{INF, INF, INF}, {INF, INF, INF}, {INF, INF, INF}};
    for(int i = 0; i < 3; i++){
        priority_queue<int, vector<int>, cmp> q;
        int s[10005] = {0};
        for(int j = 0; j < n; j++){
            d[j] = INF;
            //q.push(j);
        }
        d[check[i]] = 0;
        q.push(check[i]);
        s[check[i]] = 1;
        //for(int j = 0; j < n; j++)printf("%d ", d[j]);
        //printf("case1\n\n");
        //printf("node: %d\n", check[i]);
        while(!q.empty()){
            int u = q.top();

            //printf("%d\n", u);
            //for(int j = 0; j < n; j++)printf("%lld ", d[j]);
            //printf("\n");
            //for(int j = 0; j < n; j++)printf("%d ", s[j]);
            //printf("\n\n");

            q.pop();
            node* cur = &adja[u];
            while(cur -> next){
                cur = cur -> next;
                //printf("%d %d\n", d[cur -> v], d[u] + cur -> w);
                if(d[cur -> v] > d[u] + cur -> w){
                    d[cur -> v] = d[u] + cur -> w;
                    //printf("%d ", cur->v);
                    if(!s[cur->v]){
                        q.push(cur->v);
                        s[cur->v] = 1;
                        //printf("push");
                    }
                    //printf("\n");
                } 
                //printf("relax: %d %d\n", u, cur -> v);
            }
        }
        //for(int j = 0; j < n; j++)printf("%d ", d[j]);
        //printf("\n\n");
        path[i][0] = d[check[0]];
        path[i][1] = d[check[1]];
        path[i][2] = d[check[2]];
    }
    LL ans[2];
    ans[0] = path[0][1] + path[1][2] + path[2][0];
    ans[1] = path[1][0] + path[2][1] + path[0][2];

    if((path[0][1] >= INF || path[1][2] >= INF || path[2][0] >= INF) 
    && (path[1][0] >= INF || path[2][1] >= INF || path[0][2] >= INF)){
        printf("-1\n");
    }
    else if(path[0][1] >= INF || path[1][2] >= INF || path[2][0] >= INF){
        printf("%lld\n", ans[1]);
    }
    else if(path[1][0] >= INF || path[2][1] >= INF || path[0][2] >= INF){
        printf("lld\n", ans[0]);
    }
    else printf("%lld\n", ans[0] < ans[1] ? ans[0] : ans[1]);
}