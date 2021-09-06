#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k, r = 0;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m), psa(n + 1), psb(m + 1);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    psa[0] = psb[0] = 0;
    for (int i = 1; i <= n; i++)
        psa[i] = psa[i - 1] + a[i - 1];
    for (int i = 1; i <= m; i++)
        psb[i] = psb[i - 1] + b[i - 1];
    for (int i = 0; i <= n; i++)
    {
        if (k < psa[i])
            break;
        auto j = --upper_bound(psb.begin(), psb.end(), k - psa[i]) - psb.begin();
        if (r < i + j)
            r = i + j;
    }
    cout << r << '\n';
    return 0;
}
