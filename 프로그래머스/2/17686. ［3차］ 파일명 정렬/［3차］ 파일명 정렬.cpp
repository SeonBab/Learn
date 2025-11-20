#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string lowerHead(string str)
{
    string lowerHead;
    for (int i = 0; i < str.size(); ++i)
    {
        if (isdigit(str[i]))
        {
            break;
        }
        
        lowerHead += tolower(str[i]);
    }
    
    return lowerHead;
}

int getNumber(string str)
{
    auto firstDigitIt = find_if(str.begin(), str.end(), [](char c)
                                { return isdigit(c); });
    int firstDigitIndex = distance(str.begin(), firstDigitIt);
    
    auto endDigitIt = firstDigitIt;
    while (endDigitIt != str.end() && isdigit(*endDigitIt))
    {
        ++endDigitIt;
    }
    
    int length = distance(firstDigitIt, endDigitIt);
    
    string numStr = str.substr(firstDigitIndex, length);
    
    return stoi(numStr);
}

bool compare(string a, string b)
{
    string aHead = lowerHead(a);
    string bHead = lowerHead(b);
    
    // HEAD 사전순 확인
    if (aHead < bHead)
    {
        return true;
    }
    
    int aNum = getNumber(a);
    int bNum = getNumber(b);
    
    if (aNum < bNum)
    {
        return true;
    }
    
    return false;
}

vector<string> solution(vector<string> files) {
    sort(files.begin(), files.end(), compare);
    return files;
}