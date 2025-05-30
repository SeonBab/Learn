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
        
        string insertStr = "";
        for (int i = 0; i < count; ++i)
        {
            insertStr += "110";
        }
        
        int pos = temp.find_last_of('0');
        if (pos == string::npos)
        {
            temp = insertStr + temp;
        }
        else
        {
            temp.insert(pos + 1, insertStr);
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}