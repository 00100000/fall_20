#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> in;

int tryy(int l){
    int used = 0;
    for(int i = 0; i < k; i++){
        int st = used, ed = n-1;
        int target = in[used] + l;
        //if(l < 10) printf("l: %d, t: %d\n",l, target);
        if(target >= in[n-1]) return 1;
        while(st < ed){
            int mid = (st + ed) / 2;
            if(in[mid] == target){
                st = mid;
                break;
            }
            else if(in[mid] < target) st = mid;
            else ed = target;
        }
        while(in[st] == in[st + 1] && st + 1 < n) st ++;
        used = st + 1;
        if(used >= n) return 1;
    }
    //printf("%d, no!\n", l);
    return 0;
}

int find(){
    int st = 0, ed = 0x7FFFFFFF;
    while(st < ed){
        //printf("%d, %d\n", st , ed);
        int mid = (st + ed) / 2;
        if(tryy(mid)) ed = mid;
        else st = mid + 1;
        //printf("\n");
    }
    return st;
}

int main(){
    scanf("%d%d", &n, &k);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    //for(int i = 0; i < n; i++) printf("%d ", in[i]);
    //printf("\n");
    printf("%d\n", find());
}