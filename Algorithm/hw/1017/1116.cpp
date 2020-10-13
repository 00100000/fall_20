#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    priority_queue<int> a;

    while(n--){
        int in;
        scanf("%d", &in);
        a.push(in);
    }

    long long int ans = 0;
    while(a.top() > 0){
        int big = a.top();
        a.pop();
        int small = a.top();
        a.pop();

        if(big == small){
            a.push(0);
            a.push(0);
        }
        else if(small == 0){
            a.push(0);
            a.push(0);
            ans += big;
        }
        else{
            int diff = big - small;
            ans += diff;
            a.push(0);
            a.push(diff);
        }
    }
    printf("%lld\n", ans);
}