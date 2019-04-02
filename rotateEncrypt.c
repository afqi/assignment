#include <stdio.h>

int main ()
// use '_' to represent a space
{
    int c = 0; //counter used for upcoming loop
    int key = 2;
    char str[50];
    printf("Enter a message to be encrypted: ");
    scanf("%s", str);
        for (c>0; (c<40 && str[c] != '\0'); c++);
        str[c] = str[c] + 2;
    
    printf("Encrypted message: %s\n", str);

}