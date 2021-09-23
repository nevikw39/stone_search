#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_set<int> hs = {8, 27, 2021, 110, 20};
    cout << "The hash set contains:\n";
    for (const int &i : hs)
        cout << i << '\n';
    cout << "Insert an element: ";
    int n;
    cin >> n;
    hs.insert(n);
    cout << "Erase an element: ";
    cin >> n;
    hs.erase(n);
    cout << "The hash set now contains:\n";
    for (const int &i : hs)
        cout << i << '\n';
    unordered_map<string, int> ht = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}};
    ht["Apr"] = 4;
    ht["May"] = 5;
    ht["Jun"] = 6;
    ht["Jul"] = 7;
    ht["Aug"] = 8;
    ht["Sep"] = 9;
    ht["Oct"] = 10;
    ht["Nov"] = 11;
    ht["Dec"] = 12;
    string s;
    while (cin >> s)
    {
        auto itr = ht.find(s);
        if (itr != ht.end())
            cout << itr->second << '\n';
        else
            cout << "Not found.\n";
    }
    return 0;
}
