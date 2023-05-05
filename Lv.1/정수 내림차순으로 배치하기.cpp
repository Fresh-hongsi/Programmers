#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>()); //문자열을 내림차순 정렬
    answer = stoll(str); //문자열을 long long으로 변환

    return answer;
}
