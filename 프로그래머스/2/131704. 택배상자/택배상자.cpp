#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> subContainerVelt;
    int index = 0;
    int currentBox = 1;
    
    while (index < order.size())
    {
        if (!subContainerVelt.empty() && subContainerVelt.top() == order[index])
        {
            subContainerVelt.pop();
            ++index;
            ++answer;
        }
        else if (currentBox <= order.size())
        {
            if (currentBox == order[index])
            {
                ++index;
                ++answer;
            }
            else
            {
                subContainerVelt.push(currentBox);
            }
            
            ++currentBox;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}