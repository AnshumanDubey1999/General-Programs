#include <stdio.h>
#include <string.h>
typedef struct Student{                                                //Student Structure
    int roll;
    char name[100];
    int marks;
}student;
int addStudent()
{
    FILE *file;
    file = fopen("marks.dat", "ab");                                  //Append Mode
    student s;
    printf("Enter Roll Number : ");
    scanf("%d%*c",&s.roll);
    printf("Enter Name : ");
    scanf("%[^\n]%*c", s.name);
    printf("Enter Marks : ");
    scanf("%d%*c",&s.marks);                                         //Taking input in studemt structure s
    fwrite(&s, sizeof(student), 1, file);                            //Storing that structure in binary file
    fclose(file);                                                    //Closing file
    printf("\nSuccessfully Added to Database!\n");
    return 0;
}
int getStudents(student s[])
{
    FILE *file;
    student temp;
    int i = 0;
    file = fopen("marks.dat", "rb");                                 //Reading mode
    if(file == NULL)                                                 //If no data input has taken place
        return 0;                                                    //Error occoured
    while(1)                                                         //Until the if statement in body breaks the loop
    {
        fread(&temp, sizeof(student), 1, file);                      //Taking input of the structure stored in file and storing in s
        if(feof(file))                                               //In case fread() says it's the end of the file
            break;
        s[i] = temp;
        i++;
        if(i==1000)
        {
            printf("Given Database has too many student records.\nShowing 1st 1000 entries.\n");
            break;
        }
    }
    fclose(file);                                                     //Closing file
    return i;                                                         //Function returns a non-zero number for every other case
}
int sortStudents(student s[], int size)
{
    int i, j;
    student temp;                                                     //Temporary variable
    for(i = 0; i < (size-1); i++)                                     //Bubble sort
    {
        for(j = 0; j < (size-i-1); j++)
        {
            if(s[j].roll>s[j+1].roll)
            {
                temp = s[j];                                                  //Swapping
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
        
    }
    return 0;
}
int printStudents(student s[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("----------------------------------------------\n");
        printf("%d. Roll Number : %d\n", (i+1), s[i].roll);
        printf("   Name        : %s\n", s[i].name);
        printf("   Marks       : %d\n", s[i].marks);                           //Printing
    }
    return 0;
}
int viewStudents()                                                    //Print all Inputs
{
    student s[1000];
    int i = getStudents(s);                                           //Gets all values from file in s and returns size of s
    if(i==0)                                                          //If no file found
    {
        printf("\nERROR : No Data Found.\n");
        return 0;
    }
    sortStudents(s, i);                                               //Sorting Data
    printStudents(s, i);                                              //Printing Data
    return 0;
}
int main()
{
    int c = 0;
    while(c!=3)
    {
        printf("\n--------Menu--------\n 1. Add student.\n 2. View students.\n 3. Quit.\n\nEnter your Choice : ");
        scanf("%d", &c);                                              //Choice input
        if(c==1)
            addStudent();                                             //Adds a student in the file
        else if(c==2)
            viewStudents();                                           //Displays all students
        else if(c!=3)                                                 //If choiceis neither 1, 2 or 3
            printf("Invalid Input. Please Try Again.\n\n");
    }
    printf("\nThank You.\n");
    return 0;
}