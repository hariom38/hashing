// 1. Two Sum  (leetcode)
 
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

  
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

#include<bits/stdc++.h>
using namespace std;
//brute force apporach 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int  i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
//tc-->o(n2)
//sc-->o(1)


//solve by hashmap---------->optimized 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            int complement=target-nums[i];
            if(mp.find(complement) !=mp.end()){
                return {mp[complement],i};
            }
            mp[nums[i]]=i;
        }
        return {};
        
    }
};//tc----->o(n)
//sc------>o(n)





//solve by two pointer approach-->by sorting the array  
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        //sort the vector based on array element 
        sort(temp.begin(),temp.end());
        int i=0;
        int j=n-1;
        while(i<j){
            int sum=temp[i].first+temp[j].first;
            if(sum==target){
                return{temp[i].second,temp[j].second};
            }
            else if(sum<target)       i++;
            else   j--;
        }
        return {-1,-1};
    }
};//tc--->o(n log(n))
//sc--->o(n)


int main(){
    cout<<"Radhe Radhe"<<endl;
    cout<<"Input size of array radhe"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"input array element radhe"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Input target"<<endl;
    int target;
    cin>>target;

    cout<<"twoSum index are "<<endl;
    // twoSum() is inside a class Solution
    // You cannot call it directly
    // You must create an object of the class
    Solution obj;
    vector<int> ans = obj.twoSum(arr, target);

    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
