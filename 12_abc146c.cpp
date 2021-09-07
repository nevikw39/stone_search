#include <iostream>

using namespace std;

long long a, b;

long long d(long long n)
{
    if (!n)
        return 1;
    long long y = 0;
    while (n)
    {
        n /= 10;
        ++y;
    }
    return y;
}

long long inline price(long long n)
{
    return a * n + b * d(n);
}

int main()
{
    long long x, r = 0;
    cin >> a >> b >> x;
    for (long long n = 1000000000, jump = n >> 1; jump; jump >>= 1)
        while (r + jump <= 1000000000 && price(r + jump) <= x)
            r += jump;
    cout << r << '\n';
    return 0;
}
