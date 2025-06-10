// 42. 삼총사 : 백트래킹 C(N, 3)
// https://school.programmers.co.kr/learn/courses/30/lessons/131705
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(int depth, vector<int>& number, int sum, int startIdx){
    if(depth == 3){
        return (sum == 0) ? 1 : 0;
    }
    
    int count = 0;
    for(int i=startIdx; i<number.size(); ++i){
        count += dfs(depth+1, number, sum + number[i], i+1);
    }
    return count;
}

int solution(vector<int> number) {
    return dfs(0, number, 0, 0);
}