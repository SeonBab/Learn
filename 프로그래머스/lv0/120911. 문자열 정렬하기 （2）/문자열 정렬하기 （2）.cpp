#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";

    
    for (char alphabet = 'a'; alphabet <= 'z'; ++alphabet)
    {
        for (int i = 0; i < my_string.length(); ++i)
        {
            if (alphabet == my_string[i] || alphabet + ('A' - 'a') == my_string[i])
            {
                answer.push_back(alphabet);
            }
        }
    }
    
    return answer;
}