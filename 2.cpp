//check if there are any two equal number in an array  at a distance <= K

#include<bits/stdc++.h>
using namespace std;
bool contin_nearby_dublicate(vector<int>& arr, int k){
    unordered_map<int,int>mp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        
        if(mp.find(arr[i]) !=mp.end() && i-mp[arr[i]]<=k){
            return true;
        }
        mp[arr[i]]=i;
    }
    return false;

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
    cout<<contin_nearby_dublicate(arr,k);
    
    
    return 0;
}
//tc------>o(n)
//sc------>o(n)