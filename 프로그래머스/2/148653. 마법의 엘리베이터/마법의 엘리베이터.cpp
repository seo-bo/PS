#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int solution(int storey) 
{
    int answer = 0, carry = 0;
    while(storey)
    {
        int pivot = storey % 10;
        if(pivot < 5)
        {
            answer += pivot;
            carry = 0;
        }
        else if(pivot > 5)
        {
            answer += 10 - pivot;
            carry = 1;
        }
        else
        {
            if(storey / 10 % 10 >= 5)
            {
                answer += 10 - pivot;
                carry = 1;
            }
            else
            {
                answer += pivot;
                carry =0 ;
            }
        }
        storey /= 10;
        storey += carry;
    }
    return answer;
}