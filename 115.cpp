// 115. 호텔대실 (timeline, priority_queue) / re (2트 풀었지만 누적합 접근으로 다시)
// https://school.programmers.co.kr/learn/courses/30/lessons/155651
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* 2트 (누적합) */
int time_to_min(const string& time){    // for each에서 const 써서 여기서도 써줘야 함(상수성 유지)
    int HH = stoi(time.substr(0, 2));
    int MM = stoi(time.substr(3, 2));
    return HH * 60 + MM;
}

int solution(vector<vector<string>> book_time){
    int timeline[1451] = {0, }; // 하루는 1440분 + 청소 10분

    for(const auto& t : book_time){
        int start = time_to_min(t[0]);
        int end = time_to_min(t[1]) + 10;   // 청소시간 10분
        timeline[start] += 1;   // 입실 : 방 개수 증가
        timeline[end] -= 1;     // 퇴실/청소 : 방 개수 감소
    }

    int max_rooms = 0;
    int cur_rooms = 0;
    for(int i=0; i<=1440; i++){
        cur_rooms += timeline[i];               // 현 시점 사용중인 방 개수
        max_rooms = max(max_rooms, cur_rooms);  // 동시 사용 중인 방의 최대치 기록
    }
    
    return max_rooms;
}


/* 2트 (pq) */
// int time_to_min(const string& time){    // for each에서 const 써서 여기서도 써줘야 함(상수성 유지)
//     int HH = stoi(time.substr(0, 2));
//     int MM = stoi(time.substr(3, 2));
//     return HH * 60 + MM;
// }

// int solution(vector<vector<string>> book_time){
//     vector<pair<int, int>> books;
//     for(const auto& t : book_time){
//         int start = time_to_min(t[0]);
//         int end = time_to_min(t[1]) + 10;    // 퇴실시간 10분
//         books.emplace_back(start, end);
//     }
//     sort(books.begin(), books.end());

//     priority_queue<int, vector<int>, greater<int>> pq;  // minHeap(rooms);
//     for(const auto& b : books){
//         int start = b.first;
//         int end = b.second;

//         if(!pq.empty() && pq.top() <= start){
//             pq.pop();
//         }
//         pq.push(end);
//     }
 
//     return pq.size();
// }

// /* 1트 */
// int toMin(const string& time){
//     int HH = stoi(time.substr(0, 2));
//     int MM = stoi(time.substr(3, 2));
//     return HH * 60 + MM;
// }

// int solution(vector<vector<string>> book_time) {
//     vector<pair<int, int>> books;
//     for(const auto& t : book_time){
//         int start = toMin(t[0]);
//         int end = toMin(t[1]) + 10;
//         books.emplace_back(start, end);
//     }
//     sort(books.begin(), books.end());       // pair는 정렬 조건 안줘도 되나? 기본적으로 first -> second 기준으로 하나?
    
//     priority_queue<int, vector<int>, greater<int>> rooms;       // minHeap
    
//     for(const auto& book : books){
//         int start = book.first;
//         int end = book.second;
//         if(!rooms.empty() && rooms.top() <= start){ // 현재 가장 빨리 비는 방이 이번 예약 시작 전이면, 방 재사용
//             rooms.pop();
//         }
//         rooms.emplace(end);
//     }
    
//     return rooms.size();    // 필요한 최소 방 개수 == 우선순위 큐 크기
// }