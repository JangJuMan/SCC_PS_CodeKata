// 171. 억억단을 외우자 (배수 등장횟수) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/138475
// 끝 범위가 고정되어 있음
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> count(e+1, 0);
    for(int i=1; i<=e; i++){
        for(int j=i; j<=e; j+=i){
            count[j]++;
        }
    }
    
    vector<int> best(e+1);
    best[e] = e;
    for(int i=e-1; i>=0; i--){
        if(count[i] >= count[best[i+1]]){
            best[i] = i;
        }
        else{
            best[i] = best[i+1];
        }
    }
    
    vector<int> ans(starts.size());
    for(int i=0; i<starts.size(); i++){
        ans[i] = best[starts[i]];
    }
    return ans;
}