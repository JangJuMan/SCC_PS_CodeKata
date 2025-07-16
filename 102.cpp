// 102. 다리를 지나는 트럭(큐) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/42583#
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int ans = 0, bridge_weight=0, idx=0;
    
    while(idx < truck_weights.size()){
        ans++;
        
        if(bridge.size() == bridge_length){     // 큐를 0으로 초기화하지 않고, 꽉 차면 pop
            bridge_weight -= bridge.front();
            bridge.pop();
        }
        
        if(bridge_weight + truck_weights[idx] <= weight){
            bridge.push(truck_weights[idx]);
            bridge_weight += truck_weights[idx];
            idx++;
        }
        else{
            bridge.push(0);
        }
    }
    return ans + bridge_length;
}

// int solution(int bridge_length, int weight, vector<int> truck_weights) {
//     queue<int> q;
//     int idx = 0, curWeight=0, ans=0;
    
//     for(int i=0; i<bridge_length; i++){
//         q.emplace(0);
//     }
    
//     while(idx < truck_weights.size()){
//         curWeight -= q.front();
//         q.pop();
//         if(curWeight + truck_weights[idx] <= weight){
//             q.emplace(truck_weights[idx]);
//             curWeight += truck_weights[idx];
//             idx++;
//         }
//         else{
//             q.emplace(0);
//         }
        
//         ans++;

//     }
//     ans += bridge_length;
//     return ans;
// }