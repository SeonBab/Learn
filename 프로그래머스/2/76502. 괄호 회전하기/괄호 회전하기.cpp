#include <string>
#include <stack>
#include <algorithm>

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
        
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    
    return answer;
}