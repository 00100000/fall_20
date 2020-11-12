#include <cstdio>
#define LL long long
using namespace std;

typedef struct item_{
    int id;
    long long v;
}item;

item in[100005];
item tmp[100005];

LL l[100005];
LL r[100005];

void sort(int st, int ed){
    if(st >= ed) return;

    int mid = (st + ed) / 2;
    sort(st, mid);
    sort(mid + 1, ed);

    int lused = 0, lnum = mid - st + 1;
    int rused = 0, rnum = ed - mid;
    int index = st;
    while(lused < lnum && rused < rnum){
        if(in[st + lused].v <= in[mid + 1 + rused].v){
            tmp[index] = in[st + lused];
            r[tmp[index].id] += rused;
            lused ++;
            index ++;
        }
        else{
            tmp[index] = in[mid + 1 + rused];
            l[tmp[index].id] += lnum - lused;
            rused ++;
            index ++;
        }
    }
    //printf("%d %d\n", st, ed);
    //printf("r: %d, %d\n", rused, rnum);
    //printf("l: %d, %d\n", lused, lnum);
    while(lused < lnum){
        tmp[index] = in[st + lused];
        r[tmp[index].id] += rnum;
        lused ++;
        index ++;
    }
    while(rused < rnum){
        tmp[index] = in[mid + 1 + rused];
        rused ++;
        index ++;
    }
    //printf("%d %d %d\n", rused, lused, ed - st + 1);
    for(int i = st; i <= ed; i++)in[i] = tmp[i];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &in[i].v);
        in[i].id = i;
        //printf("%d %lld\n", in[i].id, in[i].v);
    }

    sort(0, n-1);

    LL ans = 0;
    for(int i = 0; i < n; i++){
        //printf("%lld %lld\n", l[i], r[i]);
        ans += l[i] * r[i];
    } 
    printf("%lld\n", ans);
    
}