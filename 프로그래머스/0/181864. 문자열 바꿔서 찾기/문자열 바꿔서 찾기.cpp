#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(auto & i : myString)
    {
        i = (i == 'A') ? 'B' : 'A';
    }
    if(myString.find(pat) != string::npos)
    {
        return 1;
    }
    return answer;
}