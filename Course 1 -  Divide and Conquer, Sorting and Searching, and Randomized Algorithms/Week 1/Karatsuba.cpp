#include <iostream>
#include <cmath>
using namespace std;

long kara(long x, long y){
    if(!x || !y) return 0;

    long digit_x = 1, digit_y = 1;
    long x_tmp = x, y_tmp = y;
    while(x_tmp/=10) digit_x++;
    while(y_tmp/=10) digit_y++;

    if (digit_x == 1 && digit_y == 1)  return x*y;
    else
    {
        int t1 = (int) digit_x / 2;
        int t2 = (int) digit_y / 2;
        long a = x / (long) pow(10,t1);
        long b = x % (long) pow(10,t1);
        long c = y / (long) pow(10,t2);
        long d = y % (long) pow(10,t2);
        long ac = kara(a,c);
        long bd = kara(b,d);
        long t = kara((a+b),(c+d));
        return ((long)pow(10,t1+t2)*ac+(long)pow(10, t1)*(t-ac-bd)+bd);
    }
}

int main(){;
    long x, y;
    cin >> x >> y;
    cout << kara(x,y) << endl;
    return 0;
}


