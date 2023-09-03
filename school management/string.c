#include <stdio.h>
#include <stdlib.h>


void string_print(char*str)
{
    int i;

    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}

int string_len(char*str)
{
    int i;
    for(i=0; str[i]; i++)
    {
    }
    return i;
}

void string_upperToLower(char*str)
{
    int i;
    for(i=0; str[i]; i++)
    {
        if (str[i]>='A'&&str[i]<='Z')
        {
            str[i]=str[i]+('a'-'A');
        }
    }
}

int string_compare(char* s1,char* s2)
{
    int i;
    for(i=0; s1[i] || s2[i] ; i++)
    {
        if (s1[i]!=s2[i])
        {
            return 0;
        }
    }
    return 1;
}

int string_compareNotcaseSenstive(char* s1,char* s2)
{
    int i;
    for(i=0; s1[i] || s2[i] ; i++)
    {
        if ( s1[i]!=s2[i] && s1[i]!=s2[i]+32 && s1[i]!=s2[i]-32 )
        {
            return 0;
        }
    }
    return 1;
}

void string_reverse(char*str)
{
    int temp,i,j=string_len(str);
    j--;
    for(i=0; i<=j; i++,j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}

void string_scan(char*str,int maxsize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for(; str[i]!='\n'&&i<maxsize-1; )
    {
        i++;
        scanf("%c",&str[i]);

    }
    str[i]=0;
}

int string_compareSort_NotCaseSensetive(char *str1,char*str2)
{
    int i;
    char c1,c2;
    for(i=0; str2[i]||str1[i]; i++)
    {
        c1=str1[i];
        c2=str2[i];
        if(c1>='a' && c1<'z')
        {
            c1=c1-32;
        }
        if(c2>='a' && c1<'z')
        {
            c2=c2-32;
        }
        if(c1>c2)
        {
            return 1;
        }
        else if (c1<c2)
        {
            return -1;
        }
    }
    return 0;
}
