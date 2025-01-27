#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    int n = query.size();
    for(int i =0; i<n;++i)
    {
        int idx = query[i];
        if(i % 2)
        {
            arr = vector<int>(arr.begin() + idx, arr.end());          
        }
        else
        {
            arr = vector<int>(arr.begin(),arr.begin() + idx + 1);
        }
    }
    return arr;
}