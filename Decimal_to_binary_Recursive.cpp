#include <stdio.h> 
int dectobin(int decimal_number) 
{ 
 if (decimal_number == 0) 
  return 0; 
 else 
  return (decimal_number % 2 +10 * dectobin(decimal_number / 2)); 
} 
int main() 
{ 
 int decimal_number ; 
 printf("Enter a number: "); 
 scanf("%d",&decimal_number); 
 printf("%d",dectobin(decimal_number)); 
 return 0; 
}