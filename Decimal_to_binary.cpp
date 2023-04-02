#include <iostream> 
#include <cmath>
using namespace std;
int  main()
{
   int i = 0, dec, rem, binary = 0;; 
   cin >> dec;
   while( dec>0){
         rem = dec%2;
         dec = dec/2;        
         binary = binary + (rem * pow(10,i));
         i ++;
   }
   cout << binary << endl; 
   return 0;
}