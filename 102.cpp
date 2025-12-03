// 102. 다리를 지나는 트럭(큐, 시뮬레이션) / re(re)
// https://school.programmers.co.kr/learn/courses/30/lessons/42583#
#include <string>
#include <vector>
#include <queue>

using namespace std;

/* 2트 실패 */
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge_q;
    int ans=0, idx=0, n=truck_weights.size(), bridge_weight=0;
    
    while(idx < n){
        ++ans;
        
        if(bridge_q.size() == bridge_length){               // 다리가 꽉 찬 경우, 가장 먼저 들어간 트럭(or 0) pop
            bridge_weight -= bridge_q.front();
            bridge_q.pop();
        }
        
        if(bridge_weight + truck_weights[idx] <= weight){   // 트럭이 올라갈 수 있다면 트럭 올리기
            bridge_q.emplace(truck_weights[idx]);
            bridge_weight += truck_weights[idx];
            ++idx;
        }
        else{       // 트럭이 못올라간다면 0 올리기
            bridge_q.emplace(0);
        }
    }
    
    return ans + bridge_length;
}


// int solution(int bridge_length, int weight, vector<int> truck_weights) {
//     queue<int> bridge;
//     int ans = 0, bridge_weight=0, idx=0;
    
//     while(idx < truck_weights.size()){
//         ans++;
        
//         if(bridge.size() == bridge_length){     // 큐를 0으로 초기화하지 않고, 꽉 차면 pop
//             bridge_weight -= bridge.front();
//             bridge.pop();
//         }
        
//         if(bridge_weight + truck_weights[idx] <= weight){
//             bridge.push(truck_weights[idx]);
//             bridge_weight += truck_weights[idx];
//             idx++;
//         }
//         else{
//             bridge.push(0);
//         }
//     }
//     return ans + bridge_length;
// }


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