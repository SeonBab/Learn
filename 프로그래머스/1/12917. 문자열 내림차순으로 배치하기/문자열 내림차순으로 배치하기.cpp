#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = s;
    
    std::sort(answer.begin(), answer.end(), std::greater<char>());
    
    return answer;
}