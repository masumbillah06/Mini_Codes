#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char paragraph[500];
    char word[20];
    int i, j, k, count_1=0, count_2=0;
    cout << "Enter the paragraph: ";
    gets(paragraph);
    cout << "Enter the word: " ;
    gets(word);

    for (i=0; i<strlen(paragraph); i++){
        if(word[0] == paragraph[i]){
            for(j=i, k=0; k<strlen(word); j++, k++){
                if(word[k] == paragraph[j]){
                    count_1 ++;
                    if(count_1 == strlen(word)){
                        count_2 ++;
                    }
                }
                else break ;
            }
        }
        count_1 = 0;
    }

    cout << word << " found in the Paragraph is " << count_2 << "\n";
    return 0;
}