#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct Task { 
    int id, start, finish, isAccepted;
}Task;
  
int myComp(const void* a, const void* b) {
    struct Task* a1 = (struct Task*)a; 
    struct Task* b1 = (struct Task*)b; 
    return a1->finish > b1->finish; 
} 

int main() 
{ 
    int amount, i, j, timeOccupied;
    Task *tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &amount);
    tasks = (Task *)malloc(sizeof(Task)*amount);
    printf("For each task, enter Task ID, Start Time and End Time:\n");
    for(i = 0; i < amount; i++){
        scanf("%d %d %d", &tasks[i].id, &tasks[i].start, &tasks[i].finish);
        tasks[i].isAccepted=0;
    }
    qsort(tasks, amount, sizeof(Task), myComp);
    timeOccupied = tasks[0].finish;
    tasks[0].isAccepted = 1;
    for(i = 1; i < amount; i++){
        if(tasks[i].start>=timeOccupied){
            tasks[i].isAccepted=1;
            timeOccupied = tasks[i].finish;
        }
    }
    printf("Tasks to be done for maximum efficiency:\n Sl.\tID\tStart\tFinish\n----------------------------------\n");
    j = 1;
    for(i = 0; i < amount; i++){
        if(tasks[i].isAccepted){
            printf("%3d.\t%d\t%d\t%d\n", j, tasks[i].id, tasks[i].start, tasks[i].finish);
            j++;
        }
    }
    return 0; 
} 
/*
1 3 5
2 4 7
3 5 8
4 6 10
5 7 11
6 8 12
7 9 13
8 10 14
9 11 15
10 12 16
*/