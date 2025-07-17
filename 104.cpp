// 104. 소수찾기(next_permutation, 6k+5, 6k+1) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/42839
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i=5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

int solution(string numbers) { 
    unordered_set<int> res;
    sort(numbers.begin(), numbers.end());
    int len = numbers.size();
    
    do{
        for(int i = 1; i <= len; i++){
            string part = numbers.substr(0, i);
            int num = stoi(part);
            res.insert(num);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    int ans = 0;
    for(int n : res){
        if(isPrime(n)) ans++;
    }
    return ans;
}

// bool isVisited[8] = {false};
// string inputStr = "";
// int ans = 0;
// unordered_set<int> hashSet;

// void dfs(int targetDepth, int depth, string res){
//     if(depth == targetDepth){
//         int val = stoi(res);
//         if(hashSet.count(val)) return;
//         hashSet.insert(val);
//         if(isPrime(val)) ans++;
//         return;
//     }
    
//     for(int i=0; i<inputStr.size(); i++){
//         if(!isVisited[i]){
//             isVisited[i] = true;
//             dfs(targetDepth, depth+1, res + inputStr[i]);
//             isVisited[i] = false;
//         }
//     }
// }

// int solution(string numbers) { 
//     inputStr = numbers;
    
//     for(int i=1; i<=numbers.size(); i++){
//         dfs(i, 0, "");
//     }
    
//     return ans;
// }