#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    map<string,int>mm = {{"code",0},{"date",1},{"maximum",2},{"remain",3}};
    vector<vector<int>> answer;
    for(auto & i : data)
    {
        if(i[mm[ext]] < val_ext)
        {
            answer.push_back(i);
        }
    }
    sort(answer.begin(),answer.end(), [&] (const vector<int>&a, const vector<int>&b)
         {
             return a[mm[sort_by]] < b[mm[sort_by]];
         });
    return answer;
}