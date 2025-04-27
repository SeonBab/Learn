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
        while (next < strLength && name[next] == 'A')
        {
            ++next;
        }

        int targetDistance = strLength - next;

        moveCount = min(moveCount, i * 2 + targetDistance);
        moveCount = min(moveCount, targetDistance * 2 + i);
    }

    answer += moveCount;

    return answer;
}