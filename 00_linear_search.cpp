#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
#include <random>    // for mt19937

using namespace std;

int linear_search(vector<int>::iterator begin, vector<int>::iterator end, int target)
{
    int result = INT_MAX; // infinity
    for (auto itr = begin; itr != end; itr++)
        if (*itr >= target && *itr < result)
            result = *itr;
    return result;
}

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20};
    for (const int &i : v)
        cout << i << ' ';
    int result = linear_search(v.begin(), v.end(), 110);
    if (result != INT_MAX)
        cout << "\nThe minimum element that greater than or equal to 110 is " << result << '\n';
    else
        cout << "Each element is less than 110\n";

    int n;
    cin >> n;
    v.resize(n);
    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
    {
        i = _rand();
        cout << i << ' ';
    }
    result = linear_search(v.begin(), v.end(), 110);
    if (result != INT_MAX)
        cout << "\nThe minimum element that greater than or equal to 110 is " << result << '\n';
    else
        cout << "Each element is less than 110\n";
    return 0;
}
