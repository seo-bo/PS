#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int len = num_list.size();
    int a = num_list[len-1], b = num_list[len-2];
    if(a - b > 0)
    {
        num_list.push_back(a-b);
    }
    else
    {
        num_list.push_back(a*2);
    }
    return num_list;
}