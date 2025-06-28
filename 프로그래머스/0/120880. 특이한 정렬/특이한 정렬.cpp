#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    
    sort(numlist.begin(), numlist.end(), [n](int a, int b)
         {
             int distanceA = abs(a - n);
             int distanceB = abs(b - n);
             
             if (distanceA != distanceB)
             {
                 return distanceA < distanceB;
             }
             
             return a > b;
         });
    
    return numlist;
}