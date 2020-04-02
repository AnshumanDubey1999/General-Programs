/*******************************************************************************************************************************
* Program name      : HashTable.c
*
* Author            : Anshuman Dubey
*
* Date created      : 02-11-2019
*
* Question          : Write a C program for Collision avoidance in Hash table using Linear Probing.
*
*********************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
 
typedef struct{
    int key;
    int value;
}item;
 
typedef struct {
    int flag;
    /* flag = 0 : data does not exist
     * flag = 1 : data exists
     * flag = 2 : data existed at least once*/
    item *data;
}hashtable_item;
 

 
void init_array(hashtable_item *array){
    int i;
    for (i = 0; i < MAX; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hashcode(int key){
    return (key % MAX);
}

void insert(hashtable_item *array, int *size, int key, int value){
    int index = hashcode(key);
    int i = index;
    item *new_item;
    new_item = (item *)malloc(sizeof(item));
    new_item->key = key;
    new_item->value = value;
    while (array[i].flag == 1){     //probing through the array until we reach an empty space
        if (array[i].data->key == key){       // case where already existing key matches the given key
            array[i].data->value = value;
            printf("Value updated!\n");
            return;
     
        }
        i = (i + 1) % MAX;
        if (i == index) {
            printf("Hash table Full!\n");
            return;
        }
    }
 
    array[i].flag = 1;
    array[i].data = new_item;
    *size += 1;
    printf("Key(%d) has been inserted!\n", array[i].data->key);
} 
 
void remove_element(hashtable_item *array, int *size, int key){
    int index = hashcode(key);
    int  i = index;
 
    while (array[i].flag != 0) {
        if (array[i].flag == 1  &&  array[i].data->key == key ) {
            array[i].flag =  2;
            array[i].data = NULL;
            *size -= 1;
            printf("Key (%d) has been removed!\n", key);
            return;
        }
        i = (i + 1) % MAX;
        if (i == index)
            break;
    }
    printf("The key doesn't exist!\n");
}

void display(hashtable_item *array, int size){
    if (size == 0){
        printf("Empty Hash Table!\n");
        return;
    }
    int i;
    printf("Items in the HashTable are:\n");
    for (i = 0; i < MAX; i++){
        item *current = array[i].data;
        if(current != NULL)
            printf("%5d : %5d\n",current->key, current->value);
    }
}
 
void main()
{
    hashtable_item *array;
    array = (hashtable_item *)malloc(sizeof(hashtable_item)*MAX);
    int size = 0, choice = 0, key, value, n, c;
    init_array(array);
    printf("\n  --: MENU :--\n");
    printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");

    while(choice!=4){
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Key: ");
            scanf("%d", &key);
            printf("Value: ");
            scanf("%d", &value);
            insert(array, &size, key, value);
        }
        else if(choice == 2){
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            remove_element(array, &size, key);
        }
        else if(choice == 3)
            display(array, size);
        else if(choice!=4)
            printf("Invalid Input!\n");
    }
}