#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/* Add element to the BST base on the product ID */

//using recusive
BST *addElement(BST *list, Product item) {
    BSTPtr *trav = &list;
    
    if(*trav != NULL) {
        if(item.prodID > (*trav)->data.prodID) {
            (*trav)->right = addElement((*trav)->right, item);
        } else if(item.prodID < (*trav)->data.prodID) {
            (*trav)->left = addElement((*trav)->left, item);
        }
    } else {
        BSTPtr newNode = malloc(sizeof(BST));
        
        if(newNode != NULL){
            newNode->data = item;
            newNode->right = NULL;
            newNode->left = NULL;
            
            *trav = newNode; 
        }
    }
    return *trav;
}
// using iterative method
void insertBST(BSTPtr *list, Product item) {
    BSTPtr *trav;
    for(trav = list; *trav != NULL;){
        trav = (item.prodID > (*trav)->data.prodID)? &(*trav)-> right : &(*trav)-> left;
    }

    BSTPtr newNode = malloc(sizeof(BST));
        
    if(newNode != NULL){
        newNode->data = item;
        newNode->right = NULL;
        newNode->left = NULL;
        
        *trav = newNode; 
    }
}

/* Delete element in the BST base on the product ID */

// using iterative method
void removeElement(BST *list, int prodID) {
    if(!isEmpty(list)){
        BSTPtr *trav, *node, temp;
        for(trav = &list; *trav!=NULL && (*trav)->data.prodID != prodID;){
            trav = (prodID > (*trav)->data.prodID)? &(*trav) -> right : &(*trav) -> left;
        }
        if((*trav)->data.prodID == prodID){
            if((*trav) -> left == NULL && (*trav) -> right == NULL){
                temp = *trav;
                free(temp);
                temp = *trav = NULL;
            } else if((*trav) -> left == NULL || (*trav) -> right == NULL){
                temp = *trav;
                *trav = ((*trav) -> left == NULL)? (*trav) -> right: (*trav) -> left;
                free(temp);
                temp = NULL;
            } else {
                for(node = &(*trav) -> left; (*node) -> right != NULL ; node = &(*node) -> right){}
                
                (*trav) -> data = (*node) -> data;
                if((*node) -> left != NULL){
                    (*node) = (*node) -> left;
                }
                free(*node);
                *node = NULL;
            }
        }
    }
}
//using recursive method
BST *deleteElement(BST *list, int prodID) {
    BSTPtr *trav, *node, pred, temp;
    trav = &list;
    if(!isEmpty(list)){ 
        if(prodID > (*trav)->data.prodID) {
            (*trav)->right = deleteElement((*trav)->right, prodID);
        } else if(prodID < (*trav)->data.prodID) {
            (*trav)->left = deleteElement((*trav)->left, prodID);
        }
        if(list->data.prodID == prodID){ 
            if((*trav) -> left == NULL && (*trav) -> right == NULL){
                temp = *trav;
                free(temp);
                temp = *trav = NULL;
            } else if((*trav) -> left == NULL || (*trav) -> right == NULL){
                temp = *trav;
                *trav = ((*trav) -> left == NULL)? (*trav) -> right: (*trav) -> left;
                free(temp);
                temp = NULL;
            } else {
                pred = min((*trav)->right);
                node = &pred;
                (*trav) -> data = (*node) -> data;
                if((*node) -> right != NULL){
                    (*node) = (*node) -> right;
                }

                free(*node);
                *node = NULL;
            }
        }
    }
    return *trav;
}

//Display BST all in the recusive method
void inorderBST(BST *list) {
    if(list != NULL) {
        inorderBST(list->left);
        displayProduct(list->data);
        inorderBST(list->right);
    }
}
void preorderBST(BST *list) {
    if(list != NULL) {
        displayProduct(list->data);
        preorderBST(list->left);
        preorderBST(list->right);
    }
}
void postorderBST(BST *list) {
    if(list != NULL) {
        postorderBST(list->left);
        postorderBST(list->right);
        displayProduct(list->data);
    }
}

//Other functions
BST *newBST() {
    BST *list = NULL;
    return list;
}
void initBST(BST **list) {
    *list = NULL;
}
bool isEmpty(BST *list) {
    return list == NULL;
}
Product createProduct(int id, char *name, int qty, float price) {
    Product p;
    
    p.prodID = id;
    strcpy(p.prodName, name);
    p.prodQty = qty;
    p.prodPrice = price;

    return p;
}

//use the following format {<id> | <prodName>} replacing the angular brakets with data
void displayProduct(Product prod) {
    printf("\n%5d | %10s", prod.prodID, prod.prodName);
}
BST *max(BST *list) {
    return (list->right != NULL) ? max(list->right): list;
}
BST *min(BST *list) {
    return (list->left != NULL) ? min(list->left): list;
}
bool isMember(BST *list, int prodID) {
    bool check = 0;
    if(isEmpty(list)){
        if(prodID == list->data.prodID){
            check = 1;
        }
        if(prodID > list->data.prodID){
            isMember(list->right, prodID);
        }
        if(prodID < list->data.prodID){
            isMember(list->left, prodID);
        }
    }
    return check;
}