#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto & i : myString)
    {
        i = toupper(i);
    }
    return myString;
}