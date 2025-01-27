#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0, idx = 0, len = numbers.size();
    for(int i =0; i<len;++i)
    {
        if(numbers[i] == 1)
        {
            idx = i;
            break;
        }
    }
    for(int i =1; i<k;++i)
    {
        idx = (idx + 2) % len; 
    }
    return numbers[idx];
}