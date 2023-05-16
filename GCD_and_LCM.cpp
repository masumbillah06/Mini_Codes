#include<bits/stdc++.h> // based on euclidean algorithm.
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int n1 = a, n2 = b;
        if(a==0 && b==0) break;
        if(a<b) swap(a,b);
        int rem=1;
        if(a%b==0){
            cout << "GCD is: " <<  b << endl;
            cout << "LCM is: " << (n1*n2)/b << endl << endl;
        }
        else {
            while(rem>0)
                {
                    rem = a%b;
                    a = b;
                    b = rem;    
                }
                cout << "GCD is: " << a << endl;
                cout << "LCM is: " << (n1*n2)/a << endl << endl;
        }
    }
    return 0;
}
