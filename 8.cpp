// //find largest and smallest subarray with sum==k in given array
// n=5
// arr--->3 1 3 -2 2
// k=4
// output -->Max Length: 4
//           Min Length: 2

#include<bits/stdc++.h>
using namespace std;
//bruteforce  approach
vector<int> max_and_min_subarray(vector<int> arr, int k){
    int n = arr.size();
    int max_len = 0;
    int min_len = INT_MAX;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];  // ✅ update sum

            if(sum == k){
                int len = j - i + 1;
                max_len = max(max_len, len);
                min_len = min(min_len, len);
            }
        }
    }

    if(min_len == INT_MAX) min_len = 0; // if no subarray found

    return {max_len, min_len};
}
// Time: O(n²)
// Space: O(1)

//optimized 
vector<int> max_and_min_subarray(vector<int>& arr, int k){
    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0;
    int max_len = 0;
    int min_len = INT_MAX;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];

        if(mp.find(sum - k) != mp.end()){
            int len = i - mp[sum - k];
            max_len = max(max_len, len);
            min_len = min(min_len, len);
        }

        // store first occurrence only (important for max length)
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    if(min_len == INT_MAX) min_len = 0;

    return {max_len, min_len};
}
//tc----->o(n)
//sc----->o(n)

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k; 
    cin >> k;

    vector<int> ans = max_and_min_subarray(arr, k);

    cout << "Max Length: " << ans[0] << endl;
    cout << "Min Length: " << ans[1] << endl;

    return 0;
}