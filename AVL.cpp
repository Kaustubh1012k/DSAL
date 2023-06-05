#include <iostream>
#include <string.h>
using namespace std;

struct node
{
public:
    string Word;
    string Mean;
    node *left, *right;
    int h;
};

class AVLtree
{

public:
    node *Root;
    AVLtree()
    {
        Root = NULL;
    }

    node *insert(node *root, string keyword, string nMean)
    {
        if (root == NULL)
        {
            root = new node;
            root->left = root->right = NULL;
            root->Word = keyword;
            root->Mean = nMean;
            root->h = 0;
        }
        else if (root->Word > keyword)
        {
            root->left = insert(root->left, keyword, nMean);
        }
        else
        {
            root->right = insert(root->right, keyword, nMean);
        }

        root->h = max(height(root->left), height(root->right)) + 1;

        if (bFactor(root) == 2)
        {
            if (root->left->Word > keyword)
                root = RR(root);
            else
                root = LR(root);
        }

        if (bFactor(root) == -2)
        {
            if (root->right->Word > keyword)
                root = RL(root);
            else
                root = LL(root);
        }

        return root;
    }

    node *min_node(node *root)
    {
        while (root->left != NULL)
        {
            Root = root;
            root = root->left;
        }
        return root;
    }

    void delete_word(node *root, string key)
    {
        node *q;
        node *s;
        while (root != NULL)
        {
            if (key < root->Word)
            {
                q = root;
                root = root->left;
            }
            else if (key > root->Word)
            {
                q = root;
                root = root->right;
            }
            else if (key == root->Word)
            {
                if (root->left == NULL && root->right == NULL)
                {
                    if (q->left == root)
                    {
                        delete root;
                        q->left = NULL;
                        return;
                    }
                    else if (q->right == root)
                    {
                        delete root;
                        q->right = NULL;
                        return;
                    }
                }
                else if (root->left == NULL && root->right != NULL)
                {
                    if (q->right == root)
                    {
                        q->right = root->right;
                        delete root;
                        return;
                    }
                    else if (q->left = root)
                    {
                        q->left = root->right;
                        delete root;
                        return;
                    }
                }
                else if (root->left != NULL && root->right == NULL)
                {
                    if (q->right == root)
                    {
                        q->right = root->left;
                        delete root;
                        return;
                    }
                    else if (q->left == root)
                    {
                        q->left = root->left;
                        delete root;
                        return;
                    }
                }
                else if (root->left != NULL && root->right != NULL)
                {
                    s = min_node(root->right);
                    root->Word = s->Word;
                    root->Mean = s->Mean;
                    delete_word(s, s->Word);
                }
            }
        }
    }

    int height(node *curr)
    {
        if (curr == NULL)
            return -1;
        else
            return curr->h;
    }

    int bFactor(node *curr)
    {
        if (curr == NULL)
            return 0;
        else
            return height(curr->left) - height(curr->right);
    }

    node *RR(node *curr)
    {
        node *temp = curr->left;
        curr->left = temp->right;
        temp->right = curr;
        curr->h = max(height(curr->left), height(curr->right)) + 1;
        temp->h = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }

    node *LL(node *curr)
    {
        node *temp = curr->right;
        curr->right = temp->left;
        temp->left = curr;
        curr->h = max(height(curr->left), height(curr->right)) + 1;
        temp->h = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }

    node *RL(node *curr)
    {
        curr->right = RR(curr->right);
        return LL(curr);
    }

    node *LR(node *curr)
    {
        curr->left = LL(curr->left);
        return RR(curr);
    }

    void inOrder(node *curr)
    {
        if (curr != NULL)
        {
            inOrder(curr->left);
            cout << "[ " << curr->Word << " : " << curr->Mean << "]";
            inOrder(curr->right);
        }
    }
};

int main()
{
    int ch, n;
    AVLtree avl;
    node *temp = NULL;
    string word, key;
    string mean;

    cout << "\n--------------------------------------";
    cout << "\n\tAVL TREE IMPLEMENTATION";
    cout << "\n--------------------------------------";
    do
    {
        cout << "\n\t\tMENU";
        cout << "\n1.Insert 2.Inorder 3.Delete 4.Exit";
        cout << "\n--------------------------------";
        cout << "\nEnter your choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 1:
            cout << "Enter a Number of data you want to Enter: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter Word: ";
                getline(cin, word);
                cout << "\nEnter Meaning: ";
                getline(cin, mean);
                temp = avl.insert(temp, word, mean);
            }
            break;
        case 2:
            cout << "\nInorder Traversal" << endl;
            cout << "Dictionary is: " << endl;
            avl.inOrder(temp);
            cout << '\n';
            break;

        case 3:
            cout << "\nEnter the word to be deleted : ";
            cin.ignore();
            getline(cin, key);
            avl.delete_word(temp, key);
            break;

        case 4:
            exit(0);
        }
    } while (ch != 4);

    return 0;
}