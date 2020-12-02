#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector<int> res;
    vector<int> in;
    int n;
    scanf("%d", &n);
    res.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
        if(i == 0){
            res[i] = -1;
            continue;
        }
        int now = i - 1;
        int done = 0;
        while(now >= 0){
            if(in[now] > in[i]){
                res[i] = now;
                done = 1;
                break;
            }
            if(res[now] == -1){
                res[i] = -1;
                done = 1;
                break;
            }
            now = res[now];
        }
        if(!done) res[i] = -1;
    }

    printf("-1");
    for(int i = 1; i < n; i++) printf(" %d", res[i] == -1 ? -1 : in[res[i]]);
    printf("\n");
}