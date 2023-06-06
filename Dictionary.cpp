#include <iostream>
#include <string>
using namespace std;

struct node
{
    string keyword;
    string meaning;
    node *left;
    node *right;

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

        return root;
    }

    void display(node *root)
    {
        if (!root)
        {
            return;
        }
        display(root->left);
        cout << "\n\t" << root->keyword << "\t" << root->meaning << "] ";
        display(root->right);
    }

    node *deleteNode(node *root, string keyword)
    {if (root == NULL)
            return root;
        if (keyword < root->keyword)
            root->left = deleteNode(root->left, keyword);
        else if (keyword > root->keyword)
            root->right = deleteNode(root->right, keyword);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                cout << "\nWord Deleted Successfully" << endl;
                return NULL;
            }
            else if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                cout << "\nWord Deleted Successfully" << endl;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                cout << "\nWord Deleted Successfully" << endl;
                return temp;
            }
            else
            {
                node *t;
                t = root->right;
                while (t->left)
                {
                    t = t->left;
                }
                root->keyword = t->keyword;
                root->meaning = t->meaning;
                root->right = deleteNode(root->right, t->keyword);
            }
        return root;
    }

    bool search(node *root, string keyword)
    {
        if (root == NULL)
        {
            cout << "Keyword not Found" << endl;
        }
        else if (root->keyword == keyword)
        {
            cout << "Keyword is Present" << endl;
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
    {   node *t=root;
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
        cout << "Keyword not found" << endl;
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
            cout<<"\n\tWORD\tMEANING"<<endl;
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
