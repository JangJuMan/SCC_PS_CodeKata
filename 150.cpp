// 150. 디스크 컨트롤러(pq) / 풀었는데, 좀 더 깔끔하게 풀어볼까
// https://school.programmers.co.kr/learn/courses/30/lessons/42627
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Job{
    int id, start, length;
};

struct Compare{ // 우선순위 : length -> start -> id
    bool operator()(const Job& a, const Job& b) const{
        if(a.length != b.length)    return a.length > b.length;
        if(a.start != b.start)      return a.start > b.start;
        return a.id > b.id;
    }
};

int solution(vector<vector<int>> jobs) {
    for(int i=0; i<jobs.size(); i++){
        jobs[i].push_back(i);   // 작업별 id 추가
    }
    sort(jobs.begin(), jobs.end()); // 요청시간 기준으로 정렬
    
    priority_queue<Job, vector<Job>, Compare> pq;
    
    int idx = 0;    // jobs에서 다음에 넣을 작업 index
    int curTime = 0;   // 현재 시간
    int totalTime = 0;  // 총 시간 합
    int n = jobs.size();
    
    while(idx < n || !pq.empty()){
        // 현재 시각까지 들어온 작업 대기 큐에 삽입
        while(idx < n && jobs[idx][0] <= curTime){
            pq.push({jobs[idx][2], jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        if(!pq.empty()){
            auto cur = pq.top();    pq.pop();
            curTime += cur.length;
            totalTime += (curTime - cur.start);
        }
        else{
            // 대기 큐가 비어있으면 다른 작업 시각으로 점프
            curTime = jobs[idx][0];
        }
    }
    return totalTime / n;
}

/* 내 풀이 */
// int solution(vector<vector<int>> jobs) {
//     sort(jobs.begin(), jobs.end());
    
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
//     int curTime = jobs[0][0], totalTime = 0;
//     for(int i=0; i<jobs.size(); ){
//         if(jobs[i][0] <= curTime){
//             pq.push({jobs[i][1], jobs[i][0]});
//             i++;
//         }
//         else{
//             if(!pq.empty()){
//                 auto job = pq.top();    pq.pop();
//                 curTime += job.first;
//                 totalTime += curTime - job.second;
//             }
//             else{
//                 curTime = jobs[i][0];
//             }
//         }

//     }
    
//     while(!pq.empty()){
//         auto job = pq.top();    pq.pop();
//         curTime += job.first;
//         totalTime += curTime - job.second;
//     }
    
//     return totalTime / jobs.size();
// }