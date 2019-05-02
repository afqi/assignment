#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int findIndex(char code[],char charFind){
  for(int i = 0 ; i < 26; i ++){
    if(code[i] == charFind){
      return i; //this function uses a for loop to find the index of an array that is used to assign the unencrypted letter to an encrypted one.
    }
  }
  return -1;
}

char* encrypt(char *message,char code[]){ //the encrypting function
  int length = strlen(message); //takes the string "message" and counts the total elements in the array
  char *encryptMessage = (char *) malloc(sizeof(char)*length); //changes the memory location 

  for(int i = 0; i < length; i++){
    int encryptIndex = toupper(message[i]) - 'A'; //assigns message to encryptIndex and changes it to uppercase
    if(encryptIndex >= 0 && encryptIndex < 26){ 
      encryptMessage[i] = code[encryptIndex]; //takes the value of the array "i" and assigns it index to the matching index value in the encrypted code.
    }else{
      encryptMessage[i] = message[i];
    }
  }
  return encryptMessage;
}

char *decrypt(char *message,char code[]){
  int length = strlen(message);
  char *decryptMessage = (char *) malloc(sizeof(char)*length); //line 30,31,32 are the same as the encrypt function
  for(int i = 0; i <length; i++){
    int decryptIndex = toupper(message[i]) - 'A';
    if(decryptIndex >= 0 && decryptIndex < 26){
      int codeIndex = findIndex(code,toupper(message[i])); //uses the findIndex function to find the index value in the encrypted alphabet and message, and makes that value an integer that will eventually revert the encryption.
      decryptMessage[i] = 'A' + codeIndex; //adds the codeIndex to revert original encryption
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
  printf("Original Message: %s\nEncrypted Message: %s\n",message,encryptMessage); //prints the returned message from the function
  break;
}

case 2: {
  char *decryptMessage = decrypt(message,code); //uses the function "decrypt"
  printf("Decrypted Message: %s\n",decryptMessage); //prints the returned message from the function
  break;
}
default: printf("No corrrect option was selected. Re-run."); //prints a message to tell user option 1 or 2 wasnt selected.
    }
        
    }