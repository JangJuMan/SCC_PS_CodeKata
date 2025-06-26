// 71. 개인정보 유효기간
// https://school.programmers.co.kr/learn/courses/30/lessons/150370
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

constexpr int DAY_OF_MONTH = 28, MONTH_OF_YEAR = 12;

int dateStrToInt(const string& date){   // 2021.05.02
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));
    return (y * MONTH_OF_YEAR * DAY_OF_MONTH) + (m * DAY_OF_MONTH) + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    unordered_map<char, int> termsType;
    for(const string& s : terms){       // A 12
        char type = s[0];
        int due = stoi(s.substr(2));
        termsType[type] = due;
    }

    int todayInt = dateStrToInt(today);
    vector<int> ans;
    for(int i=0; i<privacies.size(); ++i){  // 2021.05.02 A
        string date = privacies[i].substr(0, 10);
        int dateInt = dateStrToInt(date);
        char type = privacies[i][11];
        int due = dateInt + termsType[type] * DAY_OF_MONTH - 1;

        if(due < todayInt){
            ans.push_back(i+1);
        }
    }
    return ans;
}