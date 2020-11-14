#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    char in[7005];
    scanf("%s", in);
    int dp[3][7005] = {0};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(in[i - 1] == in[n - j]){
                if(i > 1 && j > 1) dp[i%3][j] = dp[(i - 2)%3][j - 2] + 1;
                else dp[i%3][j] = 1;
            }
            else{
                dp[i%3][j] = dp[(i-1)%3][j] > dp[i%3][j-1] ? dp[(i-1)%3][j] : dp[i%3][j-1];
            }
        }
    printf("%d\n", dp[n%3][n]);
}