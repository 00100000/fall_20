// tle version AC

#include <cstdio>
#include <queue>
#define INF 9000000000
#define LL long long int
using namespace std;

class heap{
public:
    int node[10005];
    int n;
    void build(int i);
    void update();
    int extract_min();
};

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
    LL path[3][3] = {{INF, INF, INF}, {INF, INF, INF}, {INF, INF, INF}};
    for(int i = 0; i < 3; i++){
        int s[10005] = {0};
        heap h;
        for(int j = 0; j < n; j++){
            d[j] = INF;
            h.node[j] = j;
        }
        h.build(check[i]);
        d[check[i]] = 0;
        s[check[i]] = 1;
        
        int done = 0;
        while(done < n){
            done ++;
            /*
            int u = -1;
            for(int j = 0; j < n; j++){
                if(s[j] == 1 && u < 0) u = j;
                else if(s[j] == 1 && d[j] < d[u]) u = j;
            }
            s[u] = 2;
            */

            node* cur = &adja[u];
            while(cur -> next){
                cur = cur -> next;
                if(d[cur -> v] > d[u] + cur -> w){
                    d[cur -> v] = d[u] + cur -> w;
                    if(s[cur->v] == 0){
                        s[cur->v] = 1;
                    }
                } 
            }
        }
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
        printf("%lld\n", ans[0]);
    }
    else printf("%lld\n", ans[0] < ans[1] ? ans[0] : ans[1]);
}

void heap::build(int i){
}

void heap::update(){
}

int extract_min(){
}