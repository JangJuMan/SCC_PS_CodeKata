// 143. 이중 우선순위큐 / re.. (풀었지만, multiset 방법과 id 활용 방법 공부)
// https://school.programmers.co.kr/learn/courses/30/lessons/42628
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

/* multiset 을 활용한 개선버전 */
vector<int> solution(vector<string> operations) {
    multiset<int> s;
    
    for(const auto& op : operations){
        if(op[0] == 'I'){
            int num = stoi(op.substr(2));
            s.insert(num);
        }
        else if(op == "D 1"){
            if(!s.empty()){
                auto it = prev(s.end()); // 가장 마지막 원소의 it 반환
                s.erase(it);
            }
        }
        else if(op == "D -1"){
            if(!s.empty()){
                auto it = s.begin();    // 가장 처음 원소 반환
                s.erase(it);
            }
        }
    }
    
    if(s.empty()) return {0, 0};
    return {*prev(s.end()), *s.begin()};
    
}

/* pq 개선버전(pair, id, vec 방식) */
// vector<int> solution(vector<string> operations) {
//     priority_queue<pair<int, int>> maxHeap; // 값, id
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
//     vector<bool> valid(operations.size(), false);   // id 원소가 유효한지 확인
    
//     int id = 0; // 삽입 순번
//     for(const auto& op : operations){
//         if(op[0] == 'I'){
//             int num = stoi(op.substr(2));
//             maxHeap.push({num, id});
//             minHeap.push({num, id});
//             valid[id] = true;
//             id++;
//         }
//         else if(op == "D 1"){   // 최대값 삭제
//             while(!maxHeap.empty() && !valid[maxHeap.top().second]){
//                 maxHeap.pop();  // 이미 무효화된 값 정리
//             }
//             if(!maxHeap.empty()){
//                 valid[maxHeap.top().second] = false;
//                 maxHeap.pop();
//             }
//         }
//         else if(op == "D -1"){  // 최솟값 삭제
//             while(!minHeap.empty() && !valid[minHeap.top().second]){
//                 minHeap.pop();
//             }
//             if(!minHeap.empty()){
//                 valid[minHeap.top().second] = false;
//                 minHeap.pop();
//             }
//         }
//     }
    
//     while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();
//     while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
    
//     if(maxHeap.empty() || minHeap.empty()) return {0, 0};
//     return {maxHeap.top().first, minHeap.top().first};
// }

/* 내가 푼 방식(pq, hashMap) */
// vector<int> solution(vector<string> operations) {
//     priority_queue<int, vector<int>, less<int>> maxHeap;
//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     unordered_map<int, int> hashMap;
    
//     for(const string& oper : operations){
//         char op = oper[0];
//         int num = stoi(oper.substr(2));
        
//         if(op == 'I'){
//             minHeap.push(num);
//             maxHeap.push(num);
//             hashMap[num]++;
//         }
//         else if(op == 'D'){
//             if(num == 1){
//                 while(!maxHeap.empty() && hashMap[maxHeap.top()] == 0){
//                     maxHeap.pop();
//                 }
//                 if(!maxHeap.empty()){
//                     int maxElem = maxHeap.top();
//                     maxHeap.pop();
//                     hashMap[maxElem]--;
//                 }
//             }
//             else if(num == -1){
//                 while(!minHeap.empty() && hashMap[minHeap.top()] == 0){
//                     minHeap.pop();
//                 }
//                 if(!minHeap.empty()){
//                     int minElem = minHeap.top();
//                     minHeap.pop();
//                     hashMap[minElem]--;
//                 }
//             }
//         }
//     }
    
//     while(!maxHeap.empty() && hashMap[maxHeap.top()] == 0){
//         maxHeap.pop();
//     }
//     while(!minHeap.empty() && hashMap[minHeap.top()] == 0){
//         minHeap.pop();
//     }
//     if(minHeap.empty() && maxHeap.empty()){
//         return {0, 0};
//     }

//     return {maxHeap.top(), minHeap.top()};
// }