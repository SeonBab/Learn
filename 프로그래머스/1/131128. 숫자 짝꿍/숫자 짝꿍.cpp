#include <string>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int xArray[10] { 0 };
    int yArray[10] { 0 };
    
    for(int i = 0; i < X.length(); ++i)
    {
        int xInt = X[i] - '0';
        ++xArray[xInt];
    }
        
    for(int i = 0; i < Y.length(); ++i)
    {
        int yInt = Y[i] - '0';
        ++yArray[yInt];
    }
    
    for(int i = 9; i >= 0; --i)
    {
        if (xArray[i] == 0 || yArray[i] == 0)
        {
            continue;
        }
                
        int minValue = (xArray[i] < yArray[i]) ? xArray[i] : yArray[i];
        
        for (int j = 0; j < minValue; ++j)
        {
            answer.push_back('0' + i);
        }
    }
    
    if (answer.size() == 0)
    {
        answer = "-1";
    }
    else if (answer[0] == '0')
    {
        answer = '0';
    }
    
    return answer;
}