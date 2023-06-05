#include <iostream>
#include <string>
using namespace std;

struct node
{
    string keyword;
    string meaning;
    node *left;
    node *right;
    int h;

    node()
    {
        keyword = " ";
        meaning = " ";
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node *insert(node *root, string keyword, string meaning)
    {
        if (root == NULL)
        {
            root = new node();
            root->keyword = keyword;
            root->meaning = meaning;
            root->left = NULL;
            root->right = NULL;
            root->h=0;

            return (root);
        }
        else if (keyword < root->keyword)
        {
            root->left = insert(root->left, keyword, meaning);
        }
        else if (keyword > root->keyword)
        {
            root->right = insert(root->right, keyword, meaning);
        }

        root->h=height(root);

        if(BF(root)==2){
            if(keyword<root->left->keyword){
                root=RR(root);
            }
            else{
                root=LR(root);
            }
        }

        if(BF(root)==-2){
            if(keyword>root->left->keyword){
                root=LL(root);
            }
            else{
                root=RL(root);
            }
        }

        return root;
    }

    int height(node *t){
        if(t==NULL){
            return 0;
        }
        if(t->left==NULL || t->right==NULL){
            return 0;
        }
        else{
            int hl=1+height(t->left);
            int hr=1+height(t->right);

            if(hl>hr){
                return hl;
            }
            else{
                return hr;
            }
        }
        
    }

    int BF(node *t){
        return height(t->left)-height(t->right);
    }

    node *LL(node *t){
        node *y;
        y=t->left;
        t->left=y->right;
        y->right=t;

        return t;
    }

    node *RR(node *t){
        node *y;
        y=t->right;
        t->right=y->left;
        y->left=t;

        return t;
    }

    node *LR(node *t){
        t->left=LL(t->left);
        t=RR(t);
        return t;
    }

    node *RL(node *t){
        t->right=RR(t->right);
        t=LL(t);
        return t;
    }

    void display(node *root)
    {
        if (!root)
        {
            return;
        }
        display(root->left);
        cout << "\n\t" << root->keyword << "\t" << root->meaning;
        display(root->right);
    }

    node *deleteNode(node *root, string keyword)
    {
        node *temp;
        if (root == NULL)
            return root;
        if (keyword < root->keyword)
            root->left = deleteNode(root->left, keyword);
        else if (keyword > root->keyword)
            root->right = deleteNode(root->right, keyword);
        else if(root->left==NULL || root->right==NULL)
        {
            if (root->left != NULL) {
                root = root->left;
            } 
            else {
                root = root->right;
            }
            cout<<"\nWord Deleted Successfully"<<endl;
        }
        else{
            temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            root->keyword=temp->keyword;
            root->meaning=temp->meaning;
            root->right=deleteNode(root->right,temp->keyword);
        }
        
        root->h=height(root);

        if(BF(root)==2){
            if(BF(root->left)>=0){
                root=RR(root);
            }
            else{
                root=LR(root);
            }
        }

        if(BF(root)==-2){
            if(BF(root->right)<=0){
                root=LL(root);
            }
            else{
                root=RL(root);
            }
        }
        return root;
    }


    bool search(node *root, string keyword)
    {
        if (root == NULL)
        {
            cout << "Keyword not Found" << endl;
            return false;
        }
        else if (root->keyword == keyword)
        {
            cout << "Keyword is Present" << endl;
            return true;
        }
        else if (keyword < root->keyword)
        {
            search(root->left, keyword);
        }
        else
        {
            search(root->right, keyword);
        }
    }

    void mirror(node *root)
    {
        node *temp;
        if (root != NULL)
        {
            mirror(root->left);
            mirror(root->right);
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }

    void updation(node *root, string keyword, string meaning)
    {
        node *t=root;
        while(t!=NULL){
            if(keyword==t->keyword){
                t->meaning=meaning;
                cout<<"Word Updated Successfully!!!"<<endl;
                return;
            }
            else if(keyword<t->keyword){
                t=t->left;
            }
            else if(keyword>t->keyword){
                t=t->right;
            }
            else{
                cout<<"Word not Found"<<endl;
            }
        }
    }

    void comparison(node *root, string key)
    {
        int count = 0;
        while (root != NULL)
        {
            if (key < root->keyword)
            {
                count++;
                root = root->left;
            }
            else if (key > root->keyword)
            {
                count++;
                root = root->right;
            }
            else if (key == root->keyword)
            {
                count++;
                cout << "No. of comparisons: " << count << endl;
                return;
            }
        }
    }
};

int main()
{
    BST obj;
    node *root = NULL;
    int ch, n;
    string keyword, meaning, key, k;

    do
    {
        cout << "\n---Main Menu---";
        cout << "\n1.Create";
        cout << "\n2.Insert";
        cout << "\n3.Display in Ascending Order";
        cout << "\n4.Search";
        cout << "\n5.Delete";
        cout << "\n6.Update the Meaning of Keyword";
        cout << "\n7.Display in Descending Order";
        cout << "\n8.Exit";
        cout << "\nEnter your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the Keyword for root Node: ";
            cin.ignore();
            getline(cin, keyword);
            cout << "Enter the Meaning of " << keyword << " : ";
            getline(cin, meaning);
            root = obj.insert(root, keyword, meaning);
            break;

        case 2:
            cout << "Enter the Number of Data you want to Enter: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the Keyword: ";
                getline(cin, keyword);
                cout << "Enter the Meaning of " << keyword << " : ";
                getline(cin, meaning);
                obj.insert(root, keyword, meaning);
            }
            cout << "\n";
            break;

        case 3:
            cout << "Dictionary Elements in Ascending Order:" << endl;
            cout<<"\n\tWORD\tMEANING"<<endl;
            obj.display(root);
            cout << "\n";
            break;

        case 4:
            cout << "Enter the Keyword to search: ";
            cin.ignore();
            getline(cin, k);
            obj.search(root, k);
            obj.comparison(root, k);
            break;

        case 5:
            cout << "Enter the Keyword to be deleted: ";
            cin.ignore();
            getline(cin, key);
            root = obj.deleteNode(root, key);
            break;

        case 6:
            cout << "Enter the keyword to update: ";
            cin.ignore();
            getline(cin, keyword);
            cout << "Enter the New Meaning: ";
            getline(cin, meaning);
            obj.updation(root, keyword, meaning);
            break;
        case 7:
            cout << "\n";
            cout << "Dictionary Elements in Descending Order: " << endl;
            obj.mirror(root);
            obj.display(root);
            cout << "\n";
            break;

        case 8:
            cout << "Exiting Program!!!" << endl;
            break;

        default:
            cout << "Invalid Choice " << endl;
            break;
        }
    } while (ch != 8);

    return 0;
}
