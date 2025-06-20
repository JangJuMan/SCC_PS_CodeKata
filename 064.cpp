// 64. 체육복 Greedy
// https://school.programmers.co.kr/learn/courses/30/lessons/42862
#include <string>
#include <vector>

using namespace std;
    
int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n+1, 0);
    for(const int& i : lost){
        --clothes[i];
    }
    for(const int& i : reserve){
        ++clothes[i];
    }
    for(int i=1; i<=n; ++i){
        if(clothes[i] < 0){
            if((i-1) >= 0 && clothes[i-1] > 0){
                --clothes[i-1];
                ++clothes[i];
            }
            else if((i+1) <= n && clothes[i+1] > 0){
                --clothes[i+1];
                ++clothes[i];
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=n; ++i){
        if(clothes[i] >= 0){
            ++cnt;
        }
    }
    return cnt;
}