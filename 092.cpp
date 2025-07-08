// 92. 프로세스 (queue) O(n^2)
// https://school.programmers.co.kr/learn/courses/30/lessons/42587
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    vector<int> counting(10, 0);
    for(int i=0; i<priorities.size(); i++){
        counting[priorities[i]]++;
        q.push({i, priorities[i]});
    }
    
    int cnt = 1;
    vector<int> ans(priorities.size(), 0);
    for(int i=9; i>=0; ){
        if(counting[i] > 0){
            counting[i]--;
            while(q.front().second != i){
                q.push(q.front());
                q.pop();
            }
            
            ans[q.front().first] = cnt++;
            if(q.front().first == location){
                break;
            }
            q.pop();
        }
        else{
            i--;
        }
    }
    
    return ans[location];
}