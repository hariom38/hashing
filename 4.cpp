//count all  (i,j) pairs such that b[i]-b[j]==k

#include<bits/stdc++.h>
using namespace std;
int cout_all_pair(vector<int>&arr ,int k){
    int n=arr.size();
    unordered_map<int ,int>mp;
    
    int count=0;
    for(int i=0;i<n;i++){
        int complement=k+arr[i];
        if(mp.find(complement) !=mp.end()){
            count+=mp[complement];
        }
        mp[arr[i]]++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    
    cout<<"inpout the array element "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
       
    }
    cout<<"input target"<<endl;
    int k;
    cin>>k;
    cout<<"no of pairs whose arr[i]-arr[j] sum is "<<k<<"--> ";
    cout<<cout_all_pair(arr,k);
   
    
    
    return 0;
}
//tc------>o(n)
//sc------>o(n)
