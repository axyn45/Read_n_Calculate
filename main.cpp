#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char scan_fun[20];
int fun_type;
int para1, para2;
int count = 0;

int read_file(FILE *fp);
void write_file(FILE *fp, int result);
int extract1(FILE *fp);
int extract2(FILE *fp);

int main()
{
    FILE *fp_read = fopen("question.txt", "r");
    FILE *fp_write = fopen("answer.txt", "w");
    //char c;
    //c = fgetc(fp_read);
    //while (c != EOF || c != '\n')
    //{
    //    fputc(c, fp_write);
    //    c = fgetc(fp_read);
    //}
    //rewind(fp_read);
    //rewind(fp_write);
    //long cursor;
    while (1)
    {
        //cursor=ftell(fp_read);
        //while (c != '\n')
        //{
        //    if(c==EOF)
        //        break;
        //    fputc(c, fp_write);
        //    c = fgetc(fp_read);
        //}
        //fseek(fp_read,cursor,SEEK_SET);
        fun_type = read_file(fp_read);
        if (fun_type == -1)
            return 0;
        if (fun_type >= 1 && fun_type <= 4)
        {
            if (extract1(fp_read) == -1)
            {
                printf("WRONG FORMAT!");
                return 0;
            }
            switch (fun_type)
            {
            case 1:
                write_file(fp_write, para1 + para2);
                break;
            case 2:
                write_file(fp_write, para1 - para2);
                break;
            case 3:
                write_file(fp_write, para1 * para2);
                break;
            case 4:
                write_file(fp_write, para1 / para2);
                break;

            default:
                break;
            }
        }
        else if (fun_type == 5)
        {
            if (extract2(fp_read) == -1)
            {
                printf("WRONG FORMAT!");
                return 0;
            }
            write_file(fp_write, para1 * 2);
        }
        count++;
    }
    //debug the result
    printf("Successfully wrote results in \"answer.txt\"\n");
    fseek(fp_write, 0, SEEK_SET);
    // c = fgetc(fp_write);
    // while (c != EOF)
    // {
    //     printf("%c", c);
    //     c = fgetc(fp_write);
    // }
    return 0;
}

int read_file(FILE *fp)
{
    int i = 0;
    char name_container[10];
    //int p_bracket;
    //fseek(fp,-1,SEEK_CUR);
    if(!fgets(scan_fun,20,fp)){
        return -1;
    }
    while (scan_fun[i]!='(')
    {
        name_container[i]=scan_fun[i];
        i++;
        // scan_fun[i] = fgetc(fp);
        // if (scan_fun[i] == EOF)
        //     return -1;
        // if (scan_fun[i] == '(')
        // {
        //     //p_bracket = i;
        //     scan_fun[i] = 0;
        // }
        // else if (scan_fun[i] == '\n')
        // {
        //     //scan_fun[i] = 0;
        //     break;
        // }
        // i++;
    }
    name_container[i+1]=0;
    if (strcmp(name_container, "add") == 0)
    {
        //scan_fun[p_bracket] = '(';
        return 1;
    }
    else if (strcmp(name_container, "sub") == 0)
    {
        //scan_fun[p_bracket] = '(';
        return 2;
    }
    else if (strcmp(name_container, "muti") == 0)
    {
        //scan_fun[p_bracket] = '(';
        return 3;
    }
    else if (strcmp(name_container, "div") == 0)
    {
        //scan_fun[p_bracket] = '(';
        return 4;
    }
    else if (strcmp(name_container, "doubleMe") == 0)
    {
        //scan_fun[p_bracket] = '(';
        return 5;
    }
    else
        return 0;
}

int extract1(FILE *fp)
{
    int i = 0;
    while (scan_fun[i] != '(')
    {
        i++;
    }
    char *num;
    num = &scan_fun[i + 1];
    if (sscanf(num, "%d%*c%d%*c", &para1, &para2) == EOF)
        return -1;
    return 0;
}

int extract2(FILE *fp)
{
    int i = 0;
    while (scan_fun[i] != '(')
    {
        i++;
    }
    char *num = &scan_fun[i + 1];
    if (sscanf(num, "%d%*c", &para1) == EOF)
        return -1;
    return 0;
}

void write_file(FILE *fp, int result)
{
    switch(fun_type){
        case 1:
            fprintf(fp,"add(%d,%d)=%d\n",para1,para2,result);
            break;
        case 2:
            fprintf(fp,"sub(%d,%d)=%d\n",para1,para2,result);
            break;
        case 3:
            fprintf(fp,"muti(%d,%d)=%d\n",para1,para2,result);
            break;
        case 4:
            fprintf(fp,"div(%d,%d)=%d\n",para1,para2,result);
            break;
        case 5:
            fprintf(fp,"doubleMe(%d)=%d\n",para1,result);
            break;
    }
}