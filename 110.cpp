// 110. 두 큐 합 같게 만들기(투포인터) / re(풀긴함)
// https://school.programmers.co.kr/learn/courses/30/lessons/118667
#include <vector>
#include <string>

using namespace std;

/* 2트 : 시뮬레이션 */
int solution(vector<int> queue1, vector<int> queue2) {
    int n = queue1.size();
    long long sum_1 = 0, sum_2 = 0;
    queue<int> q1, q2;
    for(int i=0; i<n; ++i){
        q1.emplace(queue1[i]);
        sum_1 += queue1[i];
        q2.emplace(queue2[i]);
        sum_2 += queue2[i];
    }
    
    long long target_sum = (sum_1 + sum_2) / 2;
    for(int ans=0; ans<3*n; ++ans){
        if(sum_1 == target_sum){
            return ans;
        }
        else if(sum_1 < target_sum){
            q1.emplace(q2.front());
            sum_1 += q2.front();
            sum_2 -= q2.front();
            q2.pop();
        }
        else if(sum_1 > target_sum){
            q2.emplace(q1.front());
            sum_2 += q1.front();
            sum_1 -= q1.front();
            q1.pop();
        }
    }
    return -1;
}

/* 1트 : 투포인터 */
int solution(vector<int> queue1, vector<int> queue2){
    long long sum1 = 0, sum2 = 0;
    for(int i : queue1) sum1 += i;
    for(int i : queue2) sum2 += i;

    long long total = sum1 + sum2;
    if(total & 1) return -1;

    vector<int> q1 = queue1;
    q1.insert(q1.end(), queue2.begin(), queue2.end());
    
    long long target = total / 2;
    int n = queue1.size();
    int limit = n * 3, ans = 0, idx1 = 0, idx2 = n;

    while(ans <= limit && idx1 < q1.size() && idx2 < q1.size()){
        if(sum1 == target){
            return ans;
        }
        else if(sum1 > target){
            sum1 -= q1[idx1++];
        }
        else if(sum1 < target){
            sum1 += q1[idx2++];
        }
        // else if(sum1 > target){
        //     queue2.emplace_back(queue1[idx1]);
        //     sum1 -= queue1[idx1++];
        // }
        // else if(sum1 < target){
        //     queue1.emplace_back(queue2[idx2]);
        //     sum1 += queue2[idx2++];
        // }
        ans++;
    }
    return -1;
}