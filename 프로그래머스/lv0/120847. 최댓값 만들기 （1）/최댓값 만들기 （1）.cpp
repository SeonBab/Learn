#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0, max1{}, max2{};
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (max1 < numbers[i])
        {
            max2 = max1;
            max1 = numbers[i];
        }
        else if (max2 < numbers[i])
        {
            max2 = numbers[i];
        }
    }
    return answer = max1 * max2;
}