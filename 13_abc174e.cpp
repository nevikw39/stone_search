#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> a;

bool predict(int x)
{
    int cut = 0;
    for (const int &i : a)
    {
        cut += i / x;
        if (i % x == 0)
            --cut;
        if (cut > k)
            return false;
    }
    return true;
}

int main()
{
    int n, mx = 0, r = 0;
    cin >> n >> k;
    a.resize(n);
    for (int &i : a)
    {
        cin >> i;
        mx = mx > i ? mx : i;
    }
    for (int jump = mx >> 1; jump; jump >>= 1)
        while (r + jump < mx && !predict(r + jump))
            r += jump;
    cout << r + 1 << '\n';
    return 0;
}
