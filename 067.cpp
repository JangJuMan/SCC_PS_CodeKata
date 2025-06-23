// 67. 둘만의 암호
// https://school.programmers.co.kr/learn/courses/30/lessons/155652
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    vector<bool> isSkip(26, false);
    for(char ch : skip){
        isSkip[ch - 'a'] = true;
    }
    
    vector<char> available;
    vector<int> alphaPos(26, -1);
    for(int i=0; i<26; ++i){
        if(!isSkip[i]){
            alphaPos[i] = available.size();
            available.emplace_back('a'+i);
        }
    }
    
    string ans;
    int step = available.size();
    for(char ch : s){
        int pos = alphaPos[ch - 'a'];
        ans += available[(pos + index) % step];
    }
    
    return ans;
}