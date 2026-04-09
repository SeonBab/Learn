#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string inputStringA;
    string inputStringB;

    cin >> inputStringA >> inputStringB;

    int AlphabetCountA[26] = {};
    int AlphabetCountB[26] = {};

    for (int i = 0; i < inputStringA.length(); ++i)
    {
        int AlphabetIndex = inputStringA[i] - 'a';
        ++AlphabetCountA[AlphabetIndex];
    }

    for (int i = 0; i < inputStringB.length(); ++i)
    {
        int AlphabetIndex = inputStringB[i] - 'a';
        ++AlphabetCountB[AlphabetIndex];
    }

    int result = 0;
    for (int i = 0; i < 26; ++i)
    {
        result += abs(AlphabetCountA[i] - AlphabetCountB[i]);
    }

    cout << result;

    return 0;
}
