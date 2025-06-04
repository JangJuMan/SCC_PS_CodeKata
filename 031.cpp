// 수박수박수박수박수박수?
// https://school.programmers.co.kr/learn/courses/30/lessons/12922
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ans = "";
    ans.reserve(n);
    
    for(int i=0; i<n/2; i++){
        ans += "수박";
    }
    if(n & 1){
        ans += "수";
    }
    return ans;
}