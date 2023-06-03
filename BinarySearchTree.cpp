#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(){
        data=0;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    node *insert(node *t,int x){
        if(t==NULL){
            t=new node();
            t->data=x;
            t->left=NULL;
            t->right=NULL;

            return t;
        }
        else if(x<t->data){
            t->left=insert(t->left,x);
        }
        else{
            t->right=insert(t->right,x);
        }

        return t;
    }

    int height(node *t){
        int h1;
        int h2;
        if(t==NULL){
            return 0;
        }
        if(t->left==NULL && t->right==NULL){
            return 0;
        }

        h1=height(t->left);
        h2=height(t->right);

        if(h1>h2){
            return h1+1;
        }
        else{
            return h2+1;
        }
    }

    void minValue(node *root){
        node *temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        cout<<temp->data<<endl;
    }

    void mirror(node *t){
        node *temp;
        if(t!=NULL){
            mirror(t->left);
            mirror(t->right);
            temp=t->left;
            t->left=t->right;
            t->right=temp;
        }
    }

    void search(node *t,int key){
        if(t==NULL){
            cout<<"Key is not Present"<<endl;
        }
        else if(t->data==key){
            cout<<"Key is Present"<<endl;
        }
        else if(key<t->data){
            search(t->left,key);
        }
        else{
            search(t->right,key);
        }
    }

    void inorder(node *t){
        if(t==NULL){
            return;
        }
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
};

int main(){
    BST t;
    int ch;
    int ele,key,r,num,val;
    node *root=NULL;

    do
    {
        cout<<"\n---BST IMPLEMENTATION---"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Insert"<<endl;
        cout<<"3.Number of Nodes in Longest Subtree"<<endl;
        cout<<"4.Minimal Value in Tree"<<endl;
        cout<<"5.Mirror the Tree"<<endl;
        cout<<"6.Search a Value"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"\nEnter your Choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter the Value of Root Node: ";
            cin>>ele;
            root=t.insert(root,ele);
            break;
        
        case 2:
            cout<<"Enter Number of Nodes you want to insert: ";
            cin>>num;
            for(int i=0;i<num;i++){
                cout<<"\nEnter Number to Insert: ";
                cin>>val;
                root=t.insert(root,val);
            }

            cout<<"\nBST is: "<<endl;
            t.inorder(root);
            break;

        case 3:
            cout<<"\nNumber of Nodes in Longest Subtree: ";
            cout<<t.height(root);
            break;

        case 4:
            cout<<"\nMinimal Value in the BST is: ";
            t.minValue(root);
            break;

        case 5:
            cout<<"\nMirroring a Tree"<<endl;
            t.mirror(root);
            t.inorder(root);
            break;

        case 6:
            cout<<"\nEnter a Number to Search: ";
            cin>>key;
            t.search(root,key);
            break;

        case 7:
            cout<<"\nExiting Program"<<endl;
            break;
        default:
            cout<<"\nInavlid Choice"<<endl;
            break;
        }

    } while (ch!=7);
    
    
    return 0;
}