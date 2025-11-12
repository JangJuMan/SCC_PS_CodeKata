// 177. 상담원 인원 (pq) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/214288
#include <string>
#include <vector>
#include <queue>

using namespace std;

int getWaitTime(const vector<pair<int, int>>& reqByType, int numOfMentors){
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소힙
    int wait = 0;
    for(const auto& [start, duration] : reqByType){
        if(pq.size() < numOfMentors){   // 멘토가 상담중이 아니면 상담 진행
            pq.push(start + duration);  // 상담 끝나는 시간
        }
        else{   // 멘토가 상담중이면, 가장 빨리 끝나는 상담 다음에 바로 시작
            int earliest = pq.top();    pq.pop();
            if(earliest <= start){   // 상담 신청시간보다 일찍 끝나면 시간에 맞게 시작
                pq.push(start + duration);
            }
            else{                   // 상담 신청시간보다 늦게끝나면
                wait += (earliest - start);      // 해당 시간만큼 대기시간 누적 추가
                pq.push(earliest + duration);    // 상담 끝나는 시간을 기록
            }
        }
    }
    return wait;    // 총 상담대기시간을 반환
}

int solution(int k, int n, vector<vector<int>> reqs) {
    vector<vector<pair<int, int>>> reqByType(k+1);
    for(const auto& r : reqs)
        reqByType[r[2]].push_back({r[0], r[1]});
    
    vector<int> mentors(k+1, 1);
    vector<int> waits(k+1);
    for(int i=1; i<=k; i++)
        waits[i] = getWaitTime(reqByType[i], 1);
    
    int remain = n - k;
    while(remain--){
        int bestType = -1;
        int bestDelta = -1;
        int bestWait = -1;
        // 멘토를 1명 더 추가했을 때, 가장 대기시간 감소가 가장 큰 쪽으로 멘토 추가 배치
        for(int i=1; i<=k; i++){
            int cur = waits[i];
            int next = getWaitTime(reqByType[i], mentors[i]+1);
            int delta = cur - next;
            if(delta > bestDelta){
                bestDelta = delta;
                bestType = i;
                bestWait = next;
            }
        }
        mentors[bestType]++;
        waits[bestType] = bestWait;
    }
    
    int ans = 0;
    for(int i=1; i<=k; i++){
        ans += waits[i];
    }
    return ans;
}