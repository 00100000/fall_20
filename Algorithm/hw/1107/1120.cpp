#include <cstdio>
#include <vector>
using namespace std;
int num[2][7005][2];

int find_max(int i, int j){
    int ans = num[(i-1)%2][j][0];
    if(num[(i-1)%2][j][1] > ans) ans = num[(i-1)%2][j][1];
    if(num[i%2][j-1][0] > ans) ans = num[i%2][j-1][0];
    if(num[i%2][j-1][1] > ans) ans = num[i%2][j-1][1];
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    char in[7005];
    scanf("%s", in);
    
    if(n==1){
        printf("1\n");
        return 0;
    }
    

    for(int i = 0; i <= n; i++){
        num[0][i][0] = 0;
        num[0][i][1] = 0;
    }
    num[1][0][0] = 0;
    num[1][0][1] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(in[i-1] == in[n-j]){
                //printf("%c\n", in[i]);
                num[i%2][j][0] = num[(i-1)%2][j-1][0] > num[(i-1)%2][j-1][1] ? num[(i-1)%2][j-1][0] : num[(i-1)%2][j-1][1];
                num[i%2][j][1] = (num[(i-1)%2][j-1][0] + 1) > num[(i-1)%2][j-1][1] ? (num[(i-1)%2][j-1][0] + 1) : num[(i-1)%2][j-1][1];
                //num[i%2][j][1] = num[(i-1)%2][j-1][0] + 1;
            }
            else{
                num[i%2][j][0] = num[(i-1)%2][j-1][0] > num[(i-1)%2][j-1][1] ? num[(i-1)%2][j-1][0] : num[(i-1)%2][j-1][1];
                num[i%2][j][1] = find_max(i, j);
            }
        }
    }

    printf("%d\n", num[n%2][n][0] > num[n%2][n][1] ? num[n%2][n][0] : num[n%2][n][1]);
}