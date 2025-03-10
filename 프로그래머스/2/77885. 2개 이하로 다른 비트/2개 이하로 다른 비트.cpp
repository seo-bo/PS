#include <string>
#include <vector>

using namespace std;
typedef long long ll;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto & i : numbers)
    {
       if(i &1)
       {
          ll x =1;
           while(x & i)
           {
               x <<= 1;
           }
           x >>= 1;
           answer.push_back(i + x);
       }
        else
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}