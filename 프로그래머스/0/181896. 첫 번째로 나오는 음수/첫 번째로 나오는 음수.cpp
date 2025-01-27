#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    for(int i = 0; i<(int)num_list.size();++i)
    {
        if(num_list[i] < 0)
        {
            return i;
        }
    }
    return answer;
}