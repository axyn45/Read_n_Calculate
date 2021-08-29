#include <stdio.h>
#include <stdlib.h>

char ctn_fun[10];

int main(){
    FILE *fp=fopen("question.txt","r");
    switch(read_line()){
        case 0:
            break;
        case 1:
            printf("The expression is in wrong format! Please recheck it in the file.\nThe program will quit...");
            return 0;
        case 2:
            printf("The expression has parameter(s) in wrong format or the number of parameters exceeds limit! Please recheck it in the file.\nThe program will quit...");
            return 0;
    }                                  //read_line return value: 0 - success, 1 - wrong format, 2 - wrong parameters
    
}