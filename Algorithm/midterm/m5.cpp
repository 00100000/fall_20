#include <cstdio>
#include <cstdlib>
using namespace std;

int in[1005];
int dp[200005];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
        in[i] *= (n-i);
    }

    if(m <= n*k){
        printf("%d\n", (n * k) - m);
        return 0;
    }

    m -= k*n;

    for(int i = 0; i < n; i++){
        for(int j = 2*m; j >= in[i]; j--){
            if(in[i] + dp[ j-in[i] ] > dp[j]) dp[j] = in[i] + dp[ j-in[i] ];
        }
    }

    int ans = m; 
    for(int i = m; i <= 2*m; i++){
        if(ans > abs(dp[i] - m)) ans = abs(dp[i] - m);
    }
    printf("%d\n", ans);
}