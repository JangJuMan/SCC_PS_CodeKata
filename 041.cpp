// 41. 이상한 문자 만들기 O(N)
// https://school.programmers.co.kr/learn/courses/30/lessons/12930
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool op = true;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            op = true;
            continue;
        }
        s[i] = op ? toupper(s[i]) : tolower(s[i]);
        op = !op;
    }
    return s;
}