// 128. 디펜스 게임 (pq, 최적화) / 풀었지만 다시?
// https://school.programmers.co.kr/learn/courses/30/lessons/142085#
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    if(k >= (int)enemy.size()) return enemy.size(); // unsigned int -> int
    
    int enemySum = 0, round;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
    for(round=0; round<enemy.size(); round++){
        enemySum += enemy[round];
        maxHeap.emplace(enemy[round]);
        
        if(enemySum > n){
            if(k > 0){
                enemySum -= maxHeap.top();
                maxHeap.pop();
                k--;
            }
            else{
                break;
            }
        }
    }
    return round;
}