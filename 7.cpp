//count of number of subarrays with sum ==k
// nums=>[1,0,1,2,10,8]
// k=3
// ans=2

#include<bits/stdc++.h>
using namespace std;


// bruteforce approach 
int count_of_subarray(vector<int>&arr,int k){
    int count=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int countsum=0;
        for(int j=i;j>=0;j--){
            countsum+=arr[j];
            if(countsum==k){
                count++;
            }
        }
    }
    return count;
}
//tc--------->o(n2)
//sc---------->o(1)

//optimized code 
int count_of_subarray(vector<int>&arr,int k){
    unordered_map<int,int>mp;
    int sum=0;
    int count=0;
    mp[0]=1;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(mp.find(sum-k) !=mp.end()){
            count+=mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}
//tc------------>o(n)
//sc------------>o(n)

int main(){
    cout<<"Radhe Radhe"<<endl;
    cout<<"Input size of array"<<endl;
    int n;
    cin>>n;

    vector<int >arr(n);
    cout<<"taking input element of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Input k"<<endl;
    int k; cin>>k;
    cout<<"Otput is --> ";
    cout<< count_of_subarray(arr,k);
    
    return 0;

    //for()
}

