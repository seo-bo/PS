#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string str = to_string(x);
    int aa = 0;
    for(auto & i : str)
    {
        aa += i - '0';
    }
    return (x % aa == 0);
}