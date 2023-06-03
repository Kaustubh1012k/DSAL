#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    string data;
    node *left;
    node *right;

    node(string s)
    {
        data = s;
        left = NULL;
        right = NULL;
    }
};

class Queue
{
    node *a[20];
    int f, r;

public:
    Queue()
    {
        f = r = -1;
    }

    int empty()
    {
        if (f == -1 && r == -1)
        {
            return 1;
        }
        return 0;
    }

    void insert(node *p)
    {
        if (f == -1 && r == -1)
        {
            f = r = 0;
            a[r] = p;
        }
        else
        {
            r = r + 1;
            a[r] = p;
        }
    }

    node *remove()
    {
        node *p = a[f];
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f = f + 1;
        }
        return p;
    }
};

class Stack
{
    node *a[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    void push(node *p)
    {
        top++;
        a[top] = p;
    }

    node *pop()
    {
        node *p = a[top];
        top--;
        return p;
    }
};

class Tree
{
public:
    node *root;
    node *create()
    {
        string b;
        cout << "Enter (NA for no node): ";
        cin >> b;
        if (b == "NA")
        {
            return NULL;
        }
        else
        {
            node *temp = new node(b);
            cout << "Left part of " << b << endl;
            temp->left = create();
            cout << "Right part of " << b << endl;
            temp->right = create();
            return temp;
        }
    }

    void preorder(node *t)
    {
        if (t == NULL)
            return;
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }

    void inorder(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void postorder(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }

    void nonrecursive_inorder(node *t)
    {
        Stack st;
        while (t != NULL || !st.empty())
        {
            while (t != NULL)
            {
                st.push(t);
                t = t->left;
            }
            t = st.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }

    void nonrecursive_preorder(node *t)
    {
        Stack st;
        while (t != NULL || !st.empty())
        {
            while (t != NULL)
            {
                cout << t->data << " ";
                st.push(t);
                t = t->left;
            }
            t = st.pop();
            t = t->right;
        }
    }

    void nonrecursive_postorder(node *t)
    {
        Stack s1, s2;
        node *temp;
        if (t == NULL)
        {
            return;
        }
        s1.push(t);
        while (s1.empty() != 1)
        {
            temp = s1.pop();
            s2.push(temp);
            if (temp->left != NULL)
            {
                s1.push(temp->left);
            }
            if (temp->right)
            {
                s1.push(temp->right);
            }
        }

        while (s2.empty() != 1)
        {
            temp = s2.pop();
            cout << temp->data << " ";
        }
    }

    void BFS(node *t)
    {
        Queue q;
        q.insert(t);
        cout << t->data << " ";
        while (q.empty() != 1)
        {
            t = q.remove();
            if (t->left)
            {
                cout << t->left->data << " ";
                q.insert(t->left);
            }
            if (t->right)
            {
                cout << t->right->data << " ";
                q.insert(t->right);
            }
        }
    }
};

int main()
{
    Tree t;
    int ch;
    do
    {
        cout << "\n---Menu---" << endl;
        cout << "1.Create" << endl;
        cout << "2.Recursive Inorder" << endl;
        cout << "3.Recursive Preorder" << endl;
        cout << "4.Recursive Postorder" << endl;
        cout << "5.Non-Recursive Inorder" << endl;
        cout << "6.Non-Recursive Preorder" << endl;
        cout << "7.Non-Recursive Postorder" << endl;
        cout << "8.BFS" << endl;
        cout << "9.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            t.root = t.create();
            break;
        case 2:
            t.inorder(t.root);
            break;
        case 3:
            t.preorder(t.root);
            break;
        case 4:
            t.postorder(t.root);
            break;
        case 5:
            t.nonrecursive_inorder(t.root);
            break;
        case 6:
            t.nonrecursive_preorder(t.root);
            break;
        case 7:
            t.nonrecursive_postorder(t.root);
            break;
        case 8:
            t.BFS(t.root);
            break;
        case 9:
            cout << "Exiting the Program!!!" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (ch != 9);

    return 0;
}
