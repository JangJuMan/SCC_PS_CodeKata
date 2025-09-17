// 146. 베스트 앨범 (unordered_map, 구현) / re.. 풀었지만, 컨테이너 활용 더 잘하기
// https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays){
    unordered_map<string, int> genreTotal;
    unordered_map<string, vector<pair<int, int>>> songs;
    
    for(int i=0; i<genres.size(); i++){     // 장르별 총 재생수 계산
        genreTotal[genres[i]] += plays[i];
        songs[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> genreOrder(genreTotal.begin(), genreTotal.end());     // unordered_map → vector 복사
    sort(genreOrder.begin(), genreOrder.end(), [](const auto& a, const auto& b){    // 총 재생 수 기준으로 정렬
        return a.second > b.second;
    });
    
    vector<int> ans;
    for(const auto& [gen, total] : genreOrder){
        auto& vec = songs[gen];
        
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){  // 장르 내에서 재생수(높은순), 인덱스(낮은순) 정렬
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        
        for(int i=0; i<vec.size() && i<2; i++){ // 최대 2곡 선택
            ans.push_back(vec[i].first);
        }
    }
    return ans;
}

/* 나의 더러운 코드.. */
// vector<int> solution(vector<string> genres, vector<int> plays) {
//     unordered_map<string, vector<pair<int, int>>> hashMap;
//     unordered_map<string, int> genreTotal;
    
//     for(int i=0; i<genres.size(); i++){
//         if(hashMap.count(genres[i]) == 0){
//             genreTotal[genres[i]] = plays[i];
//             hashMap[genres[i]].push_back({i, plays[i]});
//             hashMap[genres[i]].push_back({-1, 0});
//             continue;
//         }
//         genreTotal[genres[i]] += plays[i];
//         pair<int, int> tmp;
//         pair<int, int> toReplace = {i, plays[i]};
//         for(int j=0; j<min((int)hashMap[genres[i]].size(), 2); j++){
//             // cout << "Check " << toReplace.second << " AND " << hashMap[genres[i]][j].second << endl;
//             if(toReplace.second > hashMap[genres[i]][j].second){
//                 // cout << "Swap " << toReplace.second << " AND " << hashMap[genres[i]][j].second << endl;
//                 tmp = hashMap[genres[i]][j];
//                 hashMap[genres[i]][j] = toReplace;
//                 toReplace = tmp;
//             }
//         }
//     }
    
//     vector<pair<string, int>> genre;
//     for(const auto& [gen, total] : genreTotal){
//         genre.push_back({gen, total});
//     }
    
//     sort(genre.begin(), genre.end(), [](const auto& a, const auto& b){
//        return a.second > b.second;
//     });
    
//     vector<int> ans;
//     for(int i=0; i<genre.size(); i++){
//         string gen = genre[i].first;
//         for(int j=0; j<min((int)hashMap[gen].size(), 2); j++){
//             if(hashMap[gen][j].first != -1){
//                 ans.push_back(hashMap[gen][j].first);
//             }
//         }
//     }
//     return ans;
// }