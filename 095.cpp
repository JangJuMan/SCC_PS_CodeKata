// 95. k진수에서 소수 개수 구하기
// https://school.programmers.co.kr/learn/courses/30/lessons/92335
#include <string>
#include <vector>

using namespace std;

string getBaseK(int n, int k){
    if(n == 0) return "0";
    string baseK = "";
    while(n){
        baseK = to_string(n % k) + baseK;
        n /= k;
    }
    return baseK;
}

bool isPrime(long long n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(long long i=5; i * i <= n; i+=6){
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int ans = 0;  
    string baseK = getBaseK(n, k);
    
    string tmp = "";
    for(char c : baseK){
        if(c == '0'){
            if(!tmp.empty() && isPrime(stoll(tmp))) ans++;
            tmp = "";
            continue;
        }
        tmp += c;
    }
    
    if(!tmp.empty() && isPrime(stoll(tmp))) ans++;
    
    return ans;
}