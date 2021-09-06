#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
#include <algorithm> // for sort(), lower_bound(), upper_bound()

using namespace std;

int main()
{
    vector<long long> v, pow2(32, 1), pow3(32, 1);
    for (int i = 1; i < 32; i++)
        pow2[i] = pow2[i - 1] * 2;
    for (int i = 1; i < 32; i++)
        pow3[i] = pow3[i - 1] * 3;
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++)
        {
            if (pow2[i] * pow3[j] > INT_MAX)
                break;
            v.push_back(pow2[i] * pow3[j]);
        }
    sort(v.begin(), v.end());
    int m;
    while (cin >> m && m)
        cout << *lower_bound(v.begin(), v.end(), m) << '\n';
    return 0;
}