#include <cstdio>
#include <algorithm>
#include <vector>
#define LL long long int
using namespace std;

int n, k;
int in[1000005];


int tryy(int l){
    LL end = in[0] + l;
    int used = 0;
    for(int i = 0; i < k; i++){
        if(end >= in[n - 1]) return 1;
        if(i == k-1) break;
        while(end >= in[used]) used ++;
        end = in[used] + l;
    }
    return 0;
}

int find(){
    LL st = 0, ed = in[n-1] - in[0];
    while(st < ed){
        LL mid = (st + ed) / 2;
        if(tryy(mid)) ed = mid;
        else st = mid + 1;
    }
    return st;
}

int main(){
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    sort(&in[0], &in[n]);

    if(n <= k) printf("0\n");
    else if (in[0] == in[n-1]) printf("0\n");
    else printf("%d\n", find());
}