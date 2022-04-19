#include <stdio.h>

typedef struct Node
{
    int id;
    Node *leftMostChild;
    Node *rightSibling;
} Node;
Node *root;

Node *find(Node *r, int v)
{
    if (r==NULL) return NULL;
    if (r->id == v) return r;
    Node *p= r->leftMostChild;
    while (p != NULL)
    {
        Node *h = find(p,v);
        if (h != NULL) return h;
        p=p->rightSibling;
    }
    return NULL;
}

// Chèn 
void insert(Node *r,Node *p, int id)
{
    if (r=NULL) 
    {
        r=p;
    }
    Node *q= r->leftMostChild;
    while (q->rightSibling != NULL)
        q=q->rightSibling;
    q->rightSibling=p;
}
// Đếm số nút
int count(Node *r)
{
    if (r==NULL) return 0;
    int s=1;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        s+=count(p);
        p=p->rightSibling;
    }
    return s;
}

// Đếm số nút lá
int countLeaves(Node *r)
{
    if (r == NULL) return 0;
    int s=0;
    Node *p= r->leftMostChild;
    if (p==NULL) s=1;
    while (p != NULL)
    {
        s+=countLeaves(p);
        p=p->rightSibling;
    }
    return s;
}

// Độ cao của một nút
int height(Node *p)
{
    if (p==NULL) return 0;
    int max=0;
    Node *q=p->leftMostChild;
    while(q!=NULL)
    {
        int h=height(q);
        if (h>max) max=h;
        q=q->rightSibling;
    }
    return max+1;
}

// Độ sâu của một nủt
int depth(Node *r, int v, int d)
{
    if (r==NULL) return -1;
    if (r->id == v) return d;
    Node *p=r->leftMostChild;
    while (p != NULL)
    {
        if (p->id == v) return d+1;
        int dv = depth(p,v,d+1);
        if (dv>0) return dv;
        p = p->rightSibling;
    }
    return -1;
    
}
int depth(Node *r, int v)
{
    return depth(r,v,1);
}

Node *parent(Node *p, Node *r)
{
    if (r==NULL) return NULL;
    Node *q=r->leftMostChild;
    while (q!=NULL)
    {
        if (q==p) return r;
        Node *pp = parent(p,q);
        if (pp != NULL) return pp;
        q=q->rightSibling;
    }
    return NULL;
}
int main()
{
    Node *r;
}