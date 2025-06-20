// 66. 대충 만든 자판
// https://school.programmers.co.kr/learn/courses/30/lessons/160586
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> key(26, INT_MAX);
    
    for(const string& s : keymap){
        for(int i=0; i<s.size(); ++i){
            int idx = s[i] - 'A';
            key[idx] = min(key[idx], i+1);
        }
    }
    
    vector<int> ans;
    for(const string& s : targets){
        int cnt = 0;
        for(const char& c : s){
            int idx = c - 'A';
            if(key[idx] == INT_MAX){
                cnt = -1;
                break;
            }
            cnt += key[idx];
        }
        ans.emplace_back(cnt);
    }
    return ans;
}