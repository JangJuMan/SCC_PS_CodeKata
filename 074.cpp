// 74. 신고 결과 받기(map, set, 구현)
// https://school.programmers.co.kr/learn/courses/30/lessons/92334
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, unordered_set<string>> reported_user;
    unordered_map<string, int> mail_cnt;

    for(const string& r : report){
        stringstream ss(r);
        string user_id, reported_id;
        ss >> user_id >> reported_id;
        reported_user[reported_id].insert(user_id);
    }

    for(auto& [reported_id, user_id_list] : reported_user){
        if(user_id_list.size() >= k){
            for(const string& id : user_id_list){
                mail_cnt[id]++;
            }
        }
    }

    vector<int> ans;
    for(const string& id : id_list){
        ans.push_back(mail_cnt[id]);
    }
    return ans;
}