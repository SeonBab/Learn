#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0, num;
    char mark;
    stringstream ss(my_string);
    
    ss >> answer;
    
    while (ss >> mark >> num)
    {
        if (mark == '+')
        {
            answer += num;
        }
        else
        {
            answer -= num;
        }
    }
    
    return answer;
}