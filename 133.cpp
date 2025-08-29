// 133. 조이스틱 (Greedy) / re 이런 풀이... 이해어렵네
// https://school.programmers.co.kr/learn/courses/30/lessons/42860#
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int n = name.size();
    int ans = 0;
    
    for(char c : name){ // 알파벳 맞추는 비용
        ans += min(c - 'A', 'Z' - c + 1);
    }
    
    int move = n-1;     // 단순 오른쪽 커서 이동 비용
    for(int i=0; i<n; i++){
        int next = i + 1;
        while(next < n && name[next] == 'A') next++;    // 연속된 A 구간 찾기
        move = min(move, i + min(i, n-next) + (n-next));    // i만큼 이동 + next로 이동하는 최소의 방법 + next에서 끝까지 이동
    }
    ans += move;    // 알파벳 맞추는 비용 + 최소 이동 비용
    return ans;
}
