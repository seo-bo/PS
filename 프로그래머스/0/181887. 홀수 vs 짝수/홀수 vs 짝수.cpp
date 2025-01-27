#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int a =0, b = 0;
    for(int i =0 ;i <(int)num_list.size();++i)
    {
        if(i %2)
        {
            a += num_list[i];
        }
        else
        {
            b += num_list[i];
        }
    }
    return max(a,b);
}