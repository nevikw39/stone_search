#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> a;
    a.insert(110);
    a.insert(2021);
    a.insert(2021);
    set<int> b = {8, 27, 2021, 110, 20, 110, 27, 20, 27};
    cout << a.size() << ':';
    for (auto itr = a.begin(); itr != a.end(); itr++)
        cout << ' ' << *itr;
    cout << '\n'
         << b.size() << ':';
    for (const int &i : b)
        cout << ' ' << i;
    cout << '\n';

    set<int> s;
    set<int>::iterator itr;
    int x, v;
    while (cin >> x >> v)
        switch (x)
        {
        case 0:
            s.insert(v);
            cout << s.size() << ':';
            for (const int &i : s)
                cout << ' ' << i;
            cout << '\n';
            break;
        case 1:
            itr = s.find(v);
            if (itr != s.end())
                cout << *itr << '\n';
            else
                cout << "There is no element equal to " << v << ".\n";
            break;
        case 2:
            itr = s.lower_bound(v);
            if (itr != s.end())
                cout << *itr << '\n';
            else
                cout << "There is no element greater than or equal to " << v << ".\n";
            break;
        case 3:
            itr = s.upper_bound(v);
            if (itr != s.end())
                cout << *itr << '\n';
            else
                cout << "There is no element greater than or equal to " << v << ".\n";
            break;
        case 4:
            s.erase(v);
            cout << s.size() << ':';
            for (const int &i : s)
                cout << ' ' << i;
            cout << '\n';
        }
    return 0;
}
