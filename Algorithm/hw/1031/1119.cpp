#include <cstdio>
#include <vector>
#include <algorithm>
#define LL long long int 
using namespace std;

typedef struct Node{
    int val;
    int i;
    int j;
}node;

bool cmp(node n1, node n2){
    return n1.val < n2.val;
}

void sw(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void put(int* arr, node* a, node* b){
    arr[0] = a -> i;
    arr[1] = b -> i;
    arr[2] = a -> j;
    arr[3] = b -> j;
    if(arr[0] > arr[1]) sw(arr[0], arr[1]);
    else if(arr[0] == arr[1]){
        arr[0] = -1;
        return;
    }
    if(arr[2] > arr[3]) sw(arr[2], arr[3]);
    else if(arr[2] == arr[3]){
        arr[0] = -1;
        return;
    }
    if(arr[1] > arr[2]) sw(arr[1], arr[2]);
    else if(arr[1] == arr[2]){
        arr[0] = -1;
        return;
    }
}

void cpy(const int* a, int* b){
    for(int i = 0; i < 4; i++) b[i] = a[i];
}

int main(){
    int n, s;
    scanf("%d%d", &n, &s);

    vector<int> in;
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);

    vector<node> sum2;
    sum2.resize(n*(n-1)/2);
    int cnt = 0;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++){
            sum2[cnt].val = in[i] + in[j];
            sum2[cnt].i = i;
            sum2[cnt].j = j;
            cnt ++;
        }
    sort(sum2.begin(), sum2.end(), cmp);
    //for(int i = 0; i < cnt; i++) printf("%d %d v:%d\n",sum2[i].i, sum2[i].j, sum2[i].val);
    int fr = 0, ba = cnt - 1;
    int done = 0;
    int ans[4];
    int samefr = 0;
    while(fr != ba){
        int cur = sum2[fr].val + sum2[ba].val;

        if(sum2[fr].val == sum2[ba].val){
            //printf("here\n");
            if(cur == s)
                for(int i = fr; i <= ba-1; i++)
                    for(int j = i + 1; j <= ba; j++){
                        int now[4];
                        put(now, &sum2[i], &sum2[j]);
                        if(now[0] < 0) continue;
                        if(!done){
                            cpy(now, ans);
                            done = 1;
                        }
                        else{
                            for(int k = 0; k < 4; k++){
                                if(now[k] < ans[k]){
                                    cpy(now, ans);
                                    break;
                                }
                                else if(now[k] > ans[k]) break;
                            }
                        }
                    }
            break;
        }
        //printf("noo\n");
        if(cur == s){
            int now[4];
            put(now, &sum2[fr], &sum2[ba]);
            
            if(sum2[fr].val == sum2[fr+1].val){
                fr ++;
                samefr ++;
            }
            else if(sum2[ba].val == sum2[ba-1].val){
                ba --;
                fr -= samefr;
                samefr = 0;
            }
            else ba --;

            if(now[0] < 0) continue;
            if(!done){
                cpy(now, ans);
                done = 1;
            }
            else{
                for(int i = 0; i < 4; i++){
                    if(now[i] < ans[i]){
                        cpy(now, ans);
                        break;
                    }
                    else if(now[i] > ans[i]) break;
                }
            }
        }
        else if (cur > s) ba --;
        else fr ++;
    }
    if(!done) printf("-1\n");
    else printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
}