#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int carry{};

    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());

    if (bin1.size() > bin2.size())
    {
        while (bin1.size() - bin2.size())
        {
            bin2 += '0';
        }
    }
    else if (bin1.size() < bin2.size())
    {
        while (bin2.size() - bin1.size())
        {
            bin1 += '0';
        }
    }

    for (int i = 0; i < bin1.size(); ++i)
    {
        int num = (bin1[i] - '0') + (bin2[i] - '0') + carry;
        carry =  num / 2;
        answer += to_string(num % 2);
    }

    if (carry)
    {
        answer += to_string(carry);
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}