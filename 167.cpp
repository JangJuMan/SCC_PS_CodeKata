// 167. 표 병합 (union find) / re 아니 난이도가 이게 맞나...?
// https://school.programmers.co.kr/learn/courses/30/lessons/150366
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int n = 51;
vector<vector<string>> value(n, vector<string>(n));
vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n));
vector<vector<vector<pair<int, int>>>> group(n, vector<vector<pair<int, int>>>(n));

pair<int, int> findRoot(int r, int c){
    if(parent[r][c] == make_pair(r, c)) return {r, c};
    return parent[r][c] = findRoot(parent[r][c].first, parent[r][c].second);
}

void merge(int r1, int c1, int r2, int c2){
    auto [pr1, pc1] = findRoot(r1, c1);
    auto [pr2, pc2] = findRoot(r2, c2);
    if(pr1 == pr2 && pc1 == pc2) return;
    
    parent[pr2][pc2] = {pr1, pc1};  // 부모 병합
    
    string& v1 = value[pr1][pc1];
    string& v2 = value[pr2][pc2];
    
    if(v1.empty()){
        value[pr1][pc1] = value[pr2][pc2];
    }
    
    group[pr1][pc1].push_back(make_pair(pr2, pc2));
    for(const auto& g : group[pr2][pc2]){
        group[pr1][pc1].push_back(g);
    }
    group[pr2][pc2].clear();
}

void unmerge(int r, int c){
    auto [pr, pc] = findRoot(r, c);
    string keep = value[pr][pc];
    
    auto members = group[pr][pc];
    members.push_back(make_pair(pr, pc));
    
    for(auto& [i, j] : members){
        parent[i][j] = make_pair(i, j);
        value[i][j] = "";
        group[i][j].clear();
    }
    value[r][c] = keep;
}

vector<string> solution(vector<string> commands){
    vector<string> ans;
    
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            parent[i][j] = {i, j};
        }
    }
    
    for(const string& c : commands){
        stringstream ss(c);
        string type;
        
        ss >> type;
        if(type == "UPDATE"){
            vector<string> tokens;
            string t;
            while(ss >> t){
                tokens.emplace_back(t);
            }
            
            if(tokens.size() == 3){         //UPDATE r c value
                int r = stoi(tokens[0]);
                int c = stoi(tokens[1]);
                string val = tokens[2];
                auto [pr, pc] = findRoot(r, c);
                value[pr][pc] = val;
            }
            else if(tokens.size() == 2){    // UPDATE value1 value2
                string from = tokens[0];
                string to = tokens[1];
                for(int i=1; i<n; i++){
                    for(int j=1; j<n; j++){
                        auto [pr, pc] = findRoot(i, j);
                        if(value[pr][pc] == from){
                            value[pr][pc] = to;
                        }
                    }
                }
            }
        }
        else if(type == "MERGE"){
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            merge(r1, c1, r2, c2);
        }
        else if(type == "UNMERGE"){
            int r, c;
            ss >> r >> c;
            unmerge(r, c);
            
        }
        else if(type == "PRINT"){
            int r, c;
            ss >> r >> c;
            auto [pr, pc] = findRoot(r, c);
            // ans.emplace_back(value[pr][pc] == "" ? "EMPTY" : value[pr][pc]);
            ans.emplace_back(value[pr][pc].empty() ? "EMPTY" : value[pr][pc]);
        }
    }
    return ans;
}