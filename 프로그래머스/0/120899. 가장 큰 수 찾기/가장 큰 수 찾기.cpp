#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    int p = -1, idx = -1;
    for(int i =0; i<(int)array.size();++i)
    {
        if(array[i] > p)
        {
            p = array[i];
            idx = i;
        }
    }
    vector<int> answer = {p,idx};
    return answer;
}