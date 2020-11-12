#include <cstdio>
#include <set>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    double per = k/100.0;
    multiset<int> s;
    multiset<int>::iterator it;

    int x;
    scanf("%d", &x);
    s.insert(x);
    it = s.begin();
    int size = 1, itpos = 1;
    n--;

    while(n--){
        scanf("%d", &x);

        if(x){
            //insert
            s.insert(x);
            if(x < *it) itpos ++;
            //printf("%d %d\n", *it, itpos);
            size ++;
        }
        else{
            //query
            if(k == 0){
                printf("%d\n", *s.begin());
                continue;
            }
            int goodpos = ceil(per*size);
            //printf("%d\n", goodpos);
            while(itpos < goodpos){
                itpos ++;
                it ++;
            }
            while(itpos > goodpos){
                itpos --;
                it --;
            }
            printf("%d\n", *it);
        }
    }
}