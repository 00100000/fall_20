#include <cstdio>
#include <cstring>
using namespace std;

int n;
int wlen[100005];

int solve();
int tryy(int l);
int total;

int main(){
    scanf("%d", &n);
    total = 0;

    char instr[100005];
    for(int i = 0;  i < n; i++){
        scanf("%s", instr);
        wlen[i] = strlen(instr) + 1;
        total += wlen[i];
    }
    // printf("owo\n");
    printf("%d\n", solve());
}

int solve(){
    int st = 1, ed = total;
    while(st < ed){
        int mid = (st + ed) / 2;
        if(tryy(mid)) ed = mid;
        else st = mid + 1;
    }
    return st;
}

int tryy(int l){
    // printf("%d\n", l);
    l++;
    int used = 0;
    for(int i = 0; i < 24; i++){
        int curlen = 0;
        while(curlen + wlen[used] <= l){
            curlen += wlen[used];
            used ++;
            if(used >= n) return 1;
        }
    }
    return 0;
}