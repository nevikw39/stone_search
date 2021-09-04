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
    auto result = lower_bound(v.begin(), v.end(), 110);
    if (result != v.end())
        cout << "\nThe minimum element that no less than (greater than or equal to) 110 is " << *result << '\n';
    else
        cout << "Each element is less than 110\n";
    result = upper_bound(v.begin(), v.end(), 110);
    if (result != v.end())
        cout << "The minimum element that greater than 110 is " << *result << '\n';
    else
        cout << "Each element is less than 110\n";

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
    result = lower_bound(v.begin(), v.end(), target);
    if (result != v.end())
        cout << "The minimum element that no less than (greater than or equal to) " << target << " is " << *result << '\n';
    else
        cout << "Each element is less than " << target << '\n';
    result = upper_bound(v.begin(), v.end(), target);
    if (result != v.end())
        cout << "The minimum element that greater than " << target << " is " << *result << '\n';
    else
        cout << "Each element is less than " << target << '\n';
    return 0;
}
