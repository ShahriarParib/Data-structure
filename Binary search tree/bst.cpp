#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};
Node*insertion(Node *root,int value)
{
    if(root==NULL)
    {
        return new Node (value);

    }
    if(value<root->data)

    {
        root->left= insertion(root->left,value);
    }
    else

    {
        root->right= insertion(root->right,value);
    }
    return root;
}
int searchingDepth(Node*root,int value,int depth)
{

    if(root==NULL)
    {

        return -1;
    }
    if(value==root->data)
    {

        return depth;
    }
    if(value<root->data)
    {

        return searchingDepth(root->left,value,depth+1);
    }
    else
    {
        return searchingDepth(root->right,value,depth+1);

    }
}
Node *inordersuc(Node*root)
{
    Node *cur=root;
    while(cur&&cur->left!=NULL)
          {
             cur=cur->left;
          }
            return cur;

}
Node*deleting(Node*root,int val)
{
    if(val<root->data)
    {
        root->left=deleting(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=deleting(root->right,val);
    }
    else{
        if(root->left==NULL)
        {
            Node *temp=root->left;
            free(root);
            return temp;
        }
         else if(root->right==NULL)
        {

            Node *temp=root->left;
            free(root);
            return temp;
        }
        Node*temp=inordersuc(root->right);
        root->data=temp->data;
        root->right=deleting(root->right,temp->data);
    }
}
void ances(Node*root,int val)
{

    if(root==NULL)
    {

        return;
    }
    if(val==root->data)
    {
        return;
    }
    else if(val<root->data)
    {
        cout<<root->data<<" ";
        ances(root->left,val) ;
    }
    else
    {
        cout<<root->data<<" ";
        ances(root->right,val) ;
    }
}

void traverse(struct Node*root,int val)
{

    if(root!=NULL)
    {
traverse(root->left,val);

if(root->data!=val)

{
    cout<<root->data<<" ";
}

traverse(root->right,val);
}
}
void inorder(Node *root)
{
if(root==NULL)
{

    return;
}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void des(struct Node*root,int val)
{
    struct Node*temp=NULL;
    if(val==root->data)
    {
        temp=root;
    }
    else{
    while(root->data!=val)
    {

        if(val<root->data)
        {
            root=root->left;
        }
        else if(val>root->data)
        {
            root=root->right;
        }
           temp=root;
    }
    }
    traverse(temp,val);
}
int main()
{
    Node* root=NULL;
    root=insertion(root,5);
    insertion(root,1);
    insertion(root,3);
    insertion(root,4);
    insertion(root,7);
    insertion(root,2);
    insertion(root,0);
    cout<<"The depth is: "<<(searchingDepth(root,3,0))<<endl;
    cout<<"The ancestors are: ";
    ances(root,2);
    cout<<endl;
    cout<<"The descendants are: ";
    des(root,5);
    cout<<endl;
    deleting(root,7);
    cout<<"After deleting a node BST is: ";
    inorder(root);
    cout<<endl;
}
