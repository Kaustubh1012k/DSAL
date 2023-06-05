#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct stud
{
    int roll_no;
    string name;
    char div;
    string address;
    int status;
} rec;

class Student
{
public:
    void create()
    {
        ofstream fout;
        fout.open("Student.dat", ios::out | ios::binary);
        int n;
        cout << "Enter Number of Data you want Enter: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter Roll No of Student : ";
            cin >> rec.roll_no;
            cin.ignore();

            cout << "Enter the Name of Student : ";
            getline(cin, rec.name, '\n');

            cout << "Enter a Division of Student : ";
            cin >> rec.div;

            cout << "Enter a Address of Student : ";
            cin.ignore();
            getline(cin, rec.address, '\n');

            fout.write((char *)&rec, sizeof(stud));
        }
        fout.close();
    }
    void insert()
    {
        stud rec1;
        int n;
        fstream f;
        f.open("Student.dat", ios::in | ios::out | ios::binary);

        cout << "\nEnter Roll No of Student: ";
        cin >> rec.roll_no;

        cout << "Enter the Name of Student: ";
        cin.ignore();
        getline(cin, rec.name);

        cout << "Enter a Division of Student: ";
        cin >> rec.div;

        cout << "Enter an Address of Student: ";
        cin.ignore();
        getline(cin, rec.address);

        f.seekg(0, ios::end);
        n = f.tellg() / sizeof(stud);

        if (n == 0)
        {
            f.write((char *)&rec, sizeof(stud));
        }
        else
        {
            int i = n - 1;
            while (i >= 0)
            {
                f.seekg(i * sizeof(stud), ios::beg);
                f.read((char *)&rec1, sizeof(stud));

                if (rec1.roll_no > rec.roll_no)
                {
                    f.seekp((i + 1) * sizeof(stud), ios::beg);
                    f.write((char *)&rec1, sizeof(stud));
                }
                else
                {
                    break;
                }
                i--;
            }

            i++;
            f.seekp(i * sizeof(stud), ios::beg);
            f.write((char *)&rec, sizeof(stud));
        }

        f.close();
        cout << "\nRecord Inserted Successfully!" << endl;
    }

    int search()
    {
        int r, i = 0;
        ifstream fin;
        fin.open("Student.dat", ios::in | ios::binary);
        fin.seekg(0, ios::beg);
        cout << "\nEnter a Roll Number: ";
        cin >> r;

        if (!fin)
        {
            cout << "Error opening file!" << endl;
            return -1;
        }

        while (fin.read((char *)&rec, sizeof(stud)))
        {
            if (rec.roll_no == r)
            {
                cout << "\n\t___Record Found___";
                cout << "\n\tRoll Number\tName\t\t\tDivison\t\tAddress";
                cout << "\n\t" << rec.roll_no << "\t" << rec.name << "\t" << rec.div << "\t" << rec.address;
                return i;
            }
            i++;
        }
        fin.close();
        cout << "\n\tRecord Not Found";
        return -1;
    }

    void deletion()
    {
        int pos;
        pos = search();
        fstream f;
        f.open("Student.dat", ios::in | ios::out | ios::binary);
        f.seekg(0, ios::beg);
        if (pos == 0)
        {
            cout << "\n\tRecord Not Found";
            return;
        }
        int offset = pos * sizeof(stud);
        f.seekp(offset);
        f.tellg();
        rec.roll_no = -1;
        rec.name = "";
        rec.div = '\0';
        rec.address = "";
        f.write((char *)&rec, sizeof(stud));
        f.seekg(0);
        f.close();
        cout << "\n\tRecord Deleted";
    }

    void display()
    {
        ifstream fin;
        fin.open("Student.dat", ios::in | ios::binary);
        fin.seekg(0, ios::beg);
        cout << "\n\tThe Contents of File are:\n";
        cout << "\n\tRoll Number\tName\t\t\tDivison\t\tAddress";

        while (fin.read((char *)&rec, sizeof(stud)))
        {
            if (rec.roll_no != -1)
                cout << "\n\t" << rec.roll_no << "\t\t" << rec.name << "\t\t" << rec.div << "\t\t" << rec.address;
        }
        fin.close();
    }
};

int main()
{
    Student obj;
    int ch, key;
    do
    {
        cout << "\n----Student Information----";
        cout << "\n1.Create";
        cout << "\n2.Insert";
        cout << "\n3.Display";
        cout << "\n4.Delete";
        cout << "\n5.Search";
        cout << "\n6.Exit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            obj.create();
            cout << endl;
            break;
        case 2:
            obj.insert();
            cout << endl;
            break;
        case 3:
            obj.display();
            cout << endl;
            break;
        case 4:
            obj.deletion();
            cout << endl;
            break;
        case 5:
            key = obj.search();
            cout << endl;
            break;
        case 6:
            cout << "Exiting the Program !!!" << endl;
            break;
        default:
            cout << "Invalid Choice...." << endl;
            break;
        }
    } while (ch != 6);
    return 0;
}
