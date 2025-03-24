#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int minDiff = INT_MAX; // 최소 능력치 차이

// 능력치 계산 함수
int calculateDifference(const vector<vector<int>>& S, vector<bool>& selected, const int n)
{
    vector<int> teamA, teamB;

    // 선택 된 사람을 A팀, 선택 되지 않은 사람을 B팀
    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            teamA.push_back(i);
        }
        else
        {
            teamB.push_back(i);
        }
    }

    int sumA = 0, sumB = 0;

    // 각 팀의 능력치 합산
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            if (i == j) continue;

            sumA += S[teamA[i]][teamA[j]];
            sumB += S[teamB[i]][teamB[j]];
        }
    }

    // 능력치 차이가 음수 일 수 있으므로, 절대값으로 변환
    return abs(sumA - sumB);
}

// 백트래킹 함수 (팀 구성)
void backtrack(const vector<vector<int>>& S, vector<bool>& selected, const int n, int idx, int count)
{
    // 팀원이 나눠진 경우
    if (count == n / 2)
    {
        // 능력치를 계산하고 능력치 차이가 최소값인지 확인 후 저장
        int calculateDiff = calculateDifference(S, selected, n);
        minDiff = min(minDiff, calculateDiff);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;  // i번 사람을 선택
            backtrack(S, selected, n, i + 1, count + 1);
            selected[i] = false; // 원상 복구
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> S(n, vector<int>(n)); // n X n개의 배열
    vector<bool> selected(n); // 백트래킹을 위한 선택 배열

    // 능력치 입력 받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> S[i][j];
        }
    }

    // 백트래킹 실행
    backtrack(S, selected, n, 0, 0);

    // 최소 차이 출력
    cout << minDiff << endl;
}