#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.length(); ++i)
    {
        stack<char> st;
        
        for (char e : s)
        {
            if (st.top() == '[' && e == ']')
            {
                st.pop();
            }
            else if (st.top() == '{' && e == '}')
            {
                st.pop();
            }
            else if (st.top() == '(' && e == ')')
            {
                st.pop();
            }
            else
            {
                st.push(e);
            }
        }
        
        if (st.empty())
        {
            ++answer;
        }
        
        s += s[0];
        s = s.substr(1);
    }
    
    return answer;
}