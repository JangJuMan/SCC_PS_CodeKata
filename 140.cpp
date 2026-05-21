// 140. 유사 칸토어 비트열(Devide and Conquer) / re (어렵네..), 2트 실패
// https://school.programmers.co.kr/learn/courses/30/lessons/148652
#include <string>
#include <vector>

using namespace std;

/* 2트 (실패. 이게 뭔말이냐 하;;;) */
constexpr int N_MAX=21;

long long pow5[N_MAX];  // 5^n 값 미리 계산
long long pow4[N_MAX];  // 4^n 값 미리 계산

long long countOnes(int n, long long x){
    if(x <= 0) return 0;
    if(n == 0) return 1;    // n=0일 때, "1" 하나만 존재
    
    long long blockSize = pow5[n-1];    // 한 블록의 크기
    long long blockIdx = (x-1) / blockSize;   // x가 위치한 블록(0~4)
    long long res = 0;
    
    if(blockIdx < 2){   // block Idx가 0, 1이면 blockIdx * pow4[n-1]
        res = blockIdx * pow4[n-1] + countOnes(n-1, x - blockSize * blockIdx);
    }
    else if(blockIdx == 2){ // 3번째 블록은 0이므로 탐색 종료
        res = blockIdx * pow4[n-1];
    }
    else{   // blockIdx가 3, 4이면, 3번째 블록은 0이기 때문에 blockIdx - 1하여 계산
        res = (blockIdx-1) * pow4[n-1] + countOnes(n-1, x - blockSize * blockIdx);
    }
    return res;
}

int solution(int n, long long l, long long r) {
    pow5[0] = 1, pow4[0] = 1;
    for(int i=1; i<=n; i++){
        pow5[i] = pow5[i-1] * 5;
        pow4[i] = pow4[i-1] * 4;
    }
    return (countOnes(n, r) - countOnes(n, l-1));
}

/* 1트 (실패) */
// long long pow5[21]; // 5^n 미리 저장

// long long dnc(int n, long long l, long long r){ // Devide and Conquer
//     if(n == 0){
//         return (l == 1 && r == 1) ? 1 : 0;
//     }
    
//     long long sub = pow5[n-1];
//     long long ans = 0;
    
//     for(int i=0; i<5; i++){ // 5개의 chunk로 분리
//         long long start = i * sub + 1;
//         long long end = (i+1) * sub;
        
//         if(r < start || l > end) continue;  // 구간 안 겹침
//         if(i == 2) continue; // 가운데 블록은 전부 0
        
//         long long nl = max(l, start) - start + 1;
//         long long nr = min(r, end) - start + 1;
//         ans += dnc(n-1, nl, nr);
//     }
//     return ans;
// }

// int solution(int n, long long l, long long r) {
//     pow5[0] = 1;
//     for(int i=1; i<=n; i++){
//         pow5[i] = pow5[i-1] * 5;
//     }
//     return dnc(n, l, r);
// }