#include <string>
#include <vector>
#include <regex> //regex 헤더파일 필요
using namespace std;

int solution(string s) { //regex_replace(대상문자열, regex(타겟문자열), 결과문자열)
    
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");   
  
    return stoi(s);
}
