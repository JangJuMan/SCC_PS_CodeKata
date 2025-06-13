// 53. 명예의 전당, priority_queue
// https://school.programmers.co.kr/learn/courses/30/lessons/138477
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    ans.reserve(1000);
    for(size_t i=0; i<score.size(); ++i){
        if(i < k){
            minHeap.push(score[i]);
        }
        else{
            if(minHeap.top() < score[i]){
                minHeap.pop();
                minHeap.push(score[i]);
            }
        }
        ans.push_back(minHeap.top());
    }
    return ans;
}