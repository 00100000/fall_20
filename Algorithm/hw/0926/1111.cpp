#include <cstdio>
#include <vector>
#define LL long long int
using namespace std;

LL in[100005];
LL f[100005] = {0};
LL b[100005] = {0};
int n;

void solve(int st, int ed){
    if(st >= ed){
        return;
    }
    solve(st, (st+ed)/2);
    solve((st+ed)/2+1, ed);

    vector<LL> tmp;
    vector<LL> tmpf;
    vector<LL> tmpb;
    int size = ed - st + 1;
    tmp.resize(size);
    tmpf.resize(size);
    tmpb.resize(size);

    int fr = st, ba = (st+ed)/2+1;
    int cur = 0;
    LL unusedfr = ba - fr;
    LL usedba = 0;
    
    for(int i = 0; i <= ed - st; i++){
        if(fr > (st+ed)/2){
            while(ba <= ed){
                tmp[cur] = in[ba];
                tmpf[cur] = f[ba] + unusedfr;
                tmpb[cur] = b[ba];
                ba++;
                cur++;
            }   
            break;
        }
        if(ba > ed){
            while(fr <= (st+ed)/2){
                tmp[cur] = in[fr];
                tmpf[cur] = f[fr];
                tmpb[cur] = b[fr] + usedba;
                fr++;
                cur++;
            }
            break;
        }
        if(in[fr] <= in[ba]){
            tmp[cur] = in[fr];
            //lastnum = in[fr];
            unusedfr --;
            tmpf[cur] = f[fr];
            tmpb[cur] = b[fr] + usedba;
            fr++;
            cur++;
        }
        else{
            tmp[cur] = in[ba];
            //lastnum = in[ba];
            usedba++;
            tmpf[cur] = f[ba] + unusedfr;
            tmpb[cur] = b[ba];
            ba++;
            cur++;
        }
    }
    for(int i = st; i <= ed; i++){
        in[i] = tmp[i-st];
        f[i] = tmpf[i-st];
        b[i] = tmpb[i-st];
    }
    return;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &in[i]);
    }
    solve(0, n-1);
    LL ans = 0;
    for(int i = 0; i < n; i++){
        //printf("%d %d %d\n",in[i], f[i], b[i]);
        ans += f[i] * b[i];
    }
    printf("%lld\n", ans);
}