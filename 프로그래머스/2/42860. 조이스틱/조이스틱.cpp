#include <string>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int strLength = name.length();
    int moveCount = strLength;

    for (int i = 0; i < strLength; ++i)
    {
        char c = name[i];
        answer += min(c - 'A', 'Z' - c + 1);

        int next = i + 1;
        while (next < name.length() && name[next] == 'A')
        {
            ++next;
        }

        moveCount = min(moveCount, i * 2 + strLength - next);
        moveCount = min(moveCount, (strLength - next) * 2 + i);
    }

    answer += moveCount;

    return answer;
}