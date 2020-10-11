#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;


double W(double y) {
    long double max = 19.0;
    long double min = 0.0;
    long double mid;
    while(1){
        mid = (max + min) / 2.0;
        long double a = mid * exp(mid);
        if(abs(y - a) < 0.0000001)
            break;

        if(a > y){
            max = mid;
        }
        else{
            min = mid;
        }
    }
    return mid;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        double y;
        cin >> y;
        cout << fixed << setprecision(12) << W(y) << '\n';
    }
    return 0;
}