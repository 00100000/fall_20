#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

typedef struct node_
{
    int x;
    int y;
    int z;
} node;

vector<node> in;
vector<int> done;
int xsort[1000005];
int ysort[1000005];
int zsort[1000005];

int compx (const void *a, const void *b ){
    int c = *(int *)a;
    int d = *(int *)b;
    if(in[c].x < in[d].x) return -1;
    else if(in[c].x > in[d].x) return 1;
    return 0;
}

int compy (const void *a, const void *b ){
    int c = *(int *)a;
    int d = *(int *)b;
    if(in[c].y < in[d].y) return -1;
    else if(in[c].y > in[d].y) return 1;
    return 0;
}

int compz (const void *a, const void *b ){
    int c = *(int *)a;
    int d = *(int *)b;
    if(in[c].z < in[d].z) return -1;
    else if(in[c].z > in[d].z) return 1;
    return 0;
}

int searchx(int target){
    int st = 0, ed = n-1;
    while(1){
        //printf("st:%d ed:%d\n", st, ed);
        if(st == ed) return st;
        int mid = (st + ed) / 2;
        if(in[xsort[mid]].x == target) return mid;
        else if(in[xsort[mid]].x > target) ed = mid - 1;
        else st = mid + 1;
    }
    return 0;
}

int searchy(int target){
    int st = 0, ed = n-1;
    while(1){
        //printf("st:%d ed:%d\n", st, ed);
        if(st == ed) return st;
        int mid = (st + ed) / 2;
        if(in[ysort[mid]].y == target) return mid;
        else if(in[ysort[mid]].y > target) ed = mid - 1;
        else st = mid + 1;
    }
    return 0;
}

int searchz(int target){
    int st = 0, ed = n-1;
    while(1){
        //printf("st:%d ed:%d\n", st, ed);
        if(st == ed) return st;
        int mid = (st + ed) / 2;
        if(in[zsort[mid]].z == target) return mid;
        else if(in[zsort[mid]].z > target) ed = mid - 1;
        else st = mid + 1;
    }
    return 0;
}

int doit(int i, int ans){
    int pos = searchy(in[i].y);
    //printf("ypos = %d\n", pos);
    int ysame = 0;
    int xsame = 0;
    //if(in[ysort[pos]].x == in[i].x) xsame ++;
    for(int j = pos; j >= 0 && in[ysort[j]].y == in[i].y; j--){
        //printf("%d ", j);
        ysame ++;
        if(in[ysort[j]].x == in[i].x) xsame ++;
    }
    for(int j = pos + 1; j < n && in[ysort[j]].y == in[i].y; j++){
        ysame ++;
        if(in[ysort[j]].x == in[i].x) xsame ++;
    }
    //printf("total y: %d\n", ysame);
    xsame = ans - xsame;
    //printf("x but not y: %d\n", xsame);
    ans = ysame + xsame;
    //printf("%d\n", ans);

    pos = searchz(in[i].z);
    xsame = 0;
    int zsame = 0;
    for(int j = pos; j >= 0 && in[zsort[j]].z == in[i].z; j--){
        //printf("%d ", j);
        zsame ++;
        if(in[zsort[j]].x == in[i].x) xsame ++;
        else if(in[zsort[j]].y == in[i].y) xsame ++;
    }
    for(int j = pos + 1; j < n && in[zsort[j]].z == in[i].z; j++){
        zsame ++;
        if(in[zsort[j]].x == in[i].x) xsame ++;
        else if(in[zsort[j]].y == in[i].y) xsame ++;
    }
    xsame = ans - xsame;
    ans = n - zsame - xsame;
    return ans;
}

int main(){
    scanf("%d", &n);
    in.resize(n);
    done.resize(n, -1);
    
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &in[i].x, &in[i].y, &in[i].z);
        xsort[i] = i;
        ysort[i] = i;
        zsort[i] = i;
    }
    qsort(xsort, n, sizeof(int), compx);
    qsort(ysort, n, sizeof(int), compy);
    qsort(zsort, n, sizeof(int), compz);
    /*
    printf("\n");
    for(int i = 0; i < n; i ++){
        printf("%d %d %d\n", xsort[i], ysort[i], zsort[i]);
    }
    */
    //printf("%d\n", searchx(1));
    for(int i = 0; i < n; i++){
        //printf("---------------------\n");
        //printf("case %d\n", i);
        if(done[i] >= 0){
            printf(" %d", done[i]);
            continue;
        }

        int ans = 0;

        int pos = searchx(in[i].x);
        int st, ed;
        int j;
        for(j = pos; j >= 0 && in[xsort[j]].x == in[i].x; j--) ans ++;
        st = j + 1;
        for(j = pos + 1; j < n && in[xsort[j]].x == in[i].x; j++) ans ++;
        ed = j - 1;
        //printf("total x: %d\n", ans);
        for(j = st; j <= ed; j++){
            done[xsort[j]] = doit(xsort[j], ans);
        }
        
        if(!i) printf("%d", done[i]);
        else printf(" %d", done[i]);
    }
    printf("\n");
}