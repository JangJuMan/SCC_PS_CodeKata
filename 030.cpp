// 30. 가운데 글자 가져오기
// https://school.programmers.co.kr/learn/courses/30/lessons/12903
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if(s.size() & 1){
        return s.substr(s.size()/2, 1);
    }
    return s.substr(s.size()/2 - 1, 2);
}