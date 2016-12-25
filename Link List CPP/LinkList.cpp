#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* insert_at_beg(struct node*, int);
struct node* insert_at_end(struct node*, int);
struct node* insert_in_mid(struct node*, int, int);
struct node* del(struct node*, int);
void show(struct node*);

int main()
{
    int choice=-1, choice1, element, pos;
    struct node *temp;
	system("cls");
    while(choice)
    {
	cout<<"1. Add element\n2. Delete element\n3. Display List\n0. Exit\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1: system("cls");
		    cout<<"1. Add at beginning\n2. Add at end\n3. Add at middle\n0. Previous Menu\nEnter your choice: ";
		    cin>>choice1;
		    if(choice1)
            {
            cout<<"Enter the element to be added: ";
		    cin>>element;
            }
		    switch(choice1)
		    {
			case 1: head = insert_at_beg(head, element);
				break;
			case 2: head = insert_at_end(head, element);
				break;
			case 3: cout<<"Enter the position at which element is to be inserted: ";
				cin>>pos;
				head = insert_in_mid(head,pos,element);
				break;
			case 0: break;

		    }
		    if(choice1)
            {
                cout<<"Element added successfully!!";
                getch();
            }
		    system("cls");
		    break;

	    case 2: if(head!=NULL)
	    {
	        cout<<"Enter element to be deleted: ";
		    cin>>element;
		    }
		    head = del(head, element);
		    getch();
		    system("cls");
		    break;

	    case 3: show(head);
			getch();
			system("cls");
		    break;

	    case 0: exit(0);
	}
    }
	//getch();
    return(0);
}

struct node* insert_at_beg(struct node *start, int element)
{
    struct node *temp = new node();
    if(start== NULL)
    {
	temp->data = element;
	temp->next = NULL;
	start = temp;
    }
    else
    {
	temp->data = element;
	temp->next = start;
	start = temp;
    }
    return (start);
}

struct node* insert_at_end(struct node *start, int element)
{
    struct node *temp;
    if(start==NULL)
    {
        start = insert_at_beg(start, element);
        return(start);
    }
    for(temp = start; temp->next!=NULL; temp=temp->next);
    struct node *temp1 = new node();
    temp1->data = element;
    temp->next = temp1;
    temp1->next = NULL;
    return(start);
}


struct node* insert_in_mid(struct node *start, int position, int element)
{
    struct node *temp;
    temp = start;
    if(position<=1 || start==NULL)
        start = insert_at_beg(start, element);
    else
    {
        for(int i=0; i<position-2 && temp->next!=NULL; temp=temp->next, i++);
        struct node *temp1 = new node();
        temp1->data = element;
        temp1->next = temp->next;
        temp->next = temp1;
    }
    return(start);
};

struct node* del(struct node *start, int element)
{
    if(start==NULL)
    {
        cout<<"Underflow!!";
        return(start);
    }
    else if(start->data == element)
        start=start->next;

    else
    {

        struct node *temp, *prev;
        for(temp=start; temp!=NULL && temp->data!=element; prev=temp, temp=temp->next);
        if(temp==NULL)
        {
            cout<<"No such element was found!!";
            return(start);
        }

        else
        {
            prev->next = temp->next;
            delete(temp);
        }
    }
    cout<<"\nElement deleted successfully!!";
    return(start);
};

void show(struct node *start)
{
    if(start==NULL)
        cout<<"List is empty!!";
    else
    {
        struct node *temp;
        for(temp=start;temp!=NULL;temp=temp->next)
                cout<<temp->data<<"\t";
    }
}
