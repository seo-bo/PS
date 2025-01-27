#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(auto & i : picture)
    {
        string str = "";
        for(auto & j : i)
        {
            for(int z = 0; z < k; ++z)
            {
                str += j;
            }
        }
        for(int z = 0; z <k; ++z)
        {
            answer.push_back(str);
        }
    }
    return answer;
}