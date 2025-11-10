// 175. 퍼즐 조각 채우기 (bfs, 회전, 정규화, 인코딩) / rererere (3시간)
// https://school.programmers.co.kr/learn/courses/30/lessons/84021
#include <string>
#include <vector>
#include <set>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int dr[4] = {-1, 1, 0, 0};
constexpr int dc[4] = {0, 0, -1, 1};

// BFS로 gird에서 target_val에 속한 컴포넌트 추출
vector<vector<pair<int, int>>> extract_components(const vector<vector<int>>& grid, int target_val){
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<pair<int, int>>> components;
    
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            if(!visited[r][c] && grid[r][c] == target_val){
                // BFS 시작
                queue<pair<int, int>> q;
                vector<pair<int, int>> component;
                q.push({r, c});
                component.push_back({r, c});
                visited[r][c] = true;
                
                while(!q.empty()){
                    auto [cr, cc] = q.front();  q.pop();
                    for(int i=0; i<4; i++){
                        int nr = cr + dr[i];
                        int nc = cc + dc[i];
                        if(nr<0 || n<=nr || nc<0 || n<=nc)  continue;
                        if(!visited[nr][nc] && grid[nr][nc] == target_val){
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            component.push_back({nr, nc});
                        }
                    }
                }
                components.push_back(component);
            }
        }
    }
    return components;
}

vector<pair<int, int>> to_relative_coords(const vector<pair<int, int>>& component){
    int min_r = INT_MAX, min_c = INT_MAX;
    for(auto& p : component){
        min_r = min(min_r, p.first);
        min_c = min(min_c, p.second);
    }
    
    vector<pair<int, int>> rel;
    rel.reserve(component.size());
    for(auto& p : component){
        rel.push_back({p.first - min_r, p.second - min_c});
    }
    sort(rel.begin(), rel.end());
    return rel;
}

void normalize_coords(vector<pair<int, int>>& coords){
    int min_r = INT_MAX, min_c = INT_MAX;
    for(auto& p : coords){
        min_r = min(min_r, p.first);
        min_c = min(min_c, p.second);
    }
    for(auto& p : coords){
        p.first -= min_r;
        p.second -= min_c;
    }
}

// 90도 회전변환 nrot번 (상대좌표 기준) : (r, c) -> (c, -r)
vector<pair<int, int>> rotate_coords(const vector<pair<int, int>>& coords, int nrot){
    vector<pair<int, int>> cur = coords;
    for(int i=0; i<nrot; i++){
        for(auto& p : cur){
            int r = p.first;
            int c = p.second;
            p.first = c;
            p.second = -r;
        }
        normalize_coords(cur);  // 회전 후 기준 맞추기
    }
    return cur;
}


string encode_coords(vector<pair<int, int>>& coords){
    sort(coords.begin(), coords.end());
    string s;
    for(int i=0; i<coords.size(); i++){
        if(i != 0) s.push_back(';');
        s += to_string(coords[i].first);
        s.push_back(',');
        s += to_string(coords[i].second);
    }
    return s;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size();
    
    vector<vector<pair<int, int>>> blanks = extract_components(game_board, 0);  // 게임보드의 빈칸
    vector<vector<pair<int, int>>> pieces = extract_components(table, 1);       // 테이블의 블록
    
    int m = pieces.size();                  // 테이블 블록 개수
    vector<set<string>> piece_variants(m);  // 문자열로 인코딩하여 빠른 비교(+중복제거)
    vector<int> piece_sizes(m);
    for(int i=0; i<m; i++){                 // 각 블록에 대해 회전된 모든 버전의 키를 만듦(string)
        piece_sizes[i] = pieces[i].size();
        vector<pair<int, int>> rel = to_relative_coords(pieces[i]);     // 상대좌표로 변환
        for(int rot=0; rot<4; rot++){       // 4회 회전 (0, 90, 180, 270도)
            auto rotated = rotate_coords(rel, rot);
            string key = encode_coords(rotated);
            piece_variants[i].insert(key);
        }
    }
    
    int o = blanks.size();                  // blanks도 정규화된 키로 변경
    vector<string> blank_keys(o);
    vector<int> blank_sizes(o);
    for(int i=0; i<o; i++){
        normalize_coords(blanks[i]);
        blank_keys[i] = encode_coords(blanks[i]);
        blank_sizes[i] = blanks[i].size();
    }
    
    vector<bool> used(m, false);
    int ans = 0;
    
    for(int i=0; i<o; i++){ // 각 빈칸에 대해 같은 조각들 중 매칭되는 것이 있으면 사용
        for(int j=0; j<m; j++){
            if(used[j]) continue;   // 사용한 조각은 패스
            if(blank_sizes[i] != piece_sizes[j]) continue;  // 빈칸 개수가 다르면 패스
            if(piece_variants[j].count(blank_keys[i])){  // blank_key에 해당하는 값이 variant에 있으면 매칭
                used[j] = true;
                ans += blank_sizes[i];
                break;
            }
        }
    }
    
    return ans;
}