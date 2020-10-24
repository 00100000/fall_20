#include <cstdio>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

int n;

typedef struct node_
{
    int x;
    int y;
    int z;
} node;

vector<node> in;
int xsort[1000005];
int ysort[1000005];
int zsort[1000005];

int cnt[1000005][7];  //x, y, z, xy, yz, xz, xyz

int compx (const void *a, const void *b ){
    int c = *(int *)a;
    int d = *(int *)b;
    LL tmpc = 0, tmpd = 0;
    tmpc |= in[c].x;
    tmpd |= in[d].x;
    tmpc <<= 20;
    tmpd <<= 20;
    tmpc |= in[c].y;
    tmpd |= in[d].y;
    tmpc <<= 20;
    tmpd <<= 20;
    tmpc |= in[c].z;
    tmpd |= in[d].z;
    if(tmpc < tmpd) return -1;
    else if(tmpc > tmpd) return 1;
    return 0;
}

int compy (const void *a, const void *b ){
    int c = *(int *)a;
    int d = *(int *)b;
    LL tmpc = 0, tmpd = 0;
    tmpc |= in[c].y;
    tmpd |= in[d].y;
    tmpc <<= 20;
    tmpd <<= 20;
    tmpc |= in[c].z;
    tmpd |= in[d].z;
    if(tmpc < tmpd) return -1;
    else if(tmpc > tmpd) return 1;
    return 0;
}

int compz (const void *a, const void *b ){
    int c = *(int *)a;
    int d = *(int *)b;
    LL tmpc = 0, tmpd = 0;
    tmpc |= in[c].z;
    tmpd |= in[d].z;
    tmpc <<= 20;
    tmpd <<= 20;
    tmpc |= in[c].x;
    tmpd |= in[d].x;
    if(tmpc < tmpd) return -1;
    else if(tmpc > tmpd) return 1;
    return 0;
}

int main(){
    scanf("%d", &n);
    in.resize(n);
    
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
    int nX = in[xsort[0]].x, cntX = 1;
    int nY = in[xsort[0]].y, cntY = 1;
    int nZ = in[xsort[0]].z, cntZ = 1;
    for(int i = 1; i < n; i++){
        if(in[xsort[i]].x != nX){
            for(int j = 1; j <= cntZ; j++) cnt[xsort[i - j]][6] = cntZ;
            for(int j = 1; j <= cntY; j++) cnt[xsort[i - j]][3] = cntY;
            for(int j = 1; j <= cntX; j++) cnt[xsort[i - j]][0] = cntX;
            nX = in[xsort[i]].x, cntX = 1;
            nY = in[xsort[i]].y, cntY = 1;
            nZ = in[xsort[i]].z, cntZ = 1;
        }
        else if(in[xsort[i]].y != nY){
            for(int j = 1; j <= cntZ; j++) cnt[xsort[i - j]][6] = cntZ;
            for(int j = 1; j <= cntY; j++) cnt[xsort[i - j]][3] = cntY;
            nY = in[xsort[i]].y, cntY = 1;
            nZ = in[xsort[i]].z, cntZ = 1;
            cntX ++;
        }
        else if(in[xsort[i]].z != nZ){
            for(int j = 1; j <= cntZ; j++) cnt[xsort[i - j]][6] = cntZ;
            nZ = in[xsort[i]].z, cntZ = 1;
            cntX ++;
            cntY ++;
        } 
        else{
            cntX ++;
            cntY ++;
            cntZ ++;
        }
    }
    for(int j = 1; j <= cntZ; j++) cnt[xsort[n - j]][6] = cntZ;
    for(int j = 1; j <= cntY; j++) cnt[xsort[n - j]][3] = cntY;
    for(int j = 1; j <= cntX; j++) cnt[xsort[n - j]][0] = cntX;
    /*
    printf("\n");
    for(int i = 0; i < n; i ++){
        printf("%d %d %d\n", cnt[i][0], cnt[i][3], cnt[i][6]);
    }
    */
    nY = in[ysort[0]].y, cntY = 1;
    nZ = in[ysort[0]].z, cntZ = 1;
    for(int i = 1; i < n; i++){
        if(in[ysort[i]].y != nY){
            for(int j = 1; j <= cntZ; j++) cnt[ysort[i - j]][4] = cntZ;
            for(int j = 1; j <= cntY; j++) cnt[ysort[i - j]][1] = cntY;
            nY = in[ysort[i]].y, cntY = 1;
            nZ = in[ysort[i]].z, cntZ = 1;
        }
        else if(in[ysort[i]].z != nZ){
            for(int j = 1; j <= cntZ; j++) cnt[ysort[i - j]][4] = cntZ;
            nZ = in[ysort[i]].z, cntZ = 1;
            cntY ++;
        } 
        else{
            cntY ++;
            cntZ ++;
        }
    }
    for(int j = 1; j <= cntZ; j++) cnt[ysort[n - j]][4] = cntZ;
    for(int j = 1; j <= cntY; j++) cnt[ysort[n - j]][1] = cntY;
    /*
    printf("\n");
    for(int i = 0; i < n; i ++){
        printf("%d %d\n", cnt[i][1], cnt[i][4]);
    }
    */
    nZ = in[zsort[0]].z, cntZ = 1;
    nX = in[zsort[0]].x, cntX = 1;
    for(int i = 1; i < n; i++){
        if(in[zsort[i]].z != nZ){
            for(int j = 1; j <= cntX; j++) cnt[zsort[i - j]][5] = cntX;
            for(int j = 1; j <= cntZ; j++) cnt[zsort[i - j]][2] = cntZ;
            nZ = in[zsort[i]].z, cntZ = 1;
            nX = in[zsort[i]].x, cntX = 1;
        }
        else if(in[zsort[i]].x != nX){
            for(int j = 1; j <= cntX; j++) cnt[zsort[i - j]][5] = cntX;
            nX = in[zsort[i]].x, cntX = 1;
            cntZ ++;
        } 
        else{
            cntZ ++;
            cntX ++;
        }
    }
    for(int j = 1; j <= cntX; j++) cnt[zsort[n - j]][5] = cntX;
    for(int j = 1; j <= cntZ; j++) cnt[zsort[n - j]][2] = cntZ;
    /*
    printf("\n");
    for(int i = 0; i < n; i ++){
        printf("%d %d\n", cnt[i][2], cnt[i][5]);
    }
    */
    printf("%d", n - cnt[0][0] - cnt[0][1] - cnt[0][2] + cnt[0][3] + cnt[0][4] + cnt[0][5] - cnt[0][6]);
    for(int i = 1; i < n; i++){
        printf(" %d", n - cnt[i][0] - cnt[i][1] - cnt[i][2] + cnt[i][3] + cnt[i][4] + cnt[i][5] - cnt[i][6]);
    }
    printf("\n");
}