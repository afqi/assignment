#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int findIndex(char code[],char charFind){
  for(int i = 0 ; i < 26; i ++){
    if(code[i] == charFind){
      return i;
    }
  }
  return -1;
}

char* encrypt(char *message,char code[]){
  int length = strlen(message); //takes the string "message" and counts the total elements in the array
  char *encryptMessage = (char *) malloc(sizeof(char)*length); //changes the memory location 

  for(int i = 0; i < length; i++){
    int encryptIndex = toupper(message[i]) - 'A';
    if(encryptIndex >= 0 && encryptIndex < 26){
      encryptMessage[i] = code[encryptIndex];
    }else{
      encryptMessage[i] = message[i];
    }
  }
  return encryptMessage;
}

char *decrypt(char *message,char code[]){
  int length = strlen(message);
  char *decryptMessage = (char *) malloc(sizeof(char)*length);
  for(int i = 0; i <length; i++){
    int decryptIndex = toupper(message[i]) - 'A';
    if(decryptIndex >= 0 && decryptIndex < 26){
      int codeIndex = findIndex(code,toupper(message[i]));
      decryptMessage[i] = 'A' + codeIndex;
    }else{
      decryptMessage[i] = message[i];
    }
  }
  return decryptMessage;
}

int main(){
int x = 0;    
char message[1024];
printf("Input message:\n");
scanf("%[^\n]s", message);
char code[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";   //encrypted alphabet that assigns A to Q, B to W, etc...

printf("1. Encrypt the message\n2. Decrypt the message\n");
scanf("%d", &x);
switch(x)   // simple menu for either option
    {
case 1: {
  char *encryptMessage = encrypt(message,code); //uses the function "encrypt" to produce new message
  printf("Original Message: %s\nEncrypted Message: %s\n",message,encryptMessage);
  break;
}

case 2: {
  char *decryptMessage = decrypt(message,code);
  printf("Decrypted Message: %s\n",decryptMessage);
  break;
}
default: printf("No option was selected. Re-run.");
    }
        
    }