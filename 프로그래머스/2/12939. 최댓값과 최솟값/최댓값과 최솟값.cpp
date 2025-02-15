#include <string>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    
    istringstream iss(s);
    
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    int compNum = 0;
    
    while (iss >> compNum)
    {
        minNum = (minNum > compNum) ? compNum : minNum;
        maxNum = (maxNum < compNum) ? compNum : maxNum;
    }
    
    answer += to_string(minNum);
    answer += " ";
    answer += to_string(maxNum);
    
    return answer;
}