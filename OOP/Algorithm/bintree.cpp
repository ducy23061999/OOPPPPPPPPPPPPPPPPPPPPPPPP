#include "stdio.h"
#include "stdlib.h"
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void insert(int n){
    node *current;
    node *parent;
    node *temp = (node *)malloc(sizeof(node));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL){
        root = temp;
    }else{
        current = root;
        parent = NULL;
        while(1){
            parent = current;
            if (temp->data < parent->data){
                current = current->left;
                if (current == NULL){
                    parent->left = temp;
                    return;
                }
            }else{
                current = current->right;
                if (current == NULL){
                    parent->right = temp;
                    return;
                }
            }      
            
        }
        
    }
}
void tienthutu(node *r){
    if (r != NULL){
        printf("%d ",r->data);
        tienthutu(r->left);
        tienthutu(r->right);
    };
    
}
int main(){
    int i;
    int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

    for(i = 0; i < 7; i++)
      insert(array[i]);
    tienthutu(root);
}