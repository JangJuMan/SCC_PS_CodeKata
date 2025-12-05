// 104. 소수찾기(next_permutation, 6k+5, 6k+1) / re(re)
// https://school.programmers.co.kr/learn/courses/30/lessons/42839
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n){       // 1번 방법과 동일
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i=5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

int solution(string numbers) { 
    set<int> res;
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i = 1; i <= numbers.size(); i++){
            string part = numbers.substr(0, i);
            res.insert(stoi(part));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    int ans = 0;
    for(int n : res){
        if(isPrime(n)) ans++;
    }
    return ans;
}

// bool visited[8];
// string inputNum;
// set<int> nums;

// bool isPrime(int n){
//     if(n <= 1) return false;
//     if(n <= 3) return true;
//     if(n%2 == 0 || n%3 == 0) return false;
    
//     for(int i=5; i*i <= n; i+=6){
//         if(n % i == 0 || n%(i+2) == 0) return false;
//     }
//     return true;
// }

// void dfs(int targetDepth, int cur, string res){
//     if(cur == targetDepth){
//         int val = stoi(res);
//         nums.insert(val);
//         return;
//     }
    
//     for(int i=0; i<inputNum.size(); i++){
//         if(!visited[i]){
//             visited[i] = true;
//             dfs(targetDepth, cur+1, res+inputNum[i]);
//             visited[i] = false;
//         }
//     }
// }

// int solution(string numbers) {
//     inputNum = numbers;
//     for(int i=1; i<=numbers.size(); i++){
//         dfs(i, 0, "");
//     }
    
//     int ans = 0;
//     for(int n : nums){
//         if(isPrime(n)) ans++;
//     }
//     return ans;
// }