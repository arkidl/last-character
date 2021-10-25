
///LastChar input.txt output.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///read data from file and store the last chars of
///each word to str array
void readFromFile(char *filename, char *str);
void sortChars(char *str);
void print(char *str);
void writeToFile(char *filename, char *str);

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("There should be 3 arguments\n");
        return 1;
    }
    else if(argc>3)
    {
        printf("Only first 3 will be taken into consideration\n");
    }

    char *str;
    str = (char *) malloc(1000*sizeof(char));

    readFromFile(argv[1],str);
    sortChars(str);
    print(str);
    writeToFile(argv[2], str);

    return 0;
}

void readFromFile(char *filename, char *str)
{
    FILE *infile;
    infile = fopen(filename, "r");
    if(infile==NULL)
    {
        printf("Cant open the source file!");
        exit(-1);
    }
    int i=0;
    char c1, c2;
    fscanf(infile, "%c", &c2);
    c1=c2;
    while(!feof(infile))
    {
        if(c2==' '||c2=='\n')
        {
            str[i] = c1;
            i++;
        }
        c1=c2;
        fscanf(infile, "%c", &c2);
    }
    str[i] = c1;
    i++;
    str[i] = '\0';

    return;
}

void sortChars(char *str)
{
    int n = strlen(str), minIndex;

    for(int i=0; i<n-1; i++)
    {
        minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(str[minIndex]<str[j])
                minIndex = j;
        }
        char temp = str[i];
        str[i]= str[minIndex];
        str[minIndex] = temp;
    }
    return;
}

void print(char *str)
{
    int n = strlen(str);
    for(int i=0; i<n; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");
    return;
}

void writeToFile(char *filename, char *str)
{
    if(filename == NULL)
    {
        printf("Cant open the new file!");
        exit(-2);
    }

    FILE *outfile;
    outfile = fopen(filename, "w");
    int n = strlen(str);
    for(int i=0; i<n; i++)
    {
        fprintf(outfile, "%c ", str[i]);
    }
    printf("\nDone Successfully!\n");
    return;
}
