// 139. 택배 배달과 수거하기 / re : 풀었지만 방식이 다름 (2트 : 풀었지만 방식이 다름)
// https://school.programmers.co.kr/learn/courses/30/lessons/150369
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 2트 성공 (근데 모범답안같은 풀이는 생각 못했음)*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long ans = 0;
    int idx_delivery = n-1, idx_pickup = n-1;
    while(idx_delivery >= 0 || idx_pickup >= 0){
        // cout << "idx_delivery : " << idx_delivery << " / idx_pickup : " << idx_pickup << endl;
        int cur_delivery_cap = cap, cur_pickup_cap = cap;
        int max_dist_delivery = 0, max_dist_pickup = 0;
        while(cur_delivery_cap > 0 && idx_delivery >= 0){
            if(deliveries[idx_delivery] == 0){
                idx_delivery--;
                continue;
            }
            max_dist_delivery = max(max_dist_delivery, idx_delivery + 1);
            deliveries[idx_delivery]--;
            cur_delivery_cap--;
            // cout << "\tcur_delivery_cap : " << cur_delivery_cap << " / deliveires[" << idx_delivery << "] : " << deliveries[idx_delivery] << endl;
        }
        while(cur_pickup_cap > 0 && idx_pickup >= 0){
            if(pickups[idx_pickup] == 0){
                idx_pickup--;
                continue;
            }
            max_dist_pickup = max(max_dist_pickup, idx_pickup + 1);
            pickups[idx_pickup]--;
            cur_pickup_cap--;
            // cout << "\tcur_pickup_cap : " << cur_pickup_cap << " / pickups[" << idx_pickup << "] : " << pickups[idx_pickup] << endl;
        }
        ans += (max(max_dist_delivery, max_dist_pickup)) * 2;
        // cout << "\t\tmax_dist_delivery : " << max_dist_delivery << " / max_dist_pickup : " << max_dist_pickup << " / ans : " << ans << endl;
    }
    return ans;
}

/* 1트 실패 */
// long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//     long long ans = 0;
//     int remainD = 0, remainP = 0;
    
//     for(int i=n-1; i>=0; i--){
//         remainD += deliveries[i];
//         remainP += pickups[i];
        
//         while(remainD > 0 || remainP > 0){
//             remainD -= cap;
//             remainP -= cap;
//             ans += static_cast<long long>((i+1) * 2);
//         }
//     }
//     return ans;
    
// //     /* 내풀이 */
// //     for(int idxD = n-1, idxP = n-1; idxD >= 0 || idxP >= 0; ){
// //         int tmpCap = cap;
// //         if(deliveries[idxD] == 0 && pickups[idxP] == 0){
// //             idxD--;
// //             idxP--;
// //             continue;
// //         }
        
// //         ans += max(idxD+1, idxP+1) * 2;
        
// //         // cout << idxD << endl;
// //         while((tmpCap > 0 && idxD >= 0) || deliveries[idxD] == 0){
            
// //             if(tmpCap >= deliveries[idxD]){
// //                 tmpCap -= deliveries[idxD];
// //                 deliveries[idxD] = 0;
// //                 idxD--;
// //             }
// //             else{
// //                 deliveries[idxD] -= tmpCap;
// //                 tmpCap = 0;
// //             }
// //             // cout << idxD << " " << tmpCap << endl;
// //         }
// //         // cout << idxD << endl << endl;
        
        
// //         tmpCap = cap;
// //         while((tmpCap > 0 && idxP >= 0) || pickups[idxP] == 0){
// //             if(tmpCap >= pickups[idxP]){
// //                 tmpCap -= pickups[idxP];
// //                 pickups[idxP] = 0;
// //                 idxP--;
// //             }
// //             else{
// //                 pickups[idxP] -= tmpCap;
// //                 tmpCap = 0;
// //             }
// //         }
// //     }
// //     return ans;
// }