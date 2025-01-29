#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        for (int j = i + 1; j < nums.size() - 1; ++j)
        {
            for (int k = j + 1; k < nums.size(); ++k)
            {
                int num = nums[i] + nums[j] + nums[k];
                
                bool isPrimeNumber = true;
                for (int l = 2; l * l <= num; ++l)
                {
                    if (num % l == 0)
                    {
                        isPrimeNumber = false;
                        break;
                    }
                }
                
                if (true == isPrimeNumber)
                {
                    ++answer;
                }
            }
        }
    }

    return answer;
}