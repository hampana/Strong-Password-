#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
char password[1000];
void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void randomize ( char arr[], int n )
{
    srand ( time(NULL) );
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

int main()
{
    srand((unsigned int)(time(0)));
    int n, i, cp, sm,sc, count = 0, sp,total;
    char  capletters[1000],smallletters[1000];
    char spcl[]={',','!','@','#','$','%','^','&','*','(',')','_','-',']','[','{','}',':',';','<','>','.'};
    int numbers[1000];

    printf("Enter the number of digits in the password : ");
    scanf("%d", &n);

    printf("enter the number of  captail letters in the password : ");
    scanf("%d",&cp);

    printf("enter the number of small letters in the password : ");
    scanf("%d",&sm);

    printf("enter the number of special characters in the password : ");
    scanf("%d",&sc);
    for(i=0;i<n;i++)
    {
        numbers[i] = (rand() % 10);
        password[count] = numbers[i] + '0';
        count++;
    }

    for(i=0;i<cp;i++)
    {
        capletters[i] = 'A' + (rand() % 26);
        password[count] = capletters[i];
        count++;
    }
    for(i=0;i<sm;i++)
    {
        smallletters[i] = 'a' + (rand() % 26);
        password[count] = smallletters[i];
        count++;
    }
    for(i=0;i<sc;i++)
    {
        sp = (rand() % 22);
        password[count]=spcl[sp];
        count++;
    }
     if(count<=8)
    {
      printf("\t\n** LENGTH OF THE PASSWORD SHOULD BE GREATER THAN 8 **\n\n\t Length you have entered: %d \n",count);
    }
    else if(count>8 && count < 1000)
    {
       password[count] = '\0';

       printf("\t\n\tGenerated password:  %s\n",password);
       randomize(password, count);
       printf("\t\n\tStrong password:  %s\n,\t\n\t Length of your password is :  %d", password,count);
    }
    else if (count>1000)
    {
      printf("\t\n **LENGTH OF THE PASSWORD SHOULD BE LESS THEN  1000 **\n\n\t Length you have entered: %d \n",count);
    }
    return 0;
}
