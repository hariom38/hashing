
//find sum of range [l to r ] where (l<=r) using prefix sum;
// arr=====>[3 4 1 2 1 4]
// l=2,r=5
// ans------>8
#include<bits/stdc++.h>
using namespace std;

vector<int>prefix_array(vector<int >arr){
    int n=arr.size();
    vector<int>prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    return prefix;

}
int optimizedsum(vector<int>&prefix,int l ,int r){
   return prefix[r]-prefix[l-1];


}




int main(){
    cout<<"Radhe Radhe"<<endl;
    cout<<"Input size of array"<<endl;
    int n;
    cin>>n;

    vector<int >arr(n);
    cout<<"taking input element of array"<<endl;
    //original array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //prefix array 
    vector<int>prefix=prefix_array(arr);
    //int no of queries 
    cout<<"Input Q"<<endl;
    int q;
    cin >>q;

    for(int i=1;i<=q;i++){
        cout<<"Input l and r "<<endl;
        int  l;cin>>l;
        int r;cin>>r;
        cout<<optimizedsum(prefix,l,r);
    }
   
   
    return 0;

   
}
//tc---------->o(n+q) ,'n'-->to create prefix array and ,'"q"'---->for traversing queries 
//sc-------->o(n)-->b/s of prefix array
