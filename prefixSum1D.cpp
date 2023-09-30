#include<bits/stdc++.h> // 1D prefix sum
using namespace std;
const int N = 1e5;
int ara[N+5];
int pfsum[N+5];

void buildpfsum(int n){
    for(int i=1; i<=n; i++){
        cin >> ara[i];
        pfsum[i] = pfsum[i-1] + ara[i];
    }
}

void showpfsum(int n){
    for(int i=1; i<=n; i++){
        cout << pfsum[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;

    buildpfsum(n);
    showpfsum(n);

    int q; cin >> q;
    while (q--)
    {
        int x,y;
        cin >> x >> y;
        cout << pfsum[y] - pfsum[x-1] << endl;
    }
    return 0;
}
