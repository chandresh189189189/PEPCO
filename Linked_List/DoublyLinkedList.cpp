#include<iostream>
using namespace std;
struct node{
int info;
struct node *next;
struct node *prev;
}*start;

class dll
{
public:
    void create_list(int value);
    void add_begin(int value);
    void add_after(int value, int position);
    void delete_element(int value);
    void search(int value);
    void display(int value);
    dll()
    {
        start=NULL;
    }
};

int main()
{
    int choice, element, position;
    dll dl;
    while(1)
    {
        cout<<endl<<"--------------------------------";
        cout<<endl<<"Operations on Doubly Linked List";
        cout<<endl<<"--------------------------------";
        cout<<endl<<"1-Create Node";
        cout<<endl<<"2-Add at Beginning";
        cout<<endl<<"3-Add after Position";
        cout<<endl<<"4-Delete";
        cout<<endl<<"5-Display";
        cout<<endl<<"6-Exit";
        cout<<endl<<"Enter Choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the element: ";
                    cin>>element;
                    dl.create_list(element);
                    break;
            case 2: cout<<"Enter the element: ";
                    cin>>element;
                    dl.add_begin(element);
                    break;
            case 3: cout<<"Enter the element: ";
                    cin>>element;
                    cout<<"Insert element after position: ";
                    cin>>position;
                    dl.add_after(element);
                    break;
            case 4: if(start==NULL)
                    {
                        cout<<"List empty, Nothing to delete"<<endl;
                        break;
                    }
                    cout<<"Enter element for deletion: ";
                    cin>>element;
                    dl.delete_element(element);
                    break;
            case 5: dl.display();
                    break;
            case 6: exit(1);
            default: cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}


void dll::create_list(int value)
{
    struct node *s, *temp;
    temp=new(struct node);
    temp->info=value;
    temp->next=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        s=start;
        while(s->next!=NULL)
            s=s->next;
        s->next=temp;
        temp->prev=s;

    }
}


void dll::add_begin(int value)
{
    if(start==NULL)
    {
        cout<<"First create the list"<<endl;
        return;
    }
    struct node *temp;
    temp=new(struct node);
    temp->prev=NULL;
    temp->info=value;
    temp->next=start;
    start->prev=temp;
    start=temp;
    cout<<"Element inserted"<<endl;
}


void dll::add_after(int value, int pos)
{
    if(start=NULL)
    {
        cout<<"first create the list"<<endl;
        return;
    }
    struct node *temp, *q;
    int i;
    q=start;
    for(i=0;i<pos-1;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    temp=new(struct node);
    temp->info=value;
    if(q->next==NULL)
    {
        q->next=temp;
        temp->next=NULL;
        temp->prev=q;
    }
    else
    {
        temp->next=q->next;
        temp->next->prev=temp;
        q->next=temp;
        temp->prev=q;
    }
    cout<<"Element inserted"<<endl;
}


void dll::delete_element(int value)
{
    struct node *temp, *q;
    /*first element deletion*/
    if(start->info==value)
    {
        temp=start;
        start=start->next;
        start->prev=NULL;
        cout<<"Element deleted"<<endl;
        free(temp);
        return;
    }
    q=start;
    while(q->next->next != NULL)
    {
        /*element deleted in between*/
        if(q->next->info==value)
        {
            temp=q->next;
            q->next=temp->next;
            temp->next->prev=q;
            cout<<"Element deleted"<<endl;
            free(temp);
            return;
        }
        q=q->next;
    }
    /*Last element deleted*/
    if(q->next->info==value)
    {
        temp=q->next;
        free(temp);
        q->next=NULL;
        cout<<"Element deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}


void dll::display()
{
    struct node *q;
    if(start==NULL)
    {
        cout<<"List empty,Nothing to display"<<endl;
        return;
    }
    q=start;
    cout<<"The doubly linked list is: "<<endl;
    while(q!=NULL)
    {
        cout<<q->info<<"->";
        q=q->next;
    }
    cout<<"NULL"<<endl;
}
