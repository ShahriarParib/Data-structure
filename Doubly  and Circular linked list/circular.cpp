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
    Node *n=new Node (val);
    Node *temp =head;
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void deletefirstnode(Node*&head)
{
    Node*temp=head;
    Node*todelete=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete todelete;

}
void deletelastnode(Node*&head)
{
    Node *temp =head;
    if(temp->next==head)
    {
        deletefirstnode(head);
        return;
    }
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head;


}
void display(Node*&head)
{
    Node *temp=head;
    do
    {

        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
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
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->next=head;
}
int main()
{
    Node*head=NULL;
    insertion(head,6);
    insertion(head,7);
    insertion(head,10);
    insertion(head,9);
    cout<<"Original list is:";
    display(head);
    deletefirstnode(head);
    cout<<"After deleting first node:";
    display(head);
    deletelastnode(head);
     cout<<"After deleting last node:";
    display(head);
}
