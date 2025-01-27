#include <bits/stdc++.h>

using namespace std;

string solution(string letter) {
    string answer = "";
    map<string, string> morse = 
    {
        {".-", "a"}, {"-...", "b"}, {"-.-.", "c"}, {"-..", "d"}, {".", "e"}, {"..-.", "f"},
        {"--.", "g"}, {"....", "h"}, {"..", "i"}, {".---", "j"}, {"-.-", "k"}, {".-..", "l"},
        {"--", "m"}, {"-.", "n"}, {"---", "o"}, {".--.", "p"}, {"--.-", "q"}, {".-.", "r"},
        {"...", "s"}, {"-", "t"}, {"..-", "u"}, {"...-", "v"}, {".--", "w"}, {"-..-", "x"},
        {"-.--", "y"}, {"--..", "z"}
    };
    string temp = "";
    for (auto &i : letter) 
    {
        if (i == ' ') 
        {
            if (!temp.empty() && morse.find(temp) != morse.end()) 
            {
                answer += morse[temp];
                temp = "";
            }
        } 
        else 
        {
            temp += i;
        }
    }
    if (!temp.empty() && morse.find(temp) != morse.end()) 
    {
        answer += morse[temp];
    }
    return answer;
}
