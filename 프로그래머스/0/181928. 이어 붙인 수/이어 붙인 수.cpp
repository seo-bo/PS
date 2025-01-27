#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int a = 0, b = 0,n = num_list.size();
    for(int i =0; i<n;++i)
    {
        if(num_list[i] &1)
        {
            a = a * 10 + num_list[i];
        }
        else
        {
            b = b * 10 + num_list[i];
        }
    }
    return a + b;
}