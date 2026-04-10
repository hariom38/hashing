//elemnt with max freq and min freq 
#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Hello meet"<<endl;
    cout<<"Input size of array"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Input array element"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_freq_element;
    int min_freq_element;
    int max_freq=INT_MIN;
    int min_freq=INT_MAX;
    cout<<"Optimized approach"<<endl;
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto &pair :mp){
        if(pair.second>max_freq){
            max_freq=pair.second;
            max_freq_element=pair.first;
        }
        if(pair.second<min_freq){
            min_freq=pair.second;
            min_freq_element=pair.first;
        }
    }
    cout<<"MAX FREQUENCY ELEMENT--> "<<max_freq_element<<" with max freq--> "<<max_freq<<endl;
    cout<<"MIN FREQUENCY ELEMENT--> "<<min_freq_element<<" with min freq--> "<<min_freq<<endl;

    return 0;
}
