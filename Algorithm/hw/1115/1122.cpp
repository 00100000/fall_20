#include <cstdio>
using namespace std;

typedef struct item_{
    int w;
    int v;
    int p;
} item;

int main(){
    int n, W, V;
    scanf("%d%d%d", &n, &W, &V);

    item in[505];
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &in[i].w, &in[i].v, &in[i].p);
    }

    int t[505][505] = {0};
    for(int i = 0; i < n; i++)
        for(int w = W; w >= in[i].w; w--)
            for(int v = V; v >= in[i].v; v--){
                if(t[w-in[i].w][v-in[i].v]+in[i].p > t[w][v]) t[w][v] = t[w-in[i].w][v-in[i].v]+in[i].p;
            }
    printf("%d\n", t[W][V]);
}