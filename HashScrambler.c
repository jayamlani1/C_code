#include <stdio.h>
#include <string.h>


void createhash(int arr[128][2], int i, char c)
{
        arr[c][0] = c;
        arr[c][1] = i;
}

int findhash(char c, int arr[128][2])
{
        return arr[c][1];
}
void printrest(int len, char *str)
{
        for(int i=1; i< len;i++)
        {
                printf("%c", str[i]);
        }

}
void main(int nargs, char *argv[])
{

        int arr[128][2];
        for(int i=1;i<nargs;i++)
        {
                createhash(arr, i, argv[i][0]);
        }

        // First condition is to fing the opening string.

        int j = findhash('A', arr);
        printf("%s", argv[j]);

        int len = strlen(argv[j]);
        char c = argv[j][len-1];
        while(c!='Z')
        {
                j = findhash(c, arr);
                len = strlen(argv[j]);
                c = argv[j][len-1];
                printrest(len, argv[j]);
        }
printf("\n");
}
