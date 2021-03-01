#include <cstdio>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#define LL long long int
using namespace std;

typedef struct assignment_{
    int d;
    int s;
    bool operator<(const assignment_& r)const{
        if(this->s != r.s) return this->s > r.s;
        else return this->d < r.d;
    }
}assignment;

bool dcmp(const assignment &a, const assignment &b){
    return a.d < b.d;
}

bool scmp(const assignment &a, const assignment &b){
    return a.s > b.s;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        vector<assignment> v;
        v.reserve(n);
        for(int i = 0; i < n; i++){
            assignment in;
            scanf("%d%d", &in.d, &in.s);
            v.push_back(in);
        }

        stable_sort(v.begin(), v.end(), scmp);
        stable_sort(v.begin(), v.end(), dcmp);

        //printf("\n");
        //for(int i = 0; i < n; i++) printf("%d %d\n", v[i].d, v[i].s);
        //printf("\n");

        priority_queue<assignment> pq;
        
        LL ans = v[0].s;
        int ok = 2;
        v[0].d = 1;
        pq.push(v[0]);
        for(int i = 1; i < n; i++){
            if(v[i].d < ok){
                assignment tmp = pq.top();
                if(tmp.s < v[i].s){
                    pq.pop();
                    ans -= tmp.s;
                    ans += v[i].s;
                    tmp.s = v[i].s;
                    pq.push(tmp);
                }
            }
            else{
                v[i].d = ok;
                ans += v[i].s;
                ok ++;
                pq.push(v[i]);
            }
        }
        printf("%lld\n", ans);
    }
}