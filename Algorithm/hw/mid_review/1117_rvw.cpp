#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct point_{
    int x;
    int y;
    int z;
    int a;
}point;

vector<point> pnt;
vector<int> srt;
int ans;
int n;

bool cmp_xyz(int i, int j);
bool cmp_yz(int i, int j);
bool cmp_zx(int i, int j);

void cnt_xyz();
void cnt_yz();
void cnt_zx();

int main(){
    pnt.resize(n);
    srt.reserve(n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &pnt[i].x, &pnt[i].y, &pnt[i].z);
        srt.push_back(i);
        pnt[i].a = n;
    }

    sort(srt.begin(), srt.end(), cmp_xyz);
    cnt_xyz();
    sort(srt.begin(), srt.end(), cmp_yz);
    cnt_yz();
    sort(srt.begin(), srt.end(), cmp_zx);
    cnt_zx();

    printf("%d", pnt[0].a);
    for(int i = 1; i < n; i++) printf(" %d", pnt[i].a);
}

bool cmp_xyz(int i, int j){
    if(pnt[i].x > pnt[j].x) return 1;
    if(pnt[i].x < pnt[j].x) return 0;

    if(pnt[i].y > pnt[j].y) return 1;
    if(pnt[i].y < pnt[j].y) return 0;

    if(pnt[i].z > pnt[j].z) return 1;
    if(pnt[i].z < pnt[j].z) return 0;
    return 0;
}

bool cmp_yz(int i, int j){
    if(pnt[i].y > pnt[j].y) return 1;
    if(pnt[i].y < pnt[j].y) return 0;
    
    if(pnt[i].z > pnt[j].z) return 1;
    if(pnt[i].z < pnt[j].z) return 0;
    return 0;
}

bool cmp_zx(int i, int j){
    if(pnt[i].z > pnt[j].z) return 1;
    if(pnt[i].z < pnt[j].z) return 0;

    if(pnt[i].x > pnt[j].x) return 1;
    if(pnt[i].x < pnt[j].x) return 0;
    return 0;
}

void cnt_xyz(){
    int sx = 1, sy = 1, sz = 1;
    int xfrom = 0, yfrom = 0, zfrom = 0;
    int curx = pnt[srt[0]].x;
    int cury = pnt[srt[0]].y;
    int curz = pnt[srt[0]].z;
    for(int i = 1; i < n; i++){
        if(pnt[srt[i]].x != curx){
            for(int j = xfrom; j < i; j++) pnt[j].a -= sx;
            sx = 1;
            xfrom = i;
            curx = pnt[srt[i]].x;

            for(int j = yfrom; j < i; j++) pnt[j].a += sy;
            sy = 1;
            yfrom = i;
            cury = pnt[srt[i]].y;

            for(int j = zfrom; j < i; j++) pnt[j].a -= sz;
            sz = 1;
            zfrom = i;
            curz = pnt[srt[i]].z;
        }
        else if(pnt[srt[i]].y != cury){
            sx ++;

            for(int j = yfrom; j < i; j++) pnt[j].a += sy;
            sy = 1;
            yfrom = i;
            cury = pnt[srt[i]].y;

            for(int j = zfrom; j < i; j++) pnt[j].a -= sz;
            sz = 1;
            zfrom = i;
            curz = pnt[srt[i]].z;
        }
        else if(pnt[srt[i]].z != curz){
            sx ++;
            sy ++;

            for(int j = zfrom; j < i; j++) pnt[j].a -= sz;
            sz = 1;
            zfrom = i;
            curz = pnt[srt[i]].z;
        }
        else{
            sx ++;
            sy ++;
            sz ++;
        }
    }
}

void cnt_yz(){
}

void cnt_zx(){
}