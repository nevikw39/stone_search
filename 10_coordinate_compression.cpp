#include <iostream>
#include <vector>
#include <random>    // for mt19937
#include <algorithm> // for sort(), lower_bound(), upper_bound()

using namespace std;

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20, 110, 27, 20, 27}, rank, cc;
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    rank = v;
    sort(rank.begin(), rank.end());
    auto itr = unique(rank.begin(), rank.end()); // move duplicate elements to end and return new valid end
    rank.erase(itr, rank.end());                 // remove them
    for (const int &i : v)
        cc.push_back(lower_bound(rank.begin(), rank.end(), i) - rank.begin());
    for (const int &i : cc)
        cout << i << ' ';
    cout << '\n';

    int n;
    cin >> n;
    v.resize(n);
    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
        i = _rand();
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    rank = v;
    sort(rank.begin(), rank.end());
    itr = unique(rank.begin(), rank.end());
    rank.erase(itr, rank.end());
    for (const int &i : v)
        cc.push_back(lower_bound(rank.begin(), rank.end(), i) - rank.begin());
    for (const int &i : cc)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
