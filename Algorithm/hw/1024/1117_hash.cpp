// TLE
#include <cstdio>
#include <unordered_map>
#include <vector>
#define LL long long int
using namespace std;

typedef struct node_
{
    int x;
    int y;
    int z;
} node;

int main(){
    int n;
    scanf("%d", &n);
    vector<node> in;
    in.resize(n);
    unordered_map<LL, int> x, y, z, xy, xz, yz, xyz;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &in[i].x, &in[i].y, &in[i].z);
        in[i].y <<= 21;
        in[i].z <<= 42;
        if(x.find(in[i].x) == x.end()) x[in[i].x] = 0;
        x[in[i].x] ++;
        if(y.find(in[i].y) == y.end()) y[in[i].y] = 0;
        y[in[i].y] ++;
        if(z.find(in[i].z) == z.end()) z[in[i].z] = 0;
        z[in[i].z] ++;
        if(xy.find(in[i].x + in[i].y) == xy.end()) xy[in[i].x + in[i].y] = 0;
        xy[in[i].x + in[i].y] ++;
        if(xz.find(in[i].x + in[i].z) == xz.end()) xz[in[i].x + in[i].z] = 0;
        xz[in[i].x + in[i].z] ++;
        if(yz.find(in[i].y + in[i].z) == yz.end()) yz[in[i].y + in[i].z] = 0;
        yz[in[i].y + in[i].z] ++;
        if(xyz.find(in[i].x + in[i].y + in[i].z) == xyz.end()) xyz[in[i].x + in[i].y + in[i].z] = 0;
        xyz[in[i].x + in[i].y + in[i].z] ++;
    }
    for(int i = 0; i < n; i++){
        int ans = n;
        ans -= x[in[i].x];
        ans -= y[in[i].y];
        ans -= z[in[i].z];
        ans += xy[in[i].x + in[i].y];
        ans += xz[in[i].x + in[i].z];
        ans += yz[in[i].y + in[i].z];
        ans -= xyz[in[i].x + in[i].y + in[i].z];
        if(!i) printf("%d", ans);
        else printf(" %d", ans);
    }
    printf("\n");
}