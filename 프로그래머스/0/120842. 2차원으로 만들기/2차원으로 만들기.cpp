#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    int len = num_list.size();
    vector<int>temp;
    for(int i =0;i< len;++i)
    {
        if(i > 0 && i % n == 0)
        {
            answer.push_back(temp);
            temp.clear();
        }
        temp.push_back(num_list[i]);
    }
    answer.push_back(temp);
    return answer;
}