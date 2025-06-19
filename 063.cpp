// 63. 숫자 짝꿍. string append
// https://school.programmers.co.kr/learn/courses/30/lessons/131128
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    vector<int> countX(10, 0), countY(10, 0);
    
    for(const char& ch : X) { ++countX[ch - '0']; }
    for(const char& ch : Y) { ++countY[ch - '0']; }
    
    string result = "";
    for(int i=9; i>=0; --i){
        result += string(min(countX[i], countY[i]), '0'+i);
    }
    
    if(result.empty()){
        return "-1";
    }
    if(result[0] == '0'){
        return "0";
    }
    return result;
}