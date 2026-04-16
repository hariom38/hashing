// Given an array arr[], the task is to find the maximum distance between two occurrences of an element. If no element has two occurrences, then return 0.

// Input: arr[] = [1, 1, 2, 2, 2, 1]
// Output: 5
// Explanation: distance for 1 is: 5-0 = 5, distance for 2 is : 4-2 = 2, So max distance is 5.


#include<bits/stdc++.h>
using namespace std;

//bruteforce approach
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code 
        //sabse phle sare same  element ki distance ek dosre se nikall li ,fir sabbi dintance ko temp me daal dia maximum distance ko output kr dia
        int n=arr.size();
        vector <int> temp={};
        
        for(int i=0;i<n;i++){
            int num=arr[i];
            for(int j=(n-1);j>=0;j--){
                if(arr[i]==arr[j]){
                    temp.push_back(j-i);
                }
            }
        }   
        int maximum=temp[0];
        for(int i=0;i<temp.size();i++){
            maximum=max(maximum, temp[i]);
        }
        
        return maximum;
    }
};
//tc------>o(n2)
//sc------>o(n)

//optimized approach
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int,int>mp;
        int maxi=0;
        
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) != mp.end()){
                maxi=max(maxi,i-mp[arr[i]]);
            }
            else{
                mp[arr[i]]=i;
            }
        }
        return maxi;
    }
};
//tc------->o(n)
//sc----->o(n)

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
     Solution obj;
    int maxi = obj.maxDistance(arr);
    cout<<"maximum distance between two occurrences of an element"<<" "<<maxi;

    return 0;
}
