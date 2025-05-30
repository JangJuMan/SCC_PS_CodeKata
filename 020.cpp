// 20. 정수 내림차순으로 배치하기
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    vector<int> decimal(10, 0);
    int nLength = 0;
    while(n){
        decimal[n%10]++;
        n /= 10;
        nLength++;
    }
    
    long long ans = 0;
    for(int i=9; i>=0; i--){
        while(decimal[i]-- > 0){
            ans *= 10;
            ans += i;
        }
    }
    return ans;
}

/* 더 느리지만 간단한 방법*/
// long long solution(long long n) {
//     // 숫자를 문자열로 변환 (각 자리 숫자 접근을 위함)
//     string s = to_string(n);

//     // 내림차순 정렬을 위해 greater<char> 사용
//     sort(s.begin(), s.end(), greater<char>());

//     // 정렬된 문자열을 다시 숫자로 변환
//     return stoll(s);
// }