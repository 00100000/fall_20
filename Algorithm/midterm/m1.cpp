#include <cstdio>
#include <cmath>
#define LD long double
using namespace std;

LD solve(int y, int b){
    LD st = 0, ed = __INT_MAX__;
    LD tar = (LD) y * log((LD) b);
    while(1){
        LD mid = (st + ed) / 2;
        LD tryy = (LD) mid * log((LD) mid);
        if(tar > tryy){
            if(tar - tryy < 0.000001) return mid;
            st = mid;
        }
        else{
            if(tryy - tar < 0.000001) return mid;
            ed = mid;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int y, b;
        scanf("%d%d", &y, &b);
        printf("%.8Lf\n", solve(y, b));
    }
}