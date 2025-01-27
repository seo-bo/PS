#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int sum = 0;
    for(auto & i : arr)
    {
        sum += i;
    }
    return (double)sum / (int)arr.size();
}