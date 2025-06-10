// 43. 크기가 작은 부분 문자열(문자열 대소비교, substr, stoll)
// https://school.programmers.co.kr/learn/courses/30/lessons/147355
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int cnt = 0;
    for(int i=0; i<=t.size() - p.size(); i++){
        if(t.substr(i, p.size()) <= p){
            ++cnt;
        }
    }
    return cnt;
}