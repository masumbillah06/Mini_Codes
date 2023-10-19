#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)


void binform(int n){
    if(n==0) cout << 0;
    bool start = false;
    for(int i=31; i>=0; i--){
        int bit = (n>>i)&1;
        if(bit) start = true;
        if(start) cout << bit ;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    binform(n);
    return 0;
}
