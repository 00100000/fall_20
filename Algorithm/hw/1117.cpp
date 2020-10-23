#include <vector>
#include <cstdio>
#include <algorithm>
#define LL long long int
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<LL> v;
    v.reserve(n);
    for(int i = 0; i < n; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        LL tmp = x;
        tmp <<= 20;
        tmp |= y;
        tmp <<= 20;
        tmp |= z;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
}