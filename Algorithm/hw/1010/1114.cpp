// formosa oj 1114
// Percentiles
// multiset
#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    multiset<unsigned int> s;
    multiset<unsigned int>::iterator it;
    int num = 0;
    int itpos, kpos;
    int in;
    double p = k/100.0;

    scanf("%d", &in);
    s.insert(in);
    itpos = 0;
    kpos = 0;
    it = s.begin();
    num++;
    int cur = in;

    for(int i = 1; i < n; i++){
        scanf("%d", &in);
        if(in){
            s.insert(in);
            num++;
            if(in < cur){
            //    it++;
                itpos++;
            }
            //printf("%d\n", *it);
        }
        else{
            kpos = ceil(p * num) - 1;
            if(kpos < 0) kpos = 0;
            int change = kpos - itpos;
            if(change > 0) while(change --) it++;
            else while(change ++ < 0) it --;
            itpos = kpos;
            printf("%d\n", *it);
            cur = *it;
        }
    }
}