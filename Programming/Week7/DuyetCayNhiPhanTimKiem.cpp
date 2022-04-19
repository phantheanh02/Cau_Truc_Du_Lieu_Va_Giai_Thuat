/* input
	tree: 50
		    /  \
		  30    70
		  /\	 /\
		20  40  60 90
		/
	   10
	
Enter the number of Tree elements: 8

Enter the next element: 5

Enter the next element: 3

Enter the next element: 7

Enter the next element: 4

Enter the next element: 2

Enter the next element: 1

Enter the next element: 6

Enter the next element: 9
*/
#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode *left, *right;
};

typedef TNode *Tree;

void Init(Tree &root){
	root = NULL;
}

TNode *createNode(int x){
	TNode *p = new TNode;
	if(!p) exit(1);
	p->data = x;
	p->left = p->right =  NULL;
	return p;
}

void insertNode(Tree &root, int x){
	if(root){
		if(root->data == x ) return;
		else
			if( x < root->data ) insertNode(root->left, x);
			else insertNode(root->right, x);
	}else{
		TNode *p = createNode(x);
		root = p;
	}
}

void createTree(Tree &root){
	int n;
	cout<< "\nEnter the number of Tree elements: ";
	cin>> n;
	int x;
	while(n--){
		cout<<"\nEnter the next element: ";
		cin>> x;
		insertNode(root, x);
	}
}
// Duyet theo thu tu giua
void inOrder(Tree root){
	TNode *p;
	while( root ){
		if(root->left == NULL ){
			cout<< root->data << " ";
			root = root->right;
		}
		else{
			p = root->left;
			while(p->right && p->right != root ){
				p = p->right;
			}
			if( p->right == NULL ){
				p->right = root;
				root = root->left;
			}
			else{
				p->right = NULL;
				cout<< root->data << " ";
				root = root->right;
			}
		}
	}
	cout<< endl;
}

// Duyet theo thu tu truoc
void preOrder(Tree root){
	TNode *p;
	while (root) {
		if (root->left == NULL){
			cout<<root->data<<" ";
			root=root->right;
		}
		else {
			p=root->left;
			while (p->right && p->right != root)
				p = p->right;
			if (p->right == NULL){
				p->right=root;
				cout<<root->data<<" ";
				root=root->left;
			}
			else {
				p->right = NULL;
				root = root->right;
			}
		}
	}
	cout << endl;
}

int stack[100];
int top=-1,i;
void push(int x)
{
	top++;
	stack[top]=x;
}
// Duyet theo thu tu sau
void PostOrder(Tree root)
{
	TNode *p,*q;;
	while( root ){
		if(root->right == NULL  ){
			push(root->data);
			root = root->left;
		}
		else{
			p = root->right;
			while(p->left  && p->left != root ){
				p = p->left;
			}
			if( p->left == NULL ){
				p->left = root;
				push(root->data);
				root = root->right;
			}
			else{
				p->left = NULL;			
				root = root->left;	
			}
		}
	}
	for (i=top; i>=0; i--) printf("%d ",stack[i]);
	cout<< endl;
}
int main(){
	Tree root;
	Init(root);
	createTree(root);
	int n;
	printf("Press 1 top inOrder\nPress 2 top preOrder\nPress 3 top PostOrder\n");
	scanf("%d",&n);
	if (n==1) inOrder(root);
	if (n==2) preOrder(root);
	if (n==3) PostOrder(root);
}
