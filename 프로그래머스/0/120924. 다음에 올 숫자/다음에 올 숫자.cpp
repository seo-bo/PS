#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0, n = common.size();
    bool a = true, b = true;
    for(int i = 1; i < n -1; ++i)
    {
        if(abs(common[i] - common[i-1]) != abs(common[i] - common[i+1]))
        {
            a = false;
        }
        if(common[i] * common[i] != common[i-1] * common[i+1])
        {
            b = false;
        }
    }
    if(a)
    {
        int diff = common[1] - common[0];
        return common[n-1] + diff;
    }
    else
    {
        return common[n-1] * common[n-1] / common[n-2];
    }
}