#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int a[1000005][2];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i][0]);
    }
    a[0][1] = -1;
    printf("-1");
    for(int i = 1; i < n; i++){
        int cur = i - 1;
        while(1){
            if(cur < 0){
                a[i][1] = -1;
                printf(" -1");
                break;
            }
            if(a[cur][0] > a[i][0]){
                a[i][1] = cur;
                printf(" %d", a[cur][0]);
                break;
            }
            cur = a[cur][1];
        }
    }
    printf("\n");
}