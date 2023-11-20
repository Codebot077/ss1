#include<bits/stdc++.h>
using namespace std;
#define int long long
//FIFO
signed main(){
    int n,f;
    cin>>n>>f;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int>x;
    int j=0;
    int a=0;
    for(int i=0;i<n;i++){
        if(x.size()<f){
            if(find(x.begin(),x.end(),v[i])==x.end()){
                x.push_back(v[i]);
                a++;
            }
        }else{
            if(find(x.begin(),x.end(),v[i])==x.end()){
                x[j]=v[i];
                a++;
                j=(j+1)%f;
            }
        }
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    cout<<a<<endl;

}