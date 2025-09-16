// 145. 단어 변환 (BFS) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/43163
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool canTransform(const string& a, const string& b){
    int diff = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) diff++;
        if(diff > 1) return false;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);
    
    q.push({begin, 0});
    
    while(!q.empty()){
        auto [curr, step] = q.front();
        q.pop();
        
        if(curr == target) return step;
        
        for(int i=0; i<words.size(); i++){
            if(!visited[i] && canTransform(curr, words[i])){
                visited[i] = true;
                q.push({words[i], step+1});
            }
        }
    }
    return 0;
}