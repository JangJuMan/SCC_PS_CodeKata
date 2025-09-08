// 139. 택배 배달과 수거하기 / re : 풀었지만 방식이 다름
// https://school.programmers.co.kr/learn/courses/30/lessons/150369
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long ans = 0;
    int remainD = 0, remainP = 0;
    
    for(int i=n-1; i>=0; i--){
        remainD += deliveries[i];
        remainP += pickups[i];
        
        while(remainD > 0 || remainP > 0){
            remainD -= cap;
            remainP -= cap;
            ans += static_cast<long long>((i+1) * 2);
        }
    }
    return ans;
    
//     /* 내풀이 */
//     for(int idxD = n-1, idxP = n-1; idxD >= 0 || idxP >= 0; ){
//         int tmpCap = cap;
//         if(deliveries[idxD] == 0 && pickups[idxP] == 0){
//             idxD--;
//             idxP--;
//             continue;
//         }
        
//         ans += max(idxD+1, idxP+1) * 2;
        
//         // cout << idxD << endl;
//         while((tmpCap > 0 && idxD >= 0) || deliveries[idxD] == 0){
            
//             if(tmpCap >= deliveries[idxD]){
//                 tmpCap -= deliveries[idxD];
//                 deliveries[idxD] = 0;
//                 idxD--;
//             }
//             else{
//                 deliveries[idxD] -= tmpCap;
//                 tmpCap = 0;
//             }
//             // cout << idxD << " " << tmpCap << endl;
//         }
//         // cout << idxD << endl << endl;
        
        
//         tmpCap = cap;
//         while((tmpCap > 0 && idxP >= 0) || pickups[idxP] == 0){
//             if(tmpCap >= pickups[idxP]){
//                 tmpCap -= pickups[idxP];
//                 pickups[idxP] = 0;
//                 idxP--;
//             }
//             else{
//                 pickups[idxP] -= tmpCap;
//                 tmpCap = 0;
//             }
//         }
//     }
//     return ans;
}