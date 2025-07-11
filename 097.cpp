// 97. 모음사전(backtracking, 수식 유도) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/84512
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> vowels = {' ', 'A', 'E', 'I', 'O', 'U'};
string target ="";
string tmp = "";
int cnt = 0, ans = 0;

bool dfs(int depth){
    if(tmp.back() == ' '){
        cnt++;
        if(tmp.substr(0, tmp.size()-1) == target){
            ans = cnt;
            return true;
        }
        return false;
    }
    if(depth == 5){
        cnt++;
        if(tmp == target){
            ans = cnt;
            return true;
        }
        return false;
    }
    
    for(int i=0; i<vowels.size(); i++){
        tmp.push_back(vowels[i]);
        if(dfs(depth+1)){
            return true;
        }
        tmp.pop_back();
    }
    return false;
}

int solution(string word) {
    target = word;
    dfs(0);
    return ans-1;
}

/* 수식 계산 방법 */
// int solution(string word) {
//     string vowels = "AEIOU";
//     int answer = 0;
//     int mul[5] = {781, 156, 31, 6, 1}; // 각 자리별 가중치
//     // 5^4 + 5^3 + 5^2 + 5 + 1  = 781
//     // 5^3 + 5^2 + 5 + 1        = 156
//     // 5^2 + 5 + 1              = 31
//     // 5 + 1                    = 6
//     // 1                        = 1
//     for (int i = 0; i < word.size(); i++) {
//         int idx = vowels.find(word[i]);
//         answer += idx * mul[i] + 1;
//     }
//     return answer;
// }