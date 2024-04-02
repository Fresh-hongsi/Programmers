#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
string aeiou = "AEIOU";
bool flag=false;


void dfs(string word) {
     cnt++;

    if (word == target) {

        flag = true;
        return;
    }

    if (word.length() == 5) return;

    for (int i=0; i<5; i++) {
        dfs(word + aeiou[i]);

        if(flag==true){
            return;
        }
    }
}

int solution(string word) {   
    target = word;
    dfs("");

    return cnt;
}
