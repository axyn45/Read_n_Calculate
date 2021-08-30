#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char scan_fun[10];
int i=0;

int para1,para2;

int read_file(FILE *fp);
int write_file(FILE *fp, int result);
int extract1(FILE *fp);
int extract2(FILE *fp);

int main(){
    FILE *fp_read=fopen("question.txt","r");
    FILE *fp_write=fopen("answer.txt","w");
    char c;
    c = fgetc(fp_read);
    while (c != EOF)
    {
        fputc(c, fp_write);
        c = fgetc(fp_read);
    }
    fseek(fp_read,0,SEEK_SET);
    fseek(fp_write,0,SEEK_SET);
    int fun_type=read_file(fp_read);
    if(fun_type>=1&&fun_type<=4){
        if(extract1(fp_read)==-1){
            printf("WRONG FORMAT!");
            return 0;
        }
        switch (fun_type)
        {
        case 1:
            write_file(fp_write, para1+para2);
            break;
        case 2:
            write_file(fp_write, para1-para2);
            break;
        case 3:
            write_file(fp_write, para1*para2);
            break;
        case 4:
            write_file(fp_write, para1/para2);
            break;
        
        default:
            break;
        }
    }
    return 0;
}

int read_file(FILE *fp){
    while(1){
        scan_fun[i]=fgetc(fp);
        if(scan_fun[i]=='('){
            scan_fun[i]=0;
            break;
        }
        else if(scan_fun[i]==0)
            return 0;
    }
    if(strcmp(scan_fun,"add"))
        return 1;
    else if(strcmp(scan_fun,"sub"))
        return 2;
    else if(strcmp(scan_fun,"muti"))
        return 3;
    else if(strcmp(scan_fun,"div"))
        return 4;
    else if(strcmp(scan_fun,"doubleMe"))
        return 5;
    else
        return 0;
}

int extract1(FILE *fp){
    int i=0;
    while(scan_fun[i]!='('){
        i++;
    }
    char *num=&scan_fun[i+1];
    if(sscanf(num,"%d%*c%d%*c",para1,para2)==EOF)
        return -1;
    return 0;
}

int extract2(FILE *fp){
    int i=0;
    while(scan_fun[i]!='('){
        i++;
    }
    char *num=&scan_fun[i+1];
    if(sscanf(num,"%d%*c",para1)==EOF)
        return -1;
    return 0;
}

int write_file(FILE *fp, int result){

}