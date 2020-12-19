#include <cstdio>
using namespace std;

typedef struct it_{
    int w;
    int v;
    int p;
}it;

int main(){
    int n, mxv, mxw;
    scanf("%d%d%d", &n, &mxw, &mxv);

    it item[505];
    int inw, inv, inp;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &inw, &inv, &inp);
        item[i].w = inw;
        item[i].v = inv;
        item[i].p = inp;
    }

    int dp[505][505];
    //for(int i = 0; i < mxw)
    for(int i = 0; i < n; i++)
        for(int j = mxw; j >= item[i].w; j--);
}