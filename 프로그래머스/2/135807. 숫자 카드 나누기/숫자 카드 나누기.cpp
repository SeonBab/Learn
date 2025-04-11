#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int getGCD(const vector<int>& arr)
{
    int result = arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        result = gcd(result, arr[i]);
    }
    
    return result;
}

vector<int> getDivisors(int num)
{
    vector<int> divisors;
    for (int i = 1; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            divisors.push_back(i);
            if (i != num / i)
            {
                divisors.push_back(num / i);
            }
        }
    }
    
    sort(divisors.rbegin(), divisors.rend());
    
    return divisors;
}

bool isValid(int x, const vector<int>& arr)
{
    for (int a : arr)
    {
        if (a % x == 0)
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = getGCD(arrayA);
    int gcdB = getGCD(arrayB);
    
    vector<int> divisorsA = getDivisors(gcdA);
    for (int element : divisorsA)
    {
        if (isValid(element, arrayB))
        {
            answer = max(answer, element);
            break;
        }
    }
    
    vector<int> divisorsB = getDivisors(gcdB);
    for (int element : divisorsB)
    {
        if (isValid(element, arrayA))
        {
            answer = max(answer, element);
            break;
        }
    }
    
    return answer;
}