#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    while(n--){
        int a;
        scanf("%d", &a);
        vector<int> cnt;
        cnt.resize(2*a+2);
        int max = 0;
        int type = 0;
        for(int i = 0; i < a; i++){
            int in;
            scanf("%d", &in);
            if(cnt[in] == 0) type++;
            cnt[in]++;
            if(cnt[in] > max) max = cnt[in];
        }
        int ans;
        if(max >= type+1) ans = type;
        if(max == type) ans = type - 1;
        if(max < type) ans = max;
        printf("%d\n", ans);
    }
}

