// 65. 문자열 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/140108
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ans=0, cntL=0, cntR=0;
    char charL = s[0];
    
    for(const char& c : s){
        if(cntL == 0 && cntR == 0){
            charL = c;
        }
        
        if(c == charL) ++cntL;
        else ++cntR;
        
        if(cntL == cntR){
            ++ans;
            cntL=0;
            cntR=0;
        }        
    }
    
    if(cntL > 0){
        ++ans;
    }
    return ans;
}