// 96. 주차 요금 계산 / 구현(re/re)
// https://school.programmers.co.kr/learn/courses/30/lessons/92341
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int time_to_int(const string& time){    // "12:38" 형태
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> entrance_time;
    map<string, int> total_parking_time;
    
    for(const string& record : records){
        stringstream ss(record);
        string time, car, type;
        ss >> time >> car >> type;
        if(type == "IN"){
            entrance_time[car] = time_to_int(time);
        }
        else if(type == "OUT"){
            int in = entrance_time[car];
            int out = time_to_int(time);
            int diff = out - in;
            total_parking_time[car] += diff;
            entrance_time.erase(car);
        }
    }
    
    for(const auto& [car, in_time] : entrance_time){
        total_parking_time[car] += time_to_int("23:59") - in_time;
    }
    
    vector<int> ans;
    for(const auto& [car, time] : total_parking_time){
        int fee = fees[1];  // 기본요금
        if(time > fees[0]){ // 기본시간보다 초과해서 주차하면 추가금
            fee += ceil((time - fees[0]) / (double)fees[2]) * fees[3];
        }
        ans.emplace_back(fee);
    }
    return ans;
}