#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int>v;
    for(auto & i : ingredient)
    {
        v.push_back(i);
        while(v.size() > 3)
        {
            int len = v.size() -1;
            if(v[len] == 1 && v[len-1] == 3 && v[len-2] == 2 && v[len -3] == 1)
            {
                for(int j =0; j<4;++j)
                {
                    v.pop_back();
                }
                answer++;
                continue;
            }
            break;
        }
    }
    return answer;
}