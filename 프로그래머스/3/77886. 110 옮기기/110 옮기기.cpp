#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (auto str : s)
    {
        stack<char> st;
        
        int count = 0;
        
        for (auto c : str)
        {
            st.push(c);
            
            if (st.size() >= 3)
            {
                char third = st.top();
                st.pop();
                char second = st.top();
                st.pop();
                char first = st.top();
                st.pop();
                
                if (first == '1' && second == '1' && third == '0')
                {
                    ++count;
                }
                else
                {
                    st.push(first);
                    st.push(second);
                    st.push(third);
                }
            }
        }
        
        string temp = "";
        while (!st.empty())
        {
            temp = st.top() + temp;
            st.pop();
        }
        
        int pos = temp.find_last_of('0');
        if (pos == string::npos)
        {
            temp = string(count, '1') + string(count, '1') + string(count, '0') + temp;
        }
        else
        {
            temp.insert(pos + 1, string(count, '1') + string(count, '1') + string(count, '0'));
       }
        
        answer.push_back(temp);
    }
    
    return answer;
}