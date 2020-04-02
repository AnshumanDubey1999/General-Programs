#include <stdio.h>
#include <string.h>
int addStudent()
{
    FILE *file;
    file = fopen("score.txt", "a");                                  //Append Mode
    int roll, marks;
    char name[100];
    printf("Enter Roll Number : ");
    scanf("%d%*c", &roll);
    printf("Enter Name : ");
    scanf("%[^\n]%*c", name);
    printf("Enter Marks : ");
    scanf("%d%*c", &marks);                                           //Taking input in studemt structure s
    fprintf(file, "%d|%s|%d\n", roll, name, marks);                  //Storing that values in text file
    fclose(file);                                                    //Closing file
    printf("\nSuccessfully Added to Database!\n");
    return 0;
}
int viewStudents()                                                    //Print all Inputs
{
    FILE *file;
    int i = 1, marks, roll;
    char name[100],bar;
    file = fopen("score.txt", "r");                                 //Reading mode
    if(file == NULL)                                                 //If no data input has taken place
    {
        printf("ERROR : No Data Found.\n");
        return 0;
    }
    while(1)                                                         //Until the if statement in body breaks the loop
    {
        fscanf(file, "%d%c %[^|]%*c %d%*c", &roll, &bar, name, &marks); //Taking input of the structure stored in file and storing in s
        if(feof(file))                                                //In case fread() says it's the end of the file
            break;
        printf("----------------------------------------------\n");
        printf("%d. Roll Number : %d\n", i, roll);
        printf("   Name        : %s\n", name);
        printf("   Marks       : %d\n", marks);                           //Printing
        i++;
    }
    fclose(file);                                                     //Closing file
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
    printf("\nThank You.\n");                                         //At choice = 3
    return 0;
}