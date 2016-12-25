#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root;
//root = NULL;

void add_to_bst(node*&, int);
bool search_bst(node*, int);
void delete_from_bst(node*&, int);
void inorder_bst(node*);
void display(node*);

int main()
{
    //cout<<"Hello";
    //struct node *root;
    root = NULL;
    int choice, element, num;
    char ch='y';
    bool b;
    do
    {
        cout<<"\n1. Add elements to BST\n2. Search element in BST\n3. Delete element from BST\n4. Display BST\n\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"\nEnter number of elements to be added: ";
            cin>>num;
            cout<<"\nEnter elements to be added: ";
            for(int i=0;i<num;i++)
            {
                cin>>element;
                add_to_bst(root, element);
            }
            cout<<"\nElements Added Successfully!!";
            break;

        case 2:
            cout<<"\nEnter element to be searched: ";
            cin>>element;
            b = search_bst(root, element);
            if(b)
                cout<<"\nElement Found!!";
            else
                cout<<"\nElement not Found!!";
            break;

        case 3:
            cout<<"\nEnter element to be deleted: ";
            cin>>element;
            delete_from_bst(root, element);
            cout<<"\nElement Deleted Successfully!!";
            //cout<<"Not coming here from case 3";
            break;

        case 4:
            display(root);
            break;
        }

        cout<<"\nDo you want to continue? y/n ";
        cin>>ch;

    }while(ch=='y' || ch== 'Y');

    return(0);
}

void add_to_bst(node*& root, int x)
{
    //cout<<"Hello";
    if(root == NULL)
    {
        struct node *temp = new node();
        temp->data = x;
        temp->right = NULL;
        temp->left = NULL;
        root = temp;
    }
    else
    {
        struct node *temp = new node();
        temp->data = x;
        temp->right = NULL;
        temp->left = NULL;

        struct node *par;
        par = root;
        while(1)
        {
            if(x<par->data && par->left!=NULL)
                par = par->left;
            else if(x>par->data && par->right!=NULL)
                par = par->right;
            else
                break;
        }
        if(x<par->data)
            par->left = temp;
        else
            par->right = temp;

    }
}

bool search_bst(node *root, int x)
{
    if(root == NULL)
        return(false);

    struct node *par;
        par = root;
        while(1)
        {
            if(x==par->data)
                return(true);
            else if(x>par->data && par->right!=NULL)
                par = par->right;
            else if(x<par->data && par->left!=NULL)
               par = par->left;
            else
                return(false);
        }
}

void delete_from_bst(node*& root, int x)
{
    if(!search_bst(root,x))
    {
        cout<<"\nElement not Found!!";
        return;
    }
    else if(root==NULL)
    {
        cout<<"Underflow!!";
        return;
    }

    struct node *par, *ptr;
        ptr = NULL;
        par = root;
        while(1)
        {
            if(x>par->data && par->right!=NULL)
            {
                ptr = par;
                par = par->right;
            }
            else if(x<par->data && par->left!=NULL)
            {
                ptr = par;
                par = par->left;
            }
            else
                break;
        }

            if(par->left==NULL && par->right==NULL) //case 1 no child
            {
                if(par==root)
                    root = NULL;
                else if(par==ptr->left)
                    ptr->left = NULL;
                else
                    ptr->right = NULL;
                delete(par);
                //cout<<"Element Deleted Successfully!!";
            }
            else if(par->left==NULL || par->right==NULL) //case 2 one child
            {
                if(par==root)
                {
                    if(par->right!=NULL)
                        root=par->right;
                    else
                        root=par->left;
                }
                else if(ptr->left==par)
                {
                    if(par->left==NULL)
                        ptr->left = par->right;
                    else
                        ptr->left = par->left;
                }
                else
                {
                    if(par->left==NULL)
                    ptr->right = par->right;
                    else
                    ptr->right = par->left;
                }
                delete(par);
                //cout<<"Element Deleted Successfully!!";
            }
            else //case 3 two childs
            {
                struct node *temp;
                temp = par->right;
                while(temp->left!=NULL)
                {
                    temp = temp->left;
                } //temp is inorder successor of x
                int y = temp->data;
                delete_from_bst(root, y); //Here case 1 or case 2 will execute as temp has no left child
                //cout<<temp->data;
                struct node *temp1 = new node();
                temp1->data = y;
                temp1->right = par->right;
                temp1->left = par->left;
                if(ptr==NULL)
                    root = temp1;
                else if(ptr->left == par)
                    ptr->left = temp1;
                else
                    ptr->right = temp1;
                delete(par);

            }
            //cout<<"Hello";
}

void inorder_bst(node *root)
{
    if(root==NULL)
    {
        cout<<"Underflow!!";
        return;
    }
    node *ptr, *par;
    par = root;
    if(par->left!=NULL)
    {
        ptr = par;
        inorder_bst(ptr->left);
    }
    cout<<par->data<<"\t";
    if(par->right!=NULL)
    {
       ptr = par;
       inorder_bst(ptr->right);
    }

}

void display(node *root)
{
    if(root==NULL)
    {
        cout<<"Underflow";
        return;
    }
    node *ptr, *par;
    par = root;

        cout<<"\nParent= "<<par->data;
        if(par->left!=NULL)
        cout<<"\nIts Left child= "<<par->left->data;
        else
            cout<<"\nIts Left child= NULL";
        if(par->right!=NULL)
        cout<<"\nIts Right child= "<<par->right->data;
        else
            cout<<"\nIts Right child= NULL";

    if(par->left!=NULL)
    {
        ptr=par;
        display(ptr->left);
    }

    if(par->right!=NULL)
    {
       ptr = par;
       display(ptr->right);
    }
}
