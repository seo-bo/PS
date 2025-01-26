#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) 
{
    int sum = 0;
    for(auto & i : numbers)
    {
        sum += i;
    }
    return (double)sum / (int)numbers.size();
}