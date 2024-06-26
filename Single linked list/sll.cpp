#include<bits/stdc++.h>
using namespace std;
class Node
{
public:

    int data;
    Node*next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertathead(Node*&head,int val)
{
    Node *n=new Node (val);
    if(head==NULL)
    {
        head=n;
        return;
    }

    n->next=head;
    head=n;

}
void deletefirstnode(Node*&head)
{
    if(head==NULL)
    {

        cout<<"Nothing to delete";
        return;
    }
    Node *todelete=head;
    head=head->next;
    delete todelete;
}
void deleteatpos(Node *&head,int pos)
{
      if(pos<=0)
    {
        cout<<"wrong position"<<endl;
        return;
    }
    if(pos==1)
    {
        deletefirstnode(head);
        return;
    }
    int cnt;
       Node*temp=head;
       while(temp->next!=NULL&&cnt!=pos-2)
    {
        temp=temp->next;
        cnt++;
    }
    Node*nextNode=temp->next->next;
    delete temp->next;
    temp->next=nextNode;

}
void deletelastnode(Node*&head)
{
    Node*temp=head;
      while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    Node*todelete =temp->next;
    temp->next=NULL;
    delete todelete;
}
void insertatpos(Node*&head,int pos,int val)
{
    Node *n=new Node (val);
    Node*temp=head;
    int cnt=0;
    if(pos<=0)
    {
        cout<<"wrong position"<<endl;
        return;
    }
    if(pos==1)
    {
        insertathead(head,val);
        return;
    }
     while(temp->next!=NULL&&cnt!=pos-2)
    {
        temp=temp->next;
        cnt++;
    }
    n->next=temp->next;
    temp->next=n;
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
}
void display(Node*&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int a,b,c,d;
    Node*head=NULL;
    insertion(head,6);
    insertion(head,7);
    insertion(head,10);
    insertion(head,9);
    display(head);
    cout<<"Enter position and value to insert:"<<endl;
    cin>>a>>b;
    insertatpos(head,a,b);
    cout<<"After inserting new node:";
    display(head);
    deletelastnode(head);
    cout<<"After deleting last Node:";
    display(head);
    cout<<"Enter position to delete:"<<endl;
    cin>>c;
    deleteatpos(head,c);
    cout<<"After deleting certain node:";
    display(head);
}
