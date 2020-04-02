#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

typedef struct //structure with type student
{
    int r;
    char n[30];
    int m;
}student;

void swap(student *ob1,student *ob2)//function to swap elements
{
    student tmp=*ob1;
    *ob1=*ob2;
    *ob2=tmp;
}

void sort(student arr[], int n)//function to sort the array of structures
{
    int i,j;
    for(i=0;i<(n-1);i++)
        for(j=0;j<(n-1-i);j++)
            if(arr[j].r>arr[j+1].r)
                swap(&arr[j], &arr[j+1]);
                
                
}
void print(student arr[],int n)//function to display the array of structures
{
    int i;
    printf("\n\n+-----------------------+---------------+-------------------------------------+-----------------+\n");
    printf("|\tSerial no\t|\tRoll no\t|\t\tName\t\t      |\t    Marks\t|\n");
    printf("+-----------------------+---------------+-------------------------------------+-----------------+\n");
    for(i=0;i<n;i++)
    printf("|\t%3d\t\t|\t%d\t|\t%-30s|%4d \t\t|\n", i+1, arr[i].r, arr[i].n, arr[i].m);
    printf("+-----------------------+---------------+-------------------------------------+-----------------+\n");
}
int main()
{   
    do// starting of do while loop
    {
        printf("\n1) Add students\n2) View students\n3) Quit\nEnter your choice:  ");
        int c;
        scanf("%d", &c);//Accepting the choice 
        if(c==1)
        {
            
	        int i=0; student arr;   
	        printf("Enter the roll number,name and marks of the student\n");
	        
	        printf("\nRoll No: ");
	        int roll;
	        scanf("%d%*c",&arr.r);// accepting roll number
	    
	        printf("Name: ");
	        char name[80];
	        scanf("%[^\n]%*c", arr.n);// accepting name
	        
	        printf("Marks: ");
	        int marks;
	        scanf("%d%*c", &arr.m);// accepting marks
	        
	        printf("\n");
	            
	            
	            FILE *fp;// creating file pointer
	            fp=fopen("marks.dat","ab");// opening file in appending mode
	            if(fp==NULL)// to check if file is opened successfully
	            {
	                printf("\nFile could not be opened\n");
	                exit(1);
	            }
	            
	            fwrite(&arr, sizeof(student), 1, fp);     //student details added
	            
	            printf("\nStudent details added to file marks.dat\n");
	            fclose(fp);//file is closed 
        }//if block closed
        
        else if(c==2)//to view student details after sorting according to roll numbers
        {
            student arr[max],s;//declaring array of type student
            int i=0;
	            FILE *fp;// creating file pointer
	            fp=fopen("marks.dat","rb");// opening file in reading mode
	            printf("\nReading data from file marks.dat\n");
	            if(fp==NULL)// to check if file is opened successfully
	            {
	                printf("\nFile could not be opened\n");
	                continue;
	            }
	            while(1)
	            {
	                fread(&s, sizeof(student), 1, fp);//to read student details from file
	                if(feof(fp))
	                break;
	                arr[i]=s; 
	                i++;
	            }
	            fclose(fp);
            sort(arr,i);// sorting the array of structures
            print(arr,i);// printing the array of structures
            
        }//end of if block
        
        else if(c==3)// for exiting
        {
            printf("\n\n............................ Thank You ...........................\n................... Developed by Madhusree Bera ..................\n");
            exit(0);
        }
        
        else
        printf("\nWrong choice. Enter again:  ");   
        
            
    }
    while(1);//End of while
    return 0;
}//end of main function