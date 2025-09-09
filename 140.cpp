// 140. 유사 칸토어 비트열(Devide and Conquer) / re (어렵네..)
// https://school.programmers.co.kr/learn/courses/30/lessons/148652
#include <string>
#include <vector>

using namespace std;

long long pow5[21]; // 5^n 미리 저장

long long dnc(int n, long long l, long long r){ // Devide and Conquer
    if(n == 0){
        return (l == 1 && r == 1) ? 1 : 0;
    }
    
    long long sub = pow5[n-1];
    long long ans = 0;
    
    for(int i=0; i<5; i++){ // 5개의 chunk로 분리
        long long start = i * sub + 1;
        long long end = (i+1) * sub;
        
        if(r < start || l > end) continue;  // 구간 안 겹침
        if(i == 2) continue; // 가운데 블록은 전부 0
        
        long long nl = max(l, start) - start + 1;
        long long nr = min(r, end) - start + 1;
        ans += dnc(n-1, nl, nr);
    }
    return ans;
}

int solution(int n, long long l, long long r) {
    pow5[0] = 1;
    for(int i=1; i<=n; i++){
        pow5[i] = pow5[i-1] * 5;
    }
    return dnc(n, l, r);
}