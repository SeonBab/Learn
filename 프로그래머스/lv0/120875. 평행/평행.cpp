#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<double> slope{};

    double x1 = (dots[0][0] - dots[1][0]);
    double y1 = (dots[0][1] - dots[1][1]);
    double x2 = (dots[2][0] - dots[3][0]);
    double y2 = (dots[2][1] - dots[3][1]);

    if (y1 / x1 == y2 / x2)
    {
        answer = 1;
    }

    x1 = (dots[0][0] - dots[2][0]);
    y1 = (dots[0][1] - dots[2][1]);
    x2 = (dots[1][0] - dots[3][0]);
    y2 = (dots[1][1] - dots[3][1]);

    if (y1 / x2 == y2 / x2)
    {
        answer = 1;
    }

    x1 = (dots[0][0] - dots[3][0]);
    y1 = (dots[0][1] - dots[3][1]);
    x2 = (dots[1][0] - dots[2][0]);
    y2 = (dots[1][1] - dots[2][1]);

    if (y1 / x1 == y2 / x2)
    {
        answer = 1;
    }

    return answer;
}