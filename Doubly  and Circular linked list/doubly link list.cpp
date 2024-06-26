#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    Node*next;
    Node*prev;
    Node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(Node*&head,int val)
{
    Node *n=new Node(val);
    n->next=head;
    if(head!=NULL)
    {
        head->prev=n;
    }
    head =n;

}

void insertion(Node *&head,int val)
{

    Node *n=new Node (val);
    Node *temp =head;
    if(head==NULL)
    {
        insertathead(head,val);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
}

void sorting2(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    return;
    Node* current = head;
    Node* last = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        current = head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {

                swap(current->data,current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    }
    while (swapped);
}
void display1(Node*&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

void display2(Node*&head)
{
    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;

    }
}

int main()
{
    Node *head=NULL;
    insertion(head,1);
    insertion(head,4);
    insertion(head,2);
    insertion(head,7);
    insertion(head,9);
    cout<<"The original list is: ";
    display1(head);
    cout<<endl<<"The reversed list is: ";
    display2(head);
    cout<<endl<<"The sorted list is:   ";
    sorting2(head);
    display1(head);
}
