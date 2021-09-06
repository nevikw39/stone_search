#include <iostream>
#include <vector>
#include <algorithm> // for sort(), lower_bound()

using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> cards(n);
    vector<int> rank_x, rank_y;
    for (auto &i : cards)
    {
        cin >> i.first >> i.second;
        rank_x.push_back(i.first);
        rank_y.push_back(i.second);
    }
    sort(rank_x.begin(), rank_x.end());
    rank_x.erase(unique(rank_x.begin(), rank_x.end()), rank_x.end());
    sort(rank_y.begin(), rank_y.end());
    rank_y.erase(unique(rank_y.begin(), rank_y.end()), rank_y.end());
    for (const auto &i : cards)
        cout << lower_bound(rank_x.begin(), rank_x.end(), i.first) - rank_x.begin() + 1 << lower_bound(rank_y.begin(), rank_y.end(), i.second) - rank_y.begin() + 1 << '\n';
    return 0;
}
