#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    for(auto & i : numbers)
    {
        i *= 2;
    }
    return numbers;
}