#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    char in[505];
    int dp[505][505];
    while(t--){
        int a;
        scanf("%d", &a);
        scanf("%s", in);
        for(int i = 0; i < a; i++) dp[i][i] = 1;
        for(int i = 0; i < a-1; i++){
            if(in[i] == in[i+1]) dp[i][i+1] = 1;
            else dp[i][i+1] = 2;
        }
        for(int l = 3; l <= a; l++){
            for(int i = 0; i <= a - l; i++){
                int j = i + l - 1;
                if(in[i] == in[j]){
                    if(in[i] == in[i+1] || in[j] == in[j-1])
                        dp[i][j] = dp[i+1][j-1];
                    else{
                        if(l == 3){
                            dp[i][j] = 2;
                            continue;
                        }
                        int min = 1e9;
                        for(int k = i+1; k < j-1; k++){
                            if(in[i] == in[k] || in[i] == in[k+1]){
                                if(min > dp[i+1][k] + dp[k+1][j-1])
                                    min = dp[i+1][k] + dp[k+1][j-1];
                            }
                            else{
                                if(min > dp[i+1][k] + dp[k+1][j-1] + 1)
                                    min = dp[i+1][k] + dp[k+1][j-1] + 1;
                            }
                        }
                        dp[i][j] = min;
                        if(dp[i][j] > dp[i+1][j-1] + 1) dp[i][j] = dp[i+1][j-1] + 1;
                    }
                }
                else{
                    int min = 1e9;
                    for(int k = i; k < j; k++){
                        if(min > dp[i][k] + dp[k+1][j])
                            min = dp[i][k] + dp[k+1][j];
                    }
                    dp[i][j] = min;
                }
            }
        }
        /*
        printf("\n");
        for(int i = 0; i < a; i++){
            for(int j = 0; j + i < a; j++) printf("%d ", dp[j][j+i]);
            printf("\n");
        }
        printf("\n");
        */
        printf("%d\n", dp[0][a-1]);
    }
}