#include <iostream>
#include <vector>
#include <random>    // for mt19937
#include <algorithm> // for sort(), lower_bound()

using namespace std;

vector<int>::iterator binary_search_loop(vector<int>::iterator begin, vector<int>::iterator end, int target)
{
    while (begin != end)
    {
        auto mid = begin + (end - begin) / 2;
        if (target < *mid)
            end = mid;
        else if (target == *mid)
            return mid;
        else
            begin = mid + 1;
    }
    return begin;
}

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20};
    sort(v.begin(), v.end());
    for (const int &i : v)
        cout << i << ' ';
    auto result = binary_search_loop(v.begin(), v.end(), 109);
    if (result != v.end())
        cout << "\nThe minimum element that greater than or equal to 109 is " << *result << '\n';
    else
        cout << "Each element is less than 109\n";
    result = binary_search_loop(v.begin(), v.end(), 110);
    if (result != v.end())
        cout << "The minimum element that greater than or equal to 110 is " << *result << '\n';
    else
        cout << "Each element is less than 110\n";
    result = binary_search_loop(v.begin(), v.end(), 111);
    if (result != v.end())
        cout << "The minimum element that greater than or equal to 111 is " << *result << '\n';
    else
        cout << "Each element is less than 111\n";

    int n, target;
    cin >> n;
    v.resize(n);
    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
        i = _rand();
    sort(v.begin(), v.end());
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    cin >> target;
    result = binary_search_loop(v.begin(), v.end(), target - 1);
    if (result != v.end())
        cout << "The minimum element that greater than or equal to " << target - 1 << " is " << *result << '\n';
    else
        cout << "Each element is less than " << target - 1 << '\n';
    result = binary_search_loop(v.begin(), v.end(), target);
    if (result != v.end())
        cout << "The minimum element that greater than or equal to " << target << " is " << *result << '\n';
    else
        cout << "Each element is less than " << target << '\n';
    result = binary_search_loop(v.begin(), v.end(), target + 1);
    if (result != v.end())
        cout << "The minimum element that greater than or equal to " << target + 1 << " is " << *result << '\n';
    else
        cout << "Each element is less than " << target + 1 << '\n';
    return 0;
}
