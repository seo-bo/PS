#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> pre = arr;
    for(int i =1;;++i)
    {
        for(auto & j : arr)
        {
            if(j >=50 && (j&1) == 0)
            {
                j /= 2;
            }
            else if (j < 50 && (j&1))
            {
                j = j*2 + 1;
            }
        }
        if(pre == arr)
        {
            return i-1;
        }
        pre = arr;
    }
    return answer;
}