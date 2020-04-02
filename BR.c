#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,a,c;
    char pswrd[100],pswrd1[100],user[100],test_user[100],test_pswrd[100], nL;
    for(i=1;i<=5;i++)
    {
        if(i==1 || i==5)
        {
            for(j=1;j<=50;j++)
                printf("*");
        }
        else if(i==3)
            printf("*           BUS RESERVATION SYSTEM                *");
        else
        {
            for(j=1;j<=50;j++)
            {
                if(j==1 || j==50)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("\nWelcome to our online bus reservation system.");
    printf("\nProbably we can serve you a better service......\n");
    printf("\nBefore entering, there are two options for you: \n");
    printf("1. Sign in (if you are new to our system)\n");
    printf("2. Sign up (if you are already registered)\n");
    printf("\nNow, the choice is yours: ");
    scanf("%d",&a);
    scanf("%c", &nL);                                              
    if(a==1)
    {
        printf("\n    Enter your Name: ");
        gets(user);
        while(1)
        {
            printf("    Enter password: ");
            gets(pswrd);
            printf("    Confirm your password: ");
            gets(pswrd1);
            c=strcmp(pswrd,pswrd1);
            if(c==0)
            {
                printf("\nCONGRATS! You have successfully registered!!\n");
                break;
            }
            else
            {
                printf("\nPlease do carefully fill up your password\n");
            }
        }

    }
    if(a==2)
    {
        printf("\nLOG IN to your account: \n");
        while(1){
            printf("Your name: ");
            gets(test_user);
            printf("Password: ");
            gets(test_pswrd);
            if(strcmp(user,test_user)!=0 || strcmp(pswrd,test_pswrd)!=0)
            {
                printf("Enter correct password!\n");
            }
            else
                break;
        }
    }
    return 0;
}