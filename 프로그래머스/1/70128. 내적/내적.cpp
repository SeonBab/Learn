#include <vector>
#include <numeric>

int solution(std::vector<int> a, std::vector<int> b) {    
    return inner_product(a.begin(),a.end(),b.begin(),0);
}