#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAXN = 128; // log(a*b) = log a + log b; 64 digit * 64 digit < 128 digit

class bigNum
{
    int a[MAXN] = {0};

public:
    bigNum();
    bigNum(string num); // for input
    bigNum(const bigNum &source, int new_len, int pos); // for cutting down & copy

    int len;
    void print();
    bigNum pow(int n); // return this * 10^n

    bigNum operator+(const bigNum &b);
    bigNum operator-(const bigNum &b);
    bigNum operator*(const bigNum &b);
};

// constructor
bigNum::bigNum() : len(0)
{
}

bigNum::bigNum(string num) : len(num.size())
{
    reverse(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        this->a[i] = static_cast<int>(num[i] - '0');
    }
}

bigNum::bigNum(const bigNum &source, int new_len, int pos) : len(new_len)
{
    for (int i = 0; i < new_len; i++)
    {
        this->a[i] = source.a[pos + i];
    }
}

// method
void bigNum::print()
{
    if (!this->len)
        cout << "0";
    for (int i = this->len - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
}

bigNum bigNum::pow(int n)
{
    bigNum ans(*this, this->len, 0); // copy
    for (int i = ans.len - 1; i >= 0; i--)
    {
        ans.a[i + n] = ans.a[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans.a[i] = 0;
    }
    ans.len += n;
    return ans;
}

bigNum bigNum::operator+(const bigNum &b)
{
    bigNum ans;
    ans.len = max(this->len, b.len) + 1;

    for (int i = 0; i < ans.len; i++)
    {
        ans.a[i] += (this->a[i] + b.a[i]);
        ans.a[i + 1] += ans.a[i] / 10;
        ans.a[i] %= 10;
    }

    while (!ans.a[ans.len - 1] && ans.len > 0) // 0 + 0
        ans.len--;
    return ans;
}

bigNum bigNum::operator-(const bigNum &b)
{
    bigNum ans;
    ans.len = this->len;

    for (int i = 0; i < b.len; i++)
    {
        ans.a[i] += (this->a[i] - b.a[i]);
        if (ans.a[i] < 0)
        {
            ans.a[i + 1]--;
            ans.a[i] += 10;
        }
    }

    for (int i = b.len; i < ans.len; i++)
    {
        ans.a[i] += this->a[i];
    }

    while (!ans.a[ans.len - 1] && ans.len > 0) // 10 - 10
        ans.len--;
    return ans;
}

// basic multiplication
bigNum bigNum::operator*(const bigNum &b)
{
    bigNum ans;
    for (int i = 0; i < this->len; i++)
    {
        for (int j = 0; j < b.len; j++)
        {
            ans.a[i + j] += this->a[i] * b.a[j];
            ans.a[i + j + 1] += ans.a[i + j] / 10;
            ans.a[i + j] %= 10;
        }
    }
    ans.len = this->len + b.len;
    while (!ans.a[ans.len - 1] && ans.len > 0) // 0 * 7
        ans.len--;
    return ans;
}

// kara
bigNum kara(bigNum x, bigNum y)
{
    if (!x.len || !y.len)
        return bigNum();
    if (x.len == 1 || y.len == 1) // 3*11
        return x * y;

    int len_cut = min(x.len / 2, y.len / 2); // 168*1052
    bigNum a(x, x.len - len_cut, len_cut);   // x = a*10^len_cut + b; x.len-x.len/2 to avoid odd cases (3 digits, 168)
    bigNum b(x, len_cut, 0);
    bigNum c(y, y.len - len_cut, len_cut);
    bigNum d(y, len_cut, 0);
    bigNum ac = kara(a, c);
    bigNum bd = kara(b, d);
    bigNum t = kara((a + b), (c + d));

    return (ac.pow(len_cut * 2)) + (t - ac - bd).pow(len_cut) + bd;
}

// version for x & y within 2^64 range:
// long kara(long x, long y){

//     if(!x || !y) return 0;
//     long digit_x = 1, digit_y = 1;
//     long x_tmp = x, y_tmp = y;
//     while(x_tmp/=10) digit_x++;
//     while(y_tmp/=10) digit_y++;

//     if (digit_x == 1 && digit_y == 1)  return x*y;
//     else
//     {
//         int t1 = (int) digit_x / 2;
//         int t2 = (int) digit_y / 2;
//         long a = x / (long) pow(10,t1);
//         long b = x % (long) pow(10,t1);
//         long c = y / (long) pow(10,t2);
//         long d = y % (long) pow(10,t2);
//         long ac = kara(a,c);
//         long bd = kara(b,d);
//         long t = kara((a+b),(c+d));
//         return ((long)pow(10,t1+t2)*ac+(long)pow(10, t1)*(t-ac-bd)+bd);
//     }
// }

int main()
{
    string x, y;
    cin >> x >> y;
    bigNum X(x);
    bigNum Y(y);

    // basic multiplication
    clock_t startTime1 = clock();
    bigNum basic_ans = X * Y;
    basic_ans.print();
    clock_t basicTime = clock();
    cout << "Basic multiplication: " << (double)(basicTime - startTime1) / CLOCKS_PER_SEC << " s" << endl;

    // karatsuba multiplication
    clock_t startTime2 = clock();
    bigNum kara_ans = kara(X, Y);
    kara_ans.print();
    clock_t karaTime = clock();
    cout << "Karatsuba multiplication: " << (double)(karaTime - startTime2) / CLOCKS_PER_SEC << " s" << endl;

    return 0;
}
