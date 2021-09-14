#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;
    m["Sunday"] = 0;
    m["Monday"] = 1;
    m["Tuesday"] = 2;
    m["Wednesday"] = 3;
    m["Thursday"] = 4;
    m["Friday"] = 5;
    m["Saturday"] = 6;
    for (const auto &i : m)
        cout << i.first << ": " << i.second << '\n';
    string s;
    while (cin >> s)
    {
        auto itr = m.find(s);
        if (itr != m.end())
            cout << itr->second << '\n';
        else
            cout << "Not found.\n";
    }
    return 0;
}
