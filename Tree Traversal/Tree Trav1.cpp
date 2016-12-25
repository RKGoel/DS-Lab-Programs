#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    char data;
    struct node *left;
    struct node *right;
}*root;

void preorder(node*);
void inorder(node*);
void postorder(node*);

int main()
{
    //char arr[100];
    //cout<<"Enter the tree from left to right. Enter space for NULL.";
    struct node *tree[100];
    int choice, i;
    for(int i=0; i<100; i++)
    {
        tree[i] = new node;
        tree[i]->data = ' ';
        tree[i]->left= NULL;
        tree[i]->right=NULL;
    }
   /* {
        tree[1]->data = 'A';
        tree[2]->data = 'B';
        tree[3]->data = 'C';
        tree[4]->data = 'D';
        tree[6]->data = 'E';
        tree[7]->data = 'F';
        tree[8]->data = 'G';
        tree[9]->data = 'H';
        tree[19]->data = 'K';
        tree[1]->left = tree[2];
        tree[2]->left = tree[4];
        tree[4]->left = tree[8];
        tree[3]->left = tree[6];
        tree[1]->right = tree[3];
        tree[3]->right = tree[7];
        tree[4]->right = tree[9];
        tree[9]->right = tree[19];
    }*/

    root = tree[1];

    struct node *ptr;
    char arr[100];
    for(i=0; i<100; i++)
        arr[i] = '0';
    cout<<"Enter the elements of the tree assuming complete tree.\nEnter zero where no element is present.\nEnter 1 to end.\n";
    for(i=1; arr[i-1]!='1'; i++)
    {
        cin>>arr[i];
	if(arr[i]!='0')
	tree[i]->data = arr[i];
	else
	continue;
    }
	for(i=1; arr[i]!='1'; i++)
    {
        ptr = tree[i];

    if(tree[2*i]->data!='1' && tree[2*i]->data!='0')
        ptr->left = tree[2*i];
    else
        ptr->left = NULL;
    if(tree[(2*i)+1]->data!='1' && tree[(2*i)+1]->data!='0')
        ptr->right = tree[(2*i)+1];
    else
        ptr->right = NULL;

    }

    char ch = 'y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"1. Preorder\n2. Inorder\n3. Postorder\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: preorder(root);
                    break;
            case 2: inorder(root);
                    break;
            case 3: postorder(root);
                    break;
            default: cout<<"Incorrect choice!!";
        }
        cout<<"\nDo you want to continue? y/n";
        cin>>ch;
    }


return(0);
}


void inorder(node *root)
{
    //node *par;
    node *ptr, *par;
    par = root;
    if(par->left!=NULL)
    {
        ptr = par;
        inorder(ptr->left);
    }
    if(par->data!=' ')
    cout<<par->data<<"\t";
    if(par->right!=NULL)
    {
       ptr = par;
       inorder(ptr->right);
    }

}

void preorder(node *root)
{
    //if(root == NULL)
        //return;
        node *ptr, *par;
    par = root;
    if(par->data!=' ')
    cout<<par->data<<"\t";
    if(par->left!=NULL)
    {
        ptr = par;
        preorder(ptr->left);
        //inorder(ptr->right);
    }
    if(par->right!=NULL)
    {
        ptr = par;
        preorder(ptr->right);
    }
    //return(par);
}

void postorder(node *root)
{
    node *ptr, *par;
    par = root;
    if(par->left!=NULL)
    {
        ptr = par;
        postorder(ptr->left);
    }
    //cout<<par->data<<"\t";
    if(par->right!=NULL)
    {
        ptr = par;
        postorder(ptr->right);
    }
    //cout<<ptr->data<<"\t";
    if(par->data!=' ')
    cout<<par->data<<"\t";
}
