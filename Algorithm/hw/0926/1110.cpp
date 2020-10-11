#include <cstdio>
#include <iostream>
#include <vector>
#define mod 1000000007
#define LL long long int
using namespace std;

LL md(LL in){
    return in%mod;
}

vector<LL> solve(vector<LL> x, LL n) {
    //printf("%d\n", n);
    if(n == 0){
        //printf("0");
        vector<LL> re;
        re.push_back(1);
        re.push_back(0);
        return re;
    }
    else if(n == 1){
        //printf("1");
        //printf("%d %d\n", x[0], x[1]);
        return x;
    }
    else {
        vector<LL> t = solve(x, n/2);
        vector<LL> re;
        //printf("4");
        re.push_back(md(md(t[0]*t[0]) - md(t[1]*t[1])));
        re.push_back(md(2*t[0]*t[1]));

        if(n%2){
            //printf("3");
            LL a = md(md(x[0]*re[0]) - md(x[1]*re[1]));
            LL b = md(md(x[1]*re[0]) + md(x[0]*re[1]));
            re[0] = a;
            re[1] = b;
        }
        //printf("%d %d\n", re[0], re[1]);
        return re;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        LL a, b, n;
        cin >> a >> b >> n;  // (a + bi)^n
        vector<LL> in;
        in.push_back(a);
        in.push_back(b);
        vector<LL> ans = solve(in, n);
        //printf("\n");
        cout << md(ans[0]+mod) << ' ' << md(ans[1]+mod) << '\n';
    }
    return 0;
}