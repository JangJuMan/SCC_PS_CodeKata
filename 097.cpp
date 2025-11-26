// 97. 모음사전(backtracking, 수식 유도) / re(완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/84512
#include <string>
#include <vector>
#include <array>
#include <map>
#include <iostream>

using namespace std;

/* 2트 (수식)*/
int solution(string word) {
    array<int, 5> weight = {0, 0, 0, 0, 1};
    for(int i=3; i>=0; i--){
        weight[i] = 1 + 5 * weight[i+1];
    }
    
    map<char, int> wordOrder;
    wordOrder['A'] = 0;    wordOrder['E'] = 1;
    wordOrder['I'] = 2;    wordOrder['O'] = 3;    wordOrder['U'] = 4;    
    
    int ans = 0;
    for(int i=0; i<word.size(); i++){
        ans += 1 + wordOrder[word[i]] * weight[i];
    }
    return ans;
}

/* 2트 (완전탐색) */
// string target;
// string cur = "";
// map<char, int> wordOrder;
// array<char, 6> vowels = {' ', 'A', 'E', 'I', 'O', 'U'};
// int cnt, ans;

// bool dfs(int depth){
//     if(cur.back() == ' '){
//         cnt++;
//         if(cur.substr(0, cur.size()-1) == target){
//             ans = cnt;
//             return true;
//         }
//         return false;
//     }
    
//     if(depth == 5){
//         cnt++;
//         if(cur == target){
//             ans = cnt;
//             return true;
//         }
//         return false;
//     }
    
//     for(int i=0; i<vowels.size(); i++){
//         cur.push_back(vowels[i]);
//         if(dfs(depth+1)){
//             return true;
//         }
//         cur.pop_back();
//     }
//     return false;
// }

// int solution(string word) {
//     target = word;
//     wordOrder['A'] = 0; wordOrder['E'] = 1; 
//     wordOrder['I'] = 2; wordOrder['O'] = 3; wordOrder['U'] = 4;
    
//     dfs(0);
//     return ans - 1;
// }

/* 1트 dfs */
// vector<char> vowels = {' ', 'A', 'E', 'I', 'O', 'U'};
// string target ="";
// string tmp = "";
// int cnt = 0, ans = 0;

// bool dfs(int depth){
//     if(tmp.back() == ' '){
//         cnt++;
//         if(tmp.substr(0, tmp.size()-1) == target){
//             ans = cnt;
//             return true;
//         }
//         return false;
//     }
//     if(depth == 5){
//         cnt++;
//         if(tmp == target){
//             ans = cnt;
//             return true;
//         }
//         return false;
//     }
    
//     for(int i=0; i<vowels.size(); i++){
//         tmp.push_back(vowels[i]);
//         if(dfs(depth+1)){
//             return true;
//         }
//         tmp.pop_back();
//     }
//     return false;
// }

// int solution(string word) {
//     target = word;
//     dfs(0);
//     return ans-1;
// }

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