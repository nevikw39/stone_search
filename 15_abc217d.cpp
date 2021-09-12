#include <iostream>
#include <set>

using namespace std;

int main()
{
    int l, q;
    cin >> l >> q;
    set<int> s;
    // we can imagine that the timber has been cut at mark 0 and l
    s.insert(0);
    s.insert(l);
    while (q--)
    {
        int c, x;
        cin >> c >> x;
        if (c == 1)
            s.insert(x);
        else
        {
            auto l = --s.lower_bound(x); // find the greatest cut mark on the left of x
                                         // note that because we insert 0 at the begin and x > 0, so s.lower_bound(x) won't be s.begin()
            auto r = s.upper_bound(x);   // find the least one on the right of x
                                         // note that because we insert l at the begin and x < l, so s.upper_bound(x) won't be s.end()
            cout << *r - *l << '\n';
        }
    }
    return 0;
}
