#include <iostream>
#include <vector>
#include <random>    // for mt19937
#include <algorithm> // for sort(), lower_bound(), upper_bound()

using namespace std;

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20, 110, 27, 20, 27};
    sort(v.begin(), v.end());
    for (const int &i : v)
        cout << i << ' ';
    auto l = lower_bound(v.begin(), v.end(), 110), u = upper_bound(v.begin(), v.end(), 110);
    cout << "\nThere are " << l - v.begin() << " elements less than 110:";
    for (auto itr = v.begin(); itr != l; itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << v.end() - l << " elements no less than (greater than or equal to) 110:";
    for (auto itr = l; itr != v.end(); itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << u - v.begin() << " elements no greater than (less than or equal to) 110:";
    for (auto itr = v.begin(); itr != u; itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << v.end() - u << " elements greater than 110:";
    for (auto itr = u; itr != v.end(); itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << u - l << " elements equal to 110:";
    for (auto itr = l; itr != u; itr++)
        cout << ' ' << *itr;
    cout << '\n';

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
    l = lower_bound(v.begin(), v.end(), target), u = upper_bound(v.begin(), v.end(), target);
    cout << "\nThere are " << l - v.begin() << " elements less than " << target << ':';
    for (auto itr = v.begin(); itr != l; itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << v.end() - l << " elements no less than (greater than or equal to) " << target << ':';
    for (auto itr = l; itr != v.end(); itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << u - v.begin() << " elements no greater than (less than or equal to) " << target << ':';
    for (auto itr = v.begin(); itr != u; itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << v.end() - u << " elements greater than " << target << ':';
    for (auto itr = u; itr != v.end(); itr++)
        cout << ' ' << *itr;
    cout << "\nThere are " << u - l << " elements equal to " << target << ':';
    for (auto itr = l; itr != u; itr++)
        cout << ' ' << *itr;
    cout << '\n';
    return 0;
}
