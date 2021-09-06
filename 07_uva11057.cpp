#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
#include <algorithm> // for sort(), lower_bound(), upper_bound()

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        int m, g = INT_MAX >> 1, l = INT_MIN >> 1;
        cin >> m;
        for (const int &i : v)
            if (lower_bound(v.begin(), v.end(), m - i) != upper_bound(v.begin(), v.end(), m - i) && abs(m - i * 2) < g - l)
            {
                g = max(i, m - i);
                l = min(i, m - i);
            }
        cout << "Peter should buy books whose prices are " << l << " and " << g << ".\n\n";
    }
    return 0;
}