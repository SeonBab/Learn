#include <string>
#include <vector>

using namespace std;

void merge(vector<string>& strings, int left, int mid, int right, int n)
{
    vector<string> temp(right - left + 1);
    
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= right)
    {
        if (strings[i][n] < strings[j][n])
        {
            temp[k++] = strings[i++];
        }
        else if (strings[i][n] > strings[j][n])
        {
            temp[k++] = strings[j++];
        }
        else
        {
            if (strings[i] < strings[j])
            {
                temp[k++] = strings[i++];
            }
            else
            {
                temp[k++] = strings[j++];
            }
        }
    }
    
    while (i <= mid)
    {
        temp[k++] = strings[i++];
    }
    while (j <= right)
    {
        temp[k++] = strings[j++];
    }
    
    for (int l = 0; l < temp.size(); ++l)
    {
        strings[left + l] = temp[l];
    }
}

void mergeSort(vector<string>& strings, int left, int right, int n)
{
    if (left >= right)
    {
        return;
    }
    
    int mid = left + (right - left) / 2;
    mergeSort(strings, left, mid, n);
    mergeSort(strings, mid + 1, right, n);
    merge(strings, left, mid, right, n);
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer { strings };
    
    mergeSort(answer, 0, answer.size() - 1, n);
    
    return answer;
}