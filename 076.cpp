// 76. JadenCase 문자열 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/12951
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if (s.empty()) return "";  // 빈 문자열 예외 처리
    
    string ans;
    ans = toupper(s[0]);
    for(int i=1; i<s.size(); i++){
        if(s[i-1] == ' '){
            ans += toupper(s[i]);
        }
        else{
            ans += tolower(s[i]);
        }
    }
    return ans;
}