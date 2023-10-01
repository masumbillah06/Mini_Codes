#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3;

int ara[N][N];
int pfsum[N][N];

void buildpfsum(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ara[i][j];
            pfsum[i][j] = ara[i][j] + pfsum[i-1][j] + pfsum[i][j-1] - pfsum[i-1][j-1];
        }
    }
}

void showpfsum(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << pfsum[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n; cin >> n;

    buildpfsum(n);
    showpfsum(n);

    int q; cin >> q;
    while (q--)
    {
        int a, b , c, d;
        cin >> a >> b >> c >> d;
        cout << pfsum[c][d] - pfsum[a-1][d] - pfsum [c][b-1] + pfsum[a-1][b-1];
    }

    return 0;
}
