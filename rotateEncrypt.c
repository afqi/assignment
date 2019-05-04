#include <stdio.h>
#include <ctype.h>
int main ()

{
    int n, x;
    int key = 0;
    char str[1024];
    
    printf("Choose an option:\n1. Encryption\n2. Decryption\n");
    scanf ("%d", &x);
    if(x <= 0 || x >= 3)
    {
        printf("No correct option was chosen. Try again.");
        return 0;
    }
    printf("Enter a key(0-26): ");
    scanf("%d", &key);
    if(key <= 0 || key >= 27)
    {
        printf("Key is invalid. Must be between 0-26");
        return 0;
    }
    
    switch(x)
    case 1:
{
    printf("Enter a message to be encrypted: ");
    scanf(" %[^\n]s", str);
    
    for (n=0; (n<1024 && str[n] != '\0'); n++)
    {
            while(str[n] >= 97 && str[n] <= 122)
            {
            str[n] = str[n] - 32;   
            
                if (str[n] >= 65 && str[n] <= 90)
                {
                str[n] = str[n] - 65;
                str[n] = ((str[n]+key)%26);
                str[n] = str[n] + 65;
                }
            }
    }
    
    printf("Encrypted message: %s\n", str);
break;


      
    case 2:
        {
        printf("Enter a message to be decrypted: ");
        scanf(" %[^\n]s", str);
    
        for (n=0; (n<1024 && str[n] != '\0'); n++)
        {
            if (str[n] >= 65 && str[n] <= 90)
            {
            str[n] = str[n] - 39;
            str[n] = ((str[n]-key)%26);
            str[n] = str[n] + 65;
            }

        }
        
        printf("Decrypted message: %s\n", str);
break;
        }
default:
printf("No correct option was selected. Re-run the program.");
}
return 0;
}