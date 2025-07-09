// 94. 타겟 넘버(dfs, 2갈래 분기)
// https://school.programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <vector>

using namespace std;

int ans = 0;

void dfs(const vector<int>& numbers, int target, int depth, int sum){
    if(depth == numbers.size()){
        if(sum == target){
            ans++;
        }
        return;
    }
    dfs(numbers, target, depth+1, sum+numbers[depth]);
    dfs(numbers, target, depth+1, sum-numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return ans;
}