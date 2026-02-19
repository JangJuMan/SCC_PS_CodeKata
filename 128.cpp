// 128. 디펜스 게임 (pq, 최적화) / 풀었지만 다시? (2트 완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/142085#
#include <string>
#include <vector>
#include <queue>

using namespace std;

/* 2트 */
int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, less<int>> pq;
    int ans = 0;
    for(int i=0; i<enemy.size(); i++){
        pq.emplace(enemy[i]);
        n -= enemy[i];
        
        if(n<0){        // 병사가 부족해지면
            if(k>0){    // 무적권 사용
                n += pq.top();  // 가장 큰 적의 수만큼 병사 복구
                pq.pop();
                k--;    
            }
            else{
                break;          // 무적권 없으면 게임 종료
            }
        }
        ans++;
    }
    return ans;
}

/* 1트 */
// int solution(int n, int k, vector<int> enemy) {
//     if(k >= (int)enemy.size()) return enemy.size(); // unsigned int -> int
    
//     int enemySum = 0, round;
//     priority_queue<int, vector<int>, less<int>> maxHeap;
    
//     for(round=0; round<enemy.size(); round++){
//         enemySum += enemy[round];
//         maxHeap.emplace(enemy[round]);
        
//         if(enemySum > n){
//             if(k > 0){
//                 enemySum -= maxHeap.top();
//                 maxHeap.pop();
//                 k--;
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     return round;
// }