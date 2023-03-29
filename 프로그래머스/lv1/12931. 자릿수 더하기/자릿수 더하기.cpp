#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string num = to_string(n);

    for (int i = 0; i < num.size(); ++i)
    {
        answer += (static_cast<int>(num[i]) - '0');
    }

    cout << answer << endl;

    return answer;
}