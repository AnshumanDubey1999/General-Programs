#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERR -9999999
#define space "                                                                                                    \0"

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *left, *right;
}BST;

void init(BST** aah){
    *aah = NULL;
}

int insertion(BST **aah, int n){
    if(*aah == NULL){
        BST *t;
        t = (BST *)malloc(sizeof(BST));
        if(t==NULL){
            printf("Memory Allocation Failure!");
            return ERR;
        }
        t->data = n;
        t->left = NULL;
        t->right = NULL;
        *aah = t;
        return 0;
    }
    else if((*aah)->data > n)
        return insertion(&((*aah)->left), n);
    return insertion(&((*aah)->right), n);
}

void inorder(BST *ah){
    if(ah==NULL)
        return;
    inorder(ah->left);
    printf("%3d, ", ah->data);
    inorder(ah->right);
}
void postorder(BST *ah){
    if(ah==NULL)
        return;
    postorder(ah->left);
    postorder(ah->right);
    printf("%3d, ", ah->data);
}
void preorder(BST *ah){
    if(ah==NULL)
        return;
    printf("%3d, ", ah->data);
    preorder(ah->left);
    preorder(ah->right);
}

BST** searching(BST *node, BST *parent, int n){
    if(node == NULL)
        return NULL;
    if(node->data == n){
        BST **t;
        t = (BST**)malloc(sizeof(BST*)*2);
        t[0] = node;
        t[1] = parent;
        return t;
    }
    if(node->data > n)
        return searching(node->left, node, n);
    return searching(node->right, node, n);
}
BST** leftMostNode(BST **ah){
    if((*ah)->left==NULL)
        return ah;
    return leftMostNode(&((*ah)->left));
}
int deletion(BST **aah, int n){
    BST **delete;
    delete = searching(*aah, NULL, n);
    if(delete == NULL){
        printf("Number not present!\n");
        return ERR;
    }
        
    BST *node, *parent, **successor, *t;
    node = delete[0];
    parent = delete[1];
    
    //Has 2 child
    if(node->left != NULL && node->right != NULL){
        successor = leftMostNode(&(node->right));
        node->data = (*successor)->data;
        t = *successor;
        free(t);
        *successor = NULL;
    }
    
    //Has no child
    else if(node->left == NULL && node->right == NULL){
        if(parent == NULL){
            free(node);
            *aah = NULL;
        }
        else if(parent->data>n){
            parent->left = NULL;
            free(node);
        }
        else{
            parent->right = NULL;
            free(node);
        }
    }
    
    //has right child
    else if(node->left == NULL && node->right != NULL){
        if(parent == NULL){
            *aah = node->right;
            free(node);
        }
        else if(parent->data>n){
            parent->left = node->right;
            free(node);
        }
        else{
            parent->right = node->right;
            free(node);
        }
    }
    
    //Has left child
    else if(node->left != NULL && node->right == NULL){
        if(parent == NULL){
            *aah = node->left;
            free(node);
        }
        else if(parent->data>n){
            parent->left = node->left;
            free(node);
        }
        else{
            parent->right = node->left;
            free(node);
        }
    }
    
    return 0;
}

int power(int x, int e){
    if(e==0)
        return 1;
    return x*power(x,e-1);
}

int printTree(BST *root){
    int h = height(root);
    int *coverage;
    coverage = (int *)malloc(sizeof(int)*h);
    char **strings;
    strings = (char**)malloc(sizeof(char*)*h);
    for (int i = 0; i < h; i++)
    {
        strings[i] = (char*)malloc(sizeof(char)*101);
        strings[i] = space;
        coverage[i] = 0;
    }                                                         //Initialization

    
}

int height(BST *aah){
    if(aah==NULL)
        return 0;
    int l, r;
    l = height(aah->left);
    r = height(aah->right);
    if(l>r)
        return 1+l;
    return 1+r;
}
int leaf(BST *aah){
    if(aah==NULL)
        return 0;
    if(aah->left==NULL && aah->right==NULL)
        return 1;
    
    return leaf(aah->left) + leaf(aah->right);
}          
int nodes(BST *aah){
    if(aah==NULL)
        return 0;
    return 1 + nodes(aah->left) + nodes(aah->right);
}   

int main(){
    BST *bst;
    int n, ch = 0;
    init(&bst);
    
    while(ch!=9){
        printf("\n  --: MENU :--\n");
        printf("1. Insertion\n2. Deletion\n3. Display(Inorder)\n4. Display(Preorder)\n5. Display(Postorder)\n6. Height\n7. Leaf\n8. Nodes\n9. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        
        if(ch==1){
            printf("Enter number: ");
            scanf("%d", &n);
            insertion(&bst, n);
        }
        else if(ch==2){
            printf("Enter number: ");
            scanf("%d", &n);
            if(!deletion(&bst, n))
                printf("%d successfully deleted!\n", n);
        }
        else if(ch==3 || ch==4 || ch==5){
            if(bst==NULL)
                printf("Empty List!\n");
            else{
                printf("Elements: ");
                if(ch==3)
                    inorder(bst);
                else if (ch==4)
                    preorder(bst);
                else
                    postorder(bst);
                printf("\n");
            }
        }
        else if(ch==6)
            printf("The height of the Binary Search Tree is: %d.\n", height(bst));
        else if(ch==7)
            printf("The number of leaves of the Binary Search Tree is: %d.\n", leaf(bst));
        else if(ch==8)
            printf("The number of nodes of the Binary Search Tree is: %d.\n", nodes(bst));
        else if(ch!=9)
            printf("Invalid Choice!\n");
    }
    return 0;
}
