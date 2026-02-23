// 133. 조이스틱 (Greedy) / re 이런 풀이... 이해어렵네 (2트 실패)
// https://school.programmers.co.kr/learn/courses/30/lessons/42860#
#include <string>
#include <vector>
#include <array>

using namespace std;

/* 2트 : 어렵네.. 못품 */
constexpr array<int, 26> generateTable(){
    array<int, 26> table = {};  // 중괄호 안붙이면 컴파일에러(constexpr이라 0으로 명시적 초기화 필요)
    for(int i=0; i<26; i++){
        if(i<13)    table[i] = i;
        else    table[i] = 26-i;
    }
    return table;
}
constexpr array<int, 26> alpha = generateTable();

int solution(string name) {
    int verticalMove = 0;
    for(const auto& c : name){
        verticalMove += alpha[c - 'A'];
        // 혹은 verticalMove += min(c - 'A', 'Z' - c + 1);
    }
    
    int n = name.size();
    int horizontalMove = n-1;   // 좌->우 일직선 이동하는 경우
    for(int i=0; i<n; i++){
        int nextIdx = i+1;
        while(nextIdx < n && name[nextIdx] == 'A')  nextIdx++;
        horizontalMove = min(horizontalMove, i*2 + n-nextIdx);      // i까지 갔다가 되돌아와서 뒤 방향으로 nextIdx까지 가는 경우
        horizontalMove = min(horizontalMove, (n-nextIdx)*2 + i);    // 뒤로 nextIdx까지 갔다가 되돌아와서 i까지 가는 경우
    }
    return verticalMove + horizontalMove;
}

/* 1트 */
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
