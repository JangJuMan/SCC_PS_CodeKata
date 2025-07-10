// 96. 주차 요금 계산(re) / 구현
// https://school.programmers.co.kr/learn/courses/30/lessons/92341
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int TimeToMin(const string& time){
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> InTime;
    map<string, int> TotalParkingTime;
    
    for(const auto& record : records){
        stringstream SS(record);
        string Time, Car, Type;
        SS >> Time >> Car >> Type;
        
        if(Type == "IN"){
            InTime[Car] = TimeToMin(Time);
        }
        else{
            int In = InTime[Car];
            int Out = TimeToMin(Time);
            TotalParkingTime[Car] += Out - In;
            InTime.erase(Car);
        }
    }
    
    for(const auto& [Car, In] : InTime){
        TotalParkingTime[Car] += TimeToMin("23:59") - In;
    }
    
    vector<int> ans;
    for(const auto& [Car, T] : TotalParkingTime){
        int fee = fees[1];
        if(T > fees[0]){
            fee += ceil((T - fees[0]) / (double)fees[2]) * fees[3];
        }
        ans.push_back(fee);
    }
    return ans;
}