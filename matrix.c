#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#define LINESIZE 150
#define LINES 30
void printFrame(char frame[LINES][LINESIZE])
{
    int i, j;
    for(i = 0; i < LINES; i++)
    {
        for( j = 0; j < LINESIZE; j++)
            printf("%c", frame[i][j]);
    }
}
void createFrame(char s1[LINESIZE], char frame[LINES][LINESIZE])
{
    int i, j;
    
    char character = ' ';
    for(i = 0; i < LINES; i++)
    {
        for (int j = 0; j < LINESIZE; j++)
        {
            srand(time(0)*i+character*j);                                         //To randomize the rand function with current time
            character = rand()%93 + 33;
            if(s1[j]==' ')
            {
                if(rand()%100<5)
                    frame[i][j] =  character;
                else
                    frame[i][j] = ' ';
            }
            else
            {
                if(rand()%100<85)
                    frame[i][j] =  character;
                else
                    frame[i][j] = ' ';
            }
        }
        strcpy(s1,frame[i]);
    }
}
int main()
{
    system("title MATRIX");
    system("color 04");
    system("mode 150, 30");
    char s1[LINESIZE+1];
    char s2[LINESIZE+1];
    s1[LINESIZE] = '\0';
    s2[LINESIZE] = '\0';
    int i, j;
    char character = ' ';
    char frame[LINES][LINESIZE];
    
    //Constructing s1

    for (int j = 0; j < LINESIZE; j++)
    {
        srand(time(0)+character*j);                                         //To randomize the rand function with current time
        character = rand()%93 + 33;
        if(rand()%10<6)
            s1[j] =  character;
        else
            s1[j] = ' ';
    }

    // createFrame(s1, frame);
    // printFrame(frame);

    //Constructing s2 based on s1

    for(i = 0; i < 9000; i++)
    {
        for (int j = 0; j < LINESIZE; j++)
        {
            srand(time(0)*i+character*j);                                         //To randomize the rand function with current time
            character = rand()%93 + 33;
            if(s1[j]==' ')
            {
                if(rand()%100<5)
                    s2[j] =  character;
                else
                    s2[j] = ' ';
            }
            else
            {
                if(rand()%100<85)
                    s2[j] =  character;
                else
                    s2[j] = ' ';
            }
        }
        Sleep(40);
        printf("%s", s2);
        strcpy(s1,s2);
    }
    return 0;
}