#include <string>
// 72. 달리기 경주
// https://school.programmers.co.kr/learn/courses/30/lessons/178871
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> nameToRank;
    for(int i=0; i<players.size(); i++){
        nameToRank[players[i]] = i;
    }

    for(const string& name : callings){
        int rank = nameToRank[name];
        if(rank == 0) continue;

        swap(players[rank], players[rank-1]);

        nameToRank[players[rank]] = rank;
        nameToRank[players[rank-1]] = rank-1;
    }

    return players;
}