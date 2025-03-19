#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxNum = INT_MIN;
int minNum = INT_MAX;

void backtrack(const vector<int>& numList, vector<int>& operatorList, int curResult, int numListIndex)
{
	if (numListIndex >= numList.size())
	{
		maxNum = (maxNum > curResult) ? maxNum : curResult;
		minNum = (minNum > curResult) ? curResult : minNum;

		return;
	}

	for (int operIndex = 0; operIndex < operatorList.size(); ++operIndex)
	{
		if (operatorList[operIndex] > 0)
		{
			--operatorList[operIndex];
		}
		else
		{
			continue;
		}

		int nextResult = curResult;

		switch (operIndex)
		{
		case 0:
			backtrack(numList, operatorList, curResult + numList[numListIndex], numListIndex + 1);
			break;
		case 1:
			backtrack(numList, operatorList, curResult - numList[numListIndex], numListIndex + 1);
			break;
		case 2:
			backtrack(numList, operatorList, curResult * numList[numListIndex], numListIndex + 1);
			break;
		case 3:
			if (curResult < 0) nextResult = -(-nextResult / numList[numListIndex]);
			else nextResult /= numList[numListIndex];

			backtrack(numList, operatorList, nextResult, numListIndex + 1);
			break;
		default:
			break;
		}

		++operatorList[operIndex];
	}
}

// 사용 예시
int main()
{
	int n;
	std::cin >> n;

	vector<int> numList(n);

	for (int i = 0; i < n; ++i)
	{
		int temp;
		std::cin >> temp;
		numList[i] = temp;
	}

	vector<int> operatorList(4);

	for (int i = 0; i < 4; ++i)
	{
		int temp;
		std::cin >> temp;
		operatorList[i] = temp;
	}

	backtrack(numList, operatorList, numList[0], 1);

	std::cout << maxNum << std::endl;
	std::cout << minNum << std::endl;
}