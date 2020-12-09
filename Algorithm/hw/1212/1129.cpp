#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int n, m, q;
int adja[5005][5005];
int split[5005][3]; // leader, #of nodes, done

void bfs();
void change(int a, int b);
int query(int a);

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int op[500005][3] = {0};
    scanf("%d%d%d", &n, &m, &q);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a == b) continue;
        if(a > b) swap(a, b);
        adja[a][b]++;
    }

    for(int i = 0; i < q; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        op[i][0] = a;
        op[i][1] = b;
        if(a >= 0){
            if(a > b) swap(a, b);
            if(adja[a][b]){
                adja[a][b]--;
                op[i][2] = 1;
            }
        }
    }

    //for(int i = 0; i < q; i++) printf("Q%d %d %d %d\n", i, op[i][0], op[i][1], op[i][2]);

    bfs();
    stack<int> ans;

    for(int i = q-1; i >= 0; i--){
        if(op[i][0] >= 0){
            if(op[i][2]){
                //printf("Q%d\n", i);
                change(op[i][0], op[i][1]);
            }
        }
        else{
            //printf("Q%d\n", i);
            ans.push(query(op[i][1]));
        }
    }

    while(!ans.empty()){
        printf("%d\n", ans.top());
        ans.pop();
    }
}

void bfs(){
    int next = 0;
    while(next < n){
        if(split[next][2]) next++;
        else{
            queue<int> q;
            q.push(next);
            split[next][0] = next;
            split[next][2] = 1;
            int cnt = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int i = 0; i < n; i++){
                    if(!split[i][2] && (adja[cur][i] || adja[i][cur])){
                        split[i][0] = next;
                        split[i][2] = 1;
                        cnt ++;
                        q.push(i);
                    }
                }
            }
            split[next][1] = cnt;
        }
    }
}

void change(int a, int b){
    //printf("%d %d\n", a, b);
    while(split[a][0] != a){
        a = split[a][0];
    }
    while(split[b][0] != b){
        b = split[b][0];
    }
    //printf("%d %d\n", a, b);
    if(a != b){
        split[b][0] = a;
        split[a][1] += split[b][1];
    }
}

int query(int a){
    //for(int i = 0; i < n; i++)printf("%d: lead_%d num_%d done_%d\n", i, split[i][0], split[i][1], split[i][2]);
    while(split[a][0] != a){
        a = split[a][0];
    }
    return split[a][1];
}