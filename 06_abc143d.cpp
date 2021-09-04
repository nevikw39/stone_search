#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long r = 0;
    for (auto itr = v.begin(); itr != v.end(); itr++)
        for (auto jtr = itr + 1; jtr != v.end(); jtr++)
            r += lower_bound(jtr + 1, v.end(), *itr + *jtr) - upper_bound(jtr + 1, v.end(), *jtr - *itr);
    cout << r << '\n';
    return 0;
}
