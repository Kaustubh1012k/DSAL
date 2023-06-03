#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Hashing
{
    node *tel[10];
    int hashtable[10];
    int flag[10];

public:
    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            tel[i] = NULL;

            flag[i] = 0;
        }
    }

    node *createSc(int x)
    {
        node *temp = new node();
        temp->data = x;
        temp->next = NULL;
        return temp;
    }

    void insertSc(int x)
    {
        int loc = x % 10;
        node *head = new node();
        node *temp = new node();

        head = createSc(x);
        temp = tel[loc];

        if (temp == NULL)
        {
            tel[loc] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }

    void createLp(int x)
    {
        int loc = x % 10;
        for (int i = 0; i < 10; i++)
        {
            if (flag[loc] == 0)
            {
                hashtable[loc] = x;
                flag[loc] = 1;
                break;
            }
            else
            {
                loc = (loc + 1) % 10;
            }
        }
    }

    void displaySc()
    {
        for (int i = 0; i < 10; i++)
        {
            node *temp = new node();
            temp = tel[i];

            if (temp == NULL)
            {
                cout << "--------" << endl;
            }
            else
            {
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }

    void displayLp()
    {
        for (int i = 0; i < 10; i++)
        {
            if (flag[i] == 0)
            {
                cout << "-------" << endl;
            }
            else
            {
                cout << hashtable[i] << endl;
            }
        }
    }

    void search1(int x){
        int loc= x%10;
        node *temp=tel[loc];
        int count=0;

        if(temp==NULL){
            cout<<"Telephone Number Not Found"<<endl;
            count=1;
        }
        else{
            while(temp!=NULL){
                if(temp->data==x){
                    cout<<"The Telephone Number is Found at location "<<loc<<endl;
                }
                temp=temp->next;
                count=count+1;
            }
        }

        cout<<"No. of Comparisons required to find "<<x<<" : "<<count<<endl;

    }

    void search2(int x){
        int loc= x % 10;
        int count=0;

        for(int i=0;i<10;i++){
            if(flag[loc]==1){
                if(x==hashtable[loc]){
                    cout<<"Telephone Number is Found at location "<<loc<<endl;
                    count=count+1;
                    break;
                }
                else{
                    loc=(loc+1)%10;
                    count=count+1;
                }
            }
            else{
                cout<<"Element Not Found"<<endl;
                break;
            }
        }

        cout<<"Number of Comparisons to find "<<x<<" : "<<count<<endl;
    }
};

int main()
{
    Hashing h;
    int choice, c1, c2, x, y,key1,key2;

    do
    {   
        cout<<"\n--COLLISION HANDLING--"<<endl;
        cout << "Choose Method:\n1.Seperate Chaining\n2.Linear Probing\n3.Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n---SEPERATE CHAINING---" << endl;
            do
            {
                cout << "\nMenu\n1.Insert\n2.Display\n3.Search\n4.Exit this Section" << endl;
                cout << "Enter your Choice: ";
                cin >> c1;

                switch (c1)
                {
                case 1:
                    cout << "Enter Element to Insert: ";
                    cin >> x;
                    h.insertSc(x);
                    break;

                case 2:
                    cout << "The Hashtable is: " << endl;
                    h.displaySc();
                    break;

                case 3:
                    cout<<"Enter Telephone Number to Search: ";
                    cin>>key1;
                    h.search1(key1);
                    break;

                case 4:
                    cout << "\nExiting This Section!!!" << endl;
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                    break;
                }
            } while (c1 != 4);
            break;

        case 2:
            cout << "\n---LINEAR PROBING---" << endl;
            do
            {
                cout << "\nMenu\n1.Insert\n2.Display\n3.Search\n4.Exit this Section" << endl;
                cout << "Enter your Choice: ";
                cin >> c2;

                switch (c2)
                {
                case 1:
                    cout << "Enter Element to Insert: ";
                    cin >> y;
                    h.createLp(y);
                    break;

                case 2:
                    cout << "The Hashtable is: " << endl;
                    h.displayLp();
                    break;

                case 3:
                    cout<<"Enter Telephone Number to Search: ";
                    cin>>key2;
                    h.search2(key2);
                    break;
                    
                case 4:
                    cout << "\nExiting This Section!!!" << endl;
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                    break;
                }
            } while (c2 != 4);
            break;

        case 3:
            cout << "\nExiting The Program!!!" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}