#include <cstdio>
#include <cmath>
#define LD long double
using namespace std;

LD solve(int y);

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int y;
        scanf("%d", &y);
        printf("%Lf\n", solve(y));
    }
}

LD solve(int y){
    LD st = 0, ed = 19;
    while(1){
        LD mid = (st + ed) / 2.0;
        LD val = mid * exp(mid);
        if(val <= y){
            if(y - val <= 0.000001) return mid;
            st = mid;
        }
        else{
            if(val - y <= 0.000001) return mid;
            ed = mid;
        }
    }
}