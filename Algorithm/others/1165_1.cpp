#include <cstdio>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int in[1048600];
    scanf("%d", &in[0]);
    int cut = 0;
    for(int i = 1; i < n; i++){
        scanf("%d", &in[i]);
        if(in[i] < in[i-1]) cut = i;
    }
    //printf("cut: %d\n", cut);
    while(m--){
        int target;
        scanf("%d", &target);
        int st = 0;
        int ed = n-1;
        int mid;
        while(1){
            //printf("st:%d ed:%d\n", st, ed);
            if(st >= ed){
                int pos = (st + cut + n) % n;
                if(in[pos] == target){
                    printf("%d\n", pos);
                    break;
                }
                printf("-1\n");
                break;
            }
            mid = (st + ed) / 2;
            int index = (mid + cut + n) % n;
            //printf("index: %d\n", index);
            if(in[index] == target){
                printf("%d\n", index);
                break;
            }
            if(in[index] > target) ed = mid - 1;
            if(in[index] < target) st = mid + 1;
        }
    }
}