#include<stdio.h>
#include<string.h>


int touppercase(char s[])   //toupper case string
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if (s[i]>='a' && s[i]<='z')
            s[i]-=32;
    }
    printf("String in Upper Case = %s\n",s);
}

int tolowercase(char a[])  //string to lowercase
{
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>='A' && a[i]<='Z')
            a[i]+=32;
    }
    printf("String in Lower Case = %s\n",a);
}

int lenght(char a[])     //to find lenght of a string
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    printf("the lenght of the string is %d\n",i);
}
 
int vowels_char(char a[])   //to find vowels and other character in a string
{
    int vcount=0,ccount=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
        {
           vcount++; 
        }
        else
        {
            if(a[i]>='a'&&a[i]<='z' || a[i]>='A' && a[i<='Z'])
                ccount++;
        }
    }
        printf("the no of vowels is %d\n",vcount);
        printf("the no of others is %d\n",ccount);
    
} 

int no_of_words(char a[])   //to find how many words are there in a string
{
    int words=1;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]==32)
        {
            words++;
        }
    }
    printf("no of words is %d\n",words);
}

int valid(char a[])   //to check wheather a string is valid or not 
{
    for(int i=0;a[i]!='\0';i++)
    {
        if(!(a[i]>=65 && a[i]<=90)&&!(a[i]>=97 && a[i]<=122) && !(a[i]>=48 && a[i]<=57))   //conditions the string want to follow
        {
            printf("the string is not valid\n");
            return 0;
        }
    }
    printf("the entered string is valid\n");
}

int reverse(char a[])  //reversing a string by using another array
{
    char b[100];
    int i=0;
    while(a[i]!='\0') 
        i++;
    i=i-1;
    int j;
    for(j=0;i>=0;i--,j++)
        b[j]=a[i];
    b[j]='\0';
    printf("the reversed string is %s\n",b);
}

int reverse1(char a[])  //reversing a string by swapping char
{
    int i,j=0;
    char k;
    while(a[j]!='\0')
        j++;
    j=j-1;
    for(int i=0;a[i]!='\0';i++,j--)
    {
        if(i<j)
        {
            k=a[i];
            a[i]=a[j];
            a[j]=k;
        }
    }
    printf("%s\n",a);
}

//checking wheather a string is palindrome
void palindrome (char a[])
{
    int i,j=0;
    char temp,frist_string[100];
    strcpy(frist_string,a);
    printf("%s\n",frist_string);
    while (a[j]!='\0')
        j++;
    j=j-1;
    for(i=0;a[i]!='\0';i++,j--)
    {
        if (i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int result=strcmp(a,frist_string);
    if (result==0)
        printf("the given string is palindrome\n");
    else 
        printf("given string is not palindrome\n");
}

//to compare two string and checking they are palindrome
int compre()
{
    char a[100];
    char b[100];
    printf("Enter the frist string: ");
    gets(a);
    tolowercase(a);
    printf("Enter the secound string: ");
    gets(b);
    tolowercase(b);
    int compare=strcmp(a,b);
    if(compare==0)
        printf("two strings are palindrome\n");
    else 
        printf("strings are not palindrome\n");
}

//find duplicates in a string
int duplicate(char a[])          //doubt
{
    int last_duplicate=0,count=0;
    for(char i=0;a[i]!='\0';i++)
    {
        
        for(char j=1;a[j]!='\0';j++)
        {
            i=a[i];
            if(i==a[j] && i!=last_duplicate)
            {
                count++;
                printf("%c\n",i);
                last_duplicate=i;
            }
        }
    }
}

//finding duplicates by hash table
int duphash(char a[])
{
    int hash[26]={0};
    int i;
    for(i=0;a[i]!='\0';i++)
        hash[a[i]-97]++;
    for(int i=0;i<26;i++)
    {
        if(hash[i]>1)
            printf("the letter %c is repating %d times\n",i+97,hash[i]);
    }
}

//duplicate char in string for uppercase
int duphash1(char a[])
{
    int hash[26]={0};
    int i;
    for(i=0;a[i]!='\0';i++)
        hash[a[i]-65]++;
    for(int i=0;i<26;i++)
    {
        if(hash[i]>1)
            printf("the letter %c is repating %d times\n",i+65,hash[i]);
    }
}


int main()
{
    char a[100];
    printf("enter the string: ");
    gets(a);
    duphash1(a);
    return 0;
}