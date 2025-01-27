#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int a = 0, b = 1;
    for(auto & i : num_list)
    {
        a += i;
        b *= i;
    }
    return ((int)num_list.size() > 10) ? a : b;
}