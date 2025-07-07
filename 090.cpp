// 90. 의상(unordered_map, combination)
// https://school.programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> comb;
    for(int i=0; i<clothes.size(); i++){
        ++comb[clothes[i][1]];
    }
    
    int ans = 1;
    for(const auto& [str, i] : comb){
        ans *= (i+1);
    }
    return ans - 1;
}