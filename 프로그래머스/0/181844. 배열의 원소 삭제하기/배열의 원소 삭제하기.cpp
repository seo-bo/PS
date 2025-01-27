#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    set<int>s(delete_list.begin(),delete_list.end());
    for(auto & i : arr)
    {
        if(s.find(i) == s.end())
        {
            answer.push_back(i);
        }
    }
    return answer;
}