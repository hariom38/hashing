//elemnt with max freq and min freq 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int >arr(n);
    cout<<"Taking input of array element "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int ,int>mp;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]]=1;
        }else{
            mp[arr[i]]++;
        }
    }
    int elemt_max_freq=0;
    int max_freq=INT16_MIN;
    int elemt_min_freq=0;
    int min_freq=INT16_MAX;

    for(auto &pair :mp){
        if(pair.second>max_freq){
            max_freq=pair.second;
            elemt_max_freq=pair.first;
        }
        if(pair.second <min_freq){
            min_freq=pair.second;
            elemt_min_freq=pair.first;
        }


    }
    cout<<"element "<<elemt_max_freq<<" with max freq "<<max_freq<<endl;
    cout<<"element "<<elemt_min_freq<<" with min freq "<<min_freq<<endl;


    return 0;
}
//tc------>o(n)
//sc------>o(n)