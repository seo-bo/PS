#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int solution(vector<int> nums) {
    int answer = 0, len = nums.size();
    vector<bool>prime(5001,true);
    prime[0] = prime[1] = false;
    for(ll i = 2; i*i<=5000;++i)
    {
        if(prime[i])
        {
            for(ll j = i*i; j<=5000;j += i)
            {
                prime[j] = false; 
            }
        }
    }
    for(int i =0; i < len; ++i)
    {
        for(int j =i+1; j< len; ++j)
        {
            for(int k = j + 1; k < len; ++k)
            {
                ll sum = nums[i] + nums[j] + nums[k];
                if(prime[sum])
                {
                    answer++;
                }
            }
        }
    }
    return answer;
}