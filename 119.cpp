// 119. 숫자 카드 나누기 (gcd) / re(2트 완료)
// https://school.programmers.co.kr/learn/courses/30/lessons/135807
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int mygcd_recursion(int a, int b){      // 함수 호출 오버헤드
    if(a % b == 0)
        return b
    return mygcd_recursion(b, a % b);
}

int mygcd_while(int a, int b){          // 반복문으로 개선
    while(b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB){
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];
    for(int i=1; i<arrayA.size(); i++){
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }

    int ansA = 0, ansB = 0;
    for(int i=0; i<arrayA.size(); i++){
        if(arrayB[i] % gcdA == 0) 
            ansA = 0;
        if(arrayA[i] % gcdB == 0) 
            ansB = 0;
    }
    return max(ansA, ansB);
}


/* 1트 */
// bool divisorCheck(const vector<int>& vec, int divisor){
//     for(int num : vec){
//         if(num % divisor == 0){
//             return false;
//         }
//     }
//     return true;
// }

// int solution(vector<int> arrayA, vector<int> arrayB) {
//     // array A의 모든 공약수
//     int gcdA = arrayA[0];
//     int gcdB = arrayB[0];
//     for(int i=1; i<arrayA.size(); i++){
//         gcdA = gcd(gcdA, arrayA[i]);
//         gcdB = gcd(gcdB, arrayB[i]);
//     }
    
//     int ans = 0;
//     if(divisorCheck(arrayA, gcdB)){
//         ans = max(ans, gcdB);
//     }
//     if(divisorCheck(arrayB, gcdA)){
//         ans = max(ans, gcdA);
//     }
//     return ans;   
// }