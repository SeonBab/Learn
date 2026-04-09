#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> TableArray(N, vector<int>(N, 0));
    pair<int, int> ProfessorIndex;
    pair<int, int> SungkyuIndex;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> TableArray[i][j];

            // 교수님의 위치
            if (TableArray[i][j] == 5)
            {
                ProfessorIndex = { j, i };
            }
            // 성규의 위치
            else if (TableArray[i][j] == 2)
            {
                SungkyuIndex = { j, i };
            }
        }
    }

    // 거리 체크
    float DeltaX = SungkyuIndex.first - ProfessorIndex.first;
    float DeltaY = SungkyuIndex.second - ProfessorIndex.second;

    float SquaredDeltaX = pow(DeltaX, 2.0f);
    float SquaredDeltaY = pow(DeltaY, 2.0f);

    float Distance = sqrt(SquaredDeltaX + SquaredDeltaY);

    // 도망 갈 수 없는 거리일 경우
    if (Distance < 5)
    {
        cout << 0 << endl;

        return 0;
    }

    // 학생이 세 명 이상 있는지 체크
    int MinX = min(ProfessorIndex.first, SungkyuIndex.first);
    int MinY = min(ProfessorIndex.second, SungkyuIndex.second);

    int StudentCount = 0;
    for (int i = 0; i <= abs(DeltaY); ++i)
    {
        for (int j = 0; j <= abs(DeltaX); ++j)
        {
            if (TableArray[MinY + i][MinX + j] == 1)
            {
                ++StudentCount;
            }
        }
    }

    if (StudentCount < 3)
    {
        cout << 0 << endl;

        return 0;
    }

    cout << 1 << endl;

    return 0;
}
