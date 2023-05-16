#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if(a==0 && b==0) break;
        if(a<b) swap(a,b);
        int rem=1;
        if(a%b==0) cout << b << endl;
        else {
            while(rem>0)
                {
                    rem = a%b;
                    a = b;
                    b = rem;    
                }
                cout << a << endl;
        }
    }
    return 0;
}
