#include<iostream>
using namespace  std;

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

class Queue
{
public:
    Node* ffront;
    Node* bback;
    Queue()
    {
        ffront=NULL;
        bback=NULL;
    }

    bool eempty()
    {
        return bback==NULL;
    }

    void push(int val)
    {
        Node* temp=new Node(val);
        if(!temp)
        {
            cout<<"queue overflow"<<endl;
        }
        else
        {
            if(ffront==NULL && bback==NULL)
            {
                ffront=temp;
                bback=temp;
            }
            else{
                bback->next=temp;
                bback=temp;
            }
        }
    }

    void pop()
    {
        if(!eempty())
        {
            Node* temp=ffront;
            if(ffront==bback)
            {
                ffront=NULL;
                bback=NULL;
                free(temp);
            }
            else
            {
                ffront=ffront->next;
                free(temp);
            }
        }
        else
        {
            cout<<"queue underflow"<<endl;
        }
    }

    void display()
    {
        if(!eempty())
        {
            Node* temp=ffront;
            while(temp!=NULL)
            {
                cout<<temp->data;
                temp=temp->next;
                if(temp) cout<<"->";
            }
            cout<<endl;
        }
        else
        {
            cout<<"queue is empty"<<endl;
        }
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(23);
    q.push(2);
    cout<<"The elements of queue are: ";
    q.display();
    q.pop();
    cout<<"The elements of queue are after pop: ";
    q.display();
}

