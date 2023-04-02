#include <iostream> 
#include <cmath>
#include <cstring>
using namespace std;
int  main()
{
   while(1){
   int i = 0, j, hex, rem, hexadecimal = 0;
   char bra[100];
   cin >> hex;
   while( hex>0){
         rem = hex%16;
         hex = hex/16;
         if (rem >=0 &&  rem <=9){
            bra[i] = rem + 48;
            i++;
         } 
         else if (rem >=10 &&  rem <=15){
            bra[i] = rem + 55;
            i++;
         }
   }
   for(j=strlen(bra)-1; j>=0 ; j--){
   cout << bra[j] ; 
   }
   cout <<endl;
   
   }
   return 0;
}