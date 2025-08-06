// 117. 마법의 엘리베이터(완전탐색 or Greedy) / re
// https://school.programmers.co.kr/learn/courses/30/lessons/148653#
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* greedy */
int solution(int storey){
    int ans = 0;
    while(storey > 0){
        int digit = storey % 10;
        if(digit < 5){
            storey /= 10;
            ans += digit;
        }
        else if(digit > 5){
            storey = storey/10 + 1;
            ans += (10 - digit);
        }
        else{   // digit == 5
            int next = (storey/10) % 10;
            if(next >= 5){
                ans += 5;
                storey = storey/10 + 1;
            }
            else{   // next < 5
                ans += 5;
                storey /= 10;
            }
        }
    }
    return ans;
}


/* broute force */
// int ans = 100000000;
// void dfs(int num, int cnt){
//     if(num <= 1){
//         cnt += num;
//         ans = min(ans, cnt);
//         return;
//     }
//     dfs(num/10, cnt + num%10);      // 내림
//     dfs(num/10 + 1, cnt + (10 - num%10));  // 올림
// }

// int solution(int storey) {
//     dfs(storey, 0);
//     return ans;
// }
