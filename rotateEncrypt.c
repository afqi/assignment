//#include <stdio.h>
//
//int main ()
//
//{
//    int n, x;
//    int key = 1;
//    char str[100];
//    
//    printf("Choose an option:\n1. Encryption\n2. Decryption\n");
//    scanf ("%d", &x);
//    
//    switch(x)
//    case 1:
//{
//    printf("Enter a message to be encrypted: ");
//    scanf("%[^\n]s", str);
//    
//    for (n=0; (n<100 && str[n] != '\0'); n++)
//    {
//        if (str[n] == 'z' || str[n] == 'Z')
//        {
//        str[n] = 64;
//        }
//            if (str[n] <= 122 && str[n] >= 97)
//            {
//            str[n] = str[n] - 32;
//            }
//    str[n] = str[n] + key;
//    }
//    printf("Encrypted message: %s\n", str);
//break;
//
//
//      
//    case 2:
//        {
//        printf("Enter a message to be decrypted: ");
//        scanf("%[^\n]s", str);
//    
//        for (n=0; (n<100 && str[n] != '\0'); n++)
//        {
//            if (str[n] == 'z' || str[n] == 'Z')
//            {
//            str[n] = 64;
//            }
//                if (str[n] <= 122 && str[n] >= 97)
//                {
//                str[n] = str[n] - 32;
//                }
//        str[n] = str[n] - key;
//        }
//        printf("Decrypted message: %s\n", str);
//break;
//        }
//default:
//printf("No correct option was selected. Re-run the program.");
//}
//return 0;
//
//}