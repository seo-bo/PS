#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    bool ok = false;
    for(auto & i : db)
    {
        if(i == id_pw)
        {
            return "login";
        }
        if(i[0] == id_pw[0])
        {
            ok = true;
        }
    }
    if(ok)
    {
        return "wrong pw";
    }
    return "fail";
}