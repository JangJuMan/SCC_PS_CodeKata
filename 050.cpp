// 50. 가장 가까운 같은 글자(unordered_map, vector)
// https://school.programmers.co.kr/learn/courses/30/lessons/142086
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    // 1. 문자열 범위가 넓은 경우에 좋음.
    // unordered_map<char, int> hashMap;
    // vector<int> ans(s.size(), -1);
    // for(size_t i=0; i<s.size(); ++i){
    //     if(hashMap.find(s[i]) != hashMap.end()){    // hashMap.count(s[i])
    //         ans[i] = i - hashMap[s[i]];
    //     }
    //     hashMap[s[i]] = i;
    // }
    // return ans;
    
    // 2. 알파벳은 26자밖에 안되니까 vector 쓰는게 더 효율적
    vector<int> alpha(26, -1);   // 사용하지 않는 index인 -1로 초기화 (0은 사용할 수 있는 index이기 때문에)
    vector<int> ans(s.size(), -1);
    for(size_t i=0; i<s.size(); ++i){
        if(alpha[s[i] - 'a'] != -1){
            ans[i] = i - alpha[s[i] - 'a'];
        }
        alpha[s[i] - 'a'] = i;
    }
    return ans;
}