#include<iostream>
#define n 100
using  namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class Stack
{
    public:
    Node *top;
    Stack()
    {
        top=NULL;
    }
    void push(int val)
    {
        Node*temp=new Node(val);
        if(temp==NULL)
        {
            cout<<"No space"<<endl;
            return ;
        }
        else
        {
            temp->next=top;
            top=temp;
        }
    }
        bool empty()
        {
            return top==NULL;
        }

    void pop()
    {
        if(!empty())
        {
            Node*temp=top;
            top=temp->next;
            free(temp);
        }
        else
        {
            cout<<"underflow"<<endl;
            return;
        }

    }
    void display()
    {
        if(!empty())
        {
            Node* temp=top;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        else
        {
            cout<<"Underflow"<<endl;
            return;
        }

    }
    int Top()
    {
        if(!empty())
        {
            cout<<top->data<<endl;
        }
        else
        {
            cout<<"Underflow"<<endl;


        }
    }
};
int main()
{
    Stack s;
    s.push(2);
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(11);
    cout<<"The elements of stack are: ";
    s.display();
    s.pop();
    s.pop();
    cout<<"The elements of stack are after poping: ";
    s.display();

}



