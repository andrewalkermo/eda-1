// Fig. 12.19: fig12_19.c
// Creating and traversing a binary tree
// preorder, inorder, and postorder
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// self-referential structure
struct treeNode {
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value
    struct treeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode789

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );

// function main begins program execution
int main( int argc, char **argv )
{
    unsigned int i; // counter to loop from 1-10
    int item; // variable to hold random values
    TreeNodePtr rootPtr = NULL; // tree initially empty

    srand( time( NULL ) );
    puts( "The numbers being placed in the tree are:" );

    // insert random values between 0 and 14 in the tree
    for ( i = 1; i <= 20; ++i ) {
        item = rand() % 100;
        printf( "%3d", item );
        insertNode( &rootPtr, item );
    } // end for

    // traverse the tree preOrder
    puts( "\n\nThe preOrder traversal is:" );
    preOrder( rootPtr );

    // traverse the tree inOrder
    puts( "\n\nThe inOrder traversal is:" );
    inOrder( rootPtr );

    // traverse the tree postOrder
    puts( "\n\nThe postOrder traversal is:" );
    postOrder( rootPtr ); printf("\n\n%s\n\n", argv[1]); exit(0);

} // end main

// insert node into tree
void insertNode( TreeNodePtr *treePtr, int value )
{
    // if tree is empty
    if ( *treePtr == NULL ) {
        *treePtr = malloc( sizeof( TreeNode ) );

        // if memory was allocated, then assign data
        if ( *treePtr != NULL ) {
            ( *treePtr )->data = value;
            ( *treePtr )->leftPtr = NULL;
            ( *treePtr )->rightPtr = NULL;
        } // end if
        else {
        printf( "%d not inserted. No memory available.\n", value );
        } // end else
    } // end if
    else { // tree is not empty
        // data to insert is less than data in current node
        if ( value < ( *treePtr )->data ) {
            insertNode( &( ( *treePtr )->leftPtr ), value );
        } // end if

        // data to insert is greater than data in current node
        else if ( value > ( *treePtr )->data ) {
            insertNode( &( ( *treePtr )->rightPtr ), value );
        } // end else if
        else { // duplicate data value ignored
            printf( "%s", "dup" );
        } // end else
    } // end else
} // end function insertNode

// begin inorder traversal of tree
void inOrder( TreeNodePtr treePtr )
{
    // if tree is not empty, then traverse
    if ( treePtr != NULL ) {
        inOrder( treePtr->leftPtr );
        printf( "%3d", treePtr->data );
        inOrder( treePtr->rightPtr );
    } // end if
}// end function inOrder

// begin preorder traversal of tree
void preOrder( TreeNodePtr treePtr )
{
    // if tree is not empty, then traverse
    if ( treePtr != NULL ) {
        printf( "%3d", treePtr->data );
        preOrder( treePtr->leftPtr );
        preOrder( treePtr->rightPtr );
    } // end if
}

// begin postorder traversal of tree
void postOrder( TreeNodePtr treePtr )
{
    // if tree is not empty, then traverse
    if ( treePtr != NULL ) {
        postOrder( treePtr->leftPtr );
        postOrder( treePtr->rightPtr );
        printf( "%3d", treePtr->data );
    } // end if
}// end function postOrder