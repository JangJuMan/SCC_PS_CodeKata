// 115. 호텔대실 (timeline, priority_queue) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/155651
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int toMin(const string& time){
    int HH = stoi(time.substr(0, 2));
    int MM = stoi(time.substr(3, 2));
    return HH * 60 + MM;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> books;
    for(const auto& t : book_time){
        int start = toMin(t[0]);
        int end = toMin(t[1]) + 10;
        books.emplace_back(start, end);
    }
    sort(books.begin(), books.end());
    
    priority_queue<int, vector<int>, greater<int>> rooms;
    
    for(const auto& book : books){
        int start = book.first;
        int end = book.second;
        if(!rooms.empty() && rooms.top() <= start){ // 현재 가장 빨리 비는 방이 이번 예약 시작 전이면, 방 재사용
            rooms.pop();
        }
        rooms.emplace(end);
    }
    
    return rooms.size();    // 필요한 최소 방 개수 == 우선순위 큐 크기
}