#include <cstdio>
#include <utility>
#define LL long long int
#define MOD 1000000007
using namespace std;

LL mod(LL in){
    if(in < 0) in += MOD;
    in %= MOD;
    return in;
}

pair<LL, LL> sqr(pair<LL, LL> x){
    pair<LL, LL> ans;
    LL tmp;
    tmp = mod(x.first*x.first) - mod(x.second*x.second);
    ans.first = mod(tmp);
    tmp = 2 * mod(x.first * x.second);
    ans.second = mod(tmp);
    return ans;
}

pair<LL, LL> mul(pair<LL, LL> x, pair<LL, LL>y){
    pair<LL, LL> ans;
    LL tmp;
    tmp = mod(x.first * y.first) - mod(x.second * y.second);
    ans.first = mod(tmp);
    tmp = mod(x.first * y.second) + mod(y.first * x.second);
    ans.second = mod(tmp);
    return ans;
}

pair<LL, LL> sol(pair<LL, LL> x, int n){
    if(n == 0){
        pair<LL, LL> ans;
        ans.first = 1;
        ans.second = 0;
        return ans;
    }
    if(n == 1){
        pair<LL, LL> ans;
        ans.first = x.first;
        ans.second = x.second;
        return ans;
    }
    if(n % 2){
        return mul(sqr(sol(x, n/2)), x);
    }
    else{
        return sqr(sol(x, n/2));
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        LL a, b;
        int n;
        scanf("%lld%lld%d", &a, &b, &n);
        
        pair<LL, LL> in;
        in.first = mod(a);
        in.second = mod(b);

        pair<LL, LL> ans = sol(in, n);
        printf("%lld %lld\n", ans.first, ans.second);
    }
    return 0;
}