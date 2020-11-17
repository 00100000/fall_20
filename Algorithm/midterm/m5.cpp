#include <cstdio>
#include <vector>
#define LL long long int
using namespace std;

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<LL> in;
    in.resize(n);
    LL max = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        tmp *= n - i;
        //printf("' %d\n", tmp);
        in[i] = tmp;
        if(tmp > max) max = tmp;
    }
    //printf("max: %lld\n", max);
    m -= n * k; // still need
    printf("m: %d\n", m);
    if(m <= 0){
        printf("%d\n", n * k - m);
    }
    for(int i = 0; i < n; i++){
        //printf("%lld\n", in[i]);
         LL tmp = max;
         tmp -= in[i];
         in[i] = tmp;
         //printf("__%lld\n", in[i]);
    }

    LL dpmax = max * n - m;
    printf("dpmax = %lld\n", dpmax);
    vector<LL> dp;
    dp.resize(dpmax + 5);
    for(int i = 0; i < n; i++){
        for(int j = dpmax; j >= in[i]; j--){
            if(dp[j-in[i]] + in[i] <= j){
                if(dp[j-in[i]] + in[i] > dp[j]) dp[j] = dp[j-in[i]] + in[i];
            }
        }
    }
    printf("%lld\n", dpmax - dp[dpmax]);
}