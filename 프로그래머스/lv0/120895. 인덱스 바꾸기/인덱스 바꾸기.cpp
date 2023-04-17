#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = "";
    char temp {};
    
    temp = my_string[num1];
    my_string[num1] = my_string[num2];
    my_string[num2] = temp;
    
    return answer = my_string;
}