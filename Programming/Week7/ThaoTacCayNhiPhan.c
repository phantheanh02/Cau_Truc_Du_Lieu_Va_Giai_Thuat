#include <stdio.h>
#include <stdlib.h>

// cây
typedef struct tree
{
    int id;
    struct tree *leftChild;
    struct tree *rightChild;
} tree;

//
tree *makeNode(int x)
{
    tree *q;
    q->id=x;
    q->leftChild=NULL;
    q->rightChild=NULL;
    return q;
}

void inOrder (tree *r)
{
    tree *p;
    while (r)
    {
        if (r->leftChild == NULL)
        {
            printf("%d ",r->id);
            r=r->rightChild;
        }
        else
        {
            p=r->leftChild;
            while ( p->rightChild != NULL)
                p = p->rightChild;
            if (p->rightChild == NULL)
            {
                p->rightChild=r;
                r=r->leftChild;
            }
            else
            {
                p->rightChild=NULL;
                printf("%d ", r->id);
                r=r->rightChild;
            }
            
        }
        
    }
    
}

void main()
{
    tree *r, *next;
    //r=makeNode(1);
    r->id=1;
    next->id=2;
    r->leftChild=next;
    r->rightChild=NULL;
   // r->leftChild=makeNode(2);
    inOrder(r);
}