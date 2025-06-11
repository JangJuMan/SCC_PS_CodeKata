// 45. 시저암호(단순치환) O(n)
// https://school.programmers.co.kr/learn/courses/30/lessons/12926
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    constexpr int alphabetCnt = 26;
    for(char& c : s){
        if('A' <= c && c <= 'Z'){
            c = 'A' + (c - 'A' + n) % alphabetCnt;
        }
        else if('a' <= c && c <= 'z'){
            c = 'a' + (c - 'a' + n) % alphabetCnt;
        }
        // 공백인 경우는 생략
    }
    return s;
}
