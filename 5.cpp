//count LL (i,j) pairs such that i<j and abs(b[i]-b[j])==k ,
//k>0---------->important 

#include<bits/stdc++.h>
using namespace std;
int count_pair(vector<int>&arr ,int k){
    int n=arr.size();
    unordered_map<int ,int>mp;
    //b[i]-b[j]==k------>b[i]=k+b[j];
    // -(b[i]-b[j]==k)==>b[i]=b[j]-k;
    int count=0;

    for(int i=0;i<n;i++){
        int comp1=k+arr[i];
        int comp2=arr[i]-k;

        if(mp.find(comp1) !=mp.end()){
            count+=mp[comp1];
        }
        if(k>0 && mp.find(comp2) !=mp.end()){
            count+=mp[comp2];
        }

        mp[arr[i]]++;
    }
    return count;


}
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
    cout<<count_pair(arr,k);
    return 0;

    //for()
}

