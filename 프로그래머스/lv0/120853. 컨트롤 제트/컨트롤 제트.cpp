#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0, temp{};
    char mark{};
    stack<int> st;
    
    s += ' ';

    
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            temp = temp * 10 + s[i] - '0';
        }
        else if (s[i] == '-')
        {
            mark = '-';
        }
        else if (s[i] == ' ')
        {
            if (mark == '-')
            {
                st.push(-temp);
            }
            else
            {
                st.push(temp);
            }

            temp = 0;
            mark = ' ';
        }
        else
        {
            st.pop();
        }
    }

    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }

    return answer;
}