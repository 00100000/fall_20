#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

int w[100005];
int t;

int test(int mid){
    int index = 0;
    int done = 0;
    for(int i = 0; i < 24; i++){
        int now = 0;
        while(now <= mid + 1){
            now += w[index++];
            if(index > t){
                done = 1;
                break;
            }
        }
        if(done) break;
        index --;
    }
    return done;
}

int main(){
    scanf("%d", &t);

    char in[100005];
    scanf("%s", in);
    int maxW = strlen(in);
    //w[0] = maxW+1;
    w[0] = maxW + 1;

    for(int i = 1; i < t; i++){
        char in[100005];
        scanf("%s", in);
        int inw = strlen(in);
        if(inw > maxW)
            maxW = inw;
        //w[i] = w[i-1] + inw + 1;
        w[i] = inw + 1;
    }
    /*
    for(int i = 0; i < t; i++){
        printf("%d ", w[i]);
    }
    printf("\n");
    */
    if(t <= 24){
        printf("%d\n", maxW);
        return 0;
    }
    
    int max = 100005;
    int min = maxW;
    int mid;
    while(1){
        mid = (max + min) / 2;
        if(test(mid)){
            max = mid;
        }
        else{
            min = mid + 1;
        }
        if(max <= min){
            break;
        }
    }
    printf("%d\n", max);
}