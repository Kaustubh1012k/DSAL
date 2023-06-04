#include <iostream>
using namespace std;

class Set
{
  int a[10], b[10];
  int u[10];
  int d[10];
  int n1, n2;
  int flag = 0;
  int ele1, ele2;

public:
  Set()
  {
    for (int i = 0; i < 10; i++)
    {
      a[i] = -1;
      b[i] = -1;
      u[i] = -1;
      d[i] = -1;
    }
  }

  void create()
  {
    cout << "Enter Number of Elements you want to enter in Set A: ";
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
      cout << "Enter Element No." << i + 1 << " : ";
      cin >> ele1;
      if(contain(ele1,a,n1)){
        i--;
      }
      a[i] = ele1;
    }

    cout << "Enter Number of Elements you want to enter in Set B: ";
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
      cout << "Enter Element No." << i + 1 << " : ";
      cin >> ele2;
      if(contain(ele2,b,n2)){
        i--;
      }
      b[i] = ele2;
    }
  }

  void display()
  {
    cout << "SET A: { ";
    for (int i = 0; i < n1; i++)
    {
      cout << a[i] << " ";
    }
    cout << "}" << endl;

    cout << "SET B: { ";
    for (int i = 0; i < n2; i++)
    {
      cout << b[i] << " ";
    }
    cout << "}" << endl;
  }

  bool contain(int ele, int x[], int n)
  {
    for (int i = 0; i < n; i++)
    {
      if (x[i] == ele)
      {
        cout << "Element is Already Present" << endl;
        return true;
      }
    }
    return false;
  }

  void add()
  {
    int ele;
    char c;
    cout << "Enter the Set in which you want to add element(A/B): ";
    cin >> c;
    cout << "Enter the Element: ";
    cin >> ele;

    if (c == 'a' || c == 'A')
    {
      if (contain(ele, a, n1))
      {
        cout << "Not Inserted Because Element is Already Present" << endl;
      }
      else
      {
        int pos;
        cout << "Enter the Position: ";
        cin >> pos;
        n1 = n1 + 1;
        if (pos == n1 + 1)
        {
          a[pos] = ele;
        }
        else
        {
          for (int i = n1; i >= pos; i--)
          {
            a[i] = a[i - 1];
          }
          a[pos] = ele;
        }
      }
    }

    if (c == 'b' || c == 'B')
    {
      if (contain(ele, b, n2))
      {
        cout << "Not Inserted Because Element is Already Present" << endl;
      }
      else
      {
        int pos;
        cout << "Enter the Position: ";
        cin >> pos;
        n2 = n2 + 1;
        if (pos == n2 + 1)
        {
          b[pos] = ele;
        }
        else
        {
          for (int i = n2; i >= pos; i--)
          {
            b[i] = b[i - 1];
          }
          b[pos] = ele;
        }
      }
    }
  }

  void remove()
  {
    int ele;
    char c;
    cout<<"Enter the SET: ";
    cin>> c;
    cout << "enter no to delete :";
    cin >> ele;
    if(c=='A'||c=='a'){
      int i;
      for(i=0;i<n1;i++){
        if(a[i]==ele){
          break;
        }
      }
      if(i<=n1){
        for(int j=i;j<n1;j++){
          a[j]=a[j+1];
        }
        n1=n1-1;
      }
      else{
        cout<<ele<<" is not present"<<endl;
      }
    }

    if(c=='B'||c=='b'){
      int i;
      for(i=0;i<n2;i++){
        if(b[i]==ele){
          break;
        }
      }
      if(i<=n2){
        for(int j=i;j<n2;j++){
          b[j]=b[j+1];
        }
        n2=n2-1;
      }
      else{
        cout<<ele<<" is not present"<<endl;
      }
    }
  }

  int size()
  {
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < 10; i++)
    {
      if (a[i] != -1)
      {
        count1++;
      }
    }
    cout << "Size of SET A: " << count1 << endl;

    for (int i = 0; i < 10; i++)
    {
      if (b[i] != -1)
      {
        count2++;
      }
    }
    cout << "Size of SET B: " << count2 << endl;
  }

  void intersection()
  {
    for (int i = 0; i < n1; i++)
    {
      for (int j = 0; j < n2; j++)
      {
        if (a[i] == b[j])
        {
          cout << a[i] << " ";
          break;
        }
      }
    }
    cout << endl;
  }

  void Union()
  {
    for (int i = 0; i <= n1; i++)
    {
      u[i] = a[i];
    }
    for (int j = 0; j <=n2; j++)
    {
      u[n1 + j] = b[j];
    }

    cout << "Union: { ";
    for (int i = 0; i <(n1 + n2); i++)
    {
      int k = 0;
      for (int j = i+1; j <(n1 + n2); j++)
      {
        if (u[i] == u[j])
        {
          k = 1;
          break;
        }
      }
      if (k == 0)
      {
        cout << u[i] << " ";
      }
    }
    cout << "}" << endl;
  }

  void Diff()
  {
    int c;
    cout << "Select the Option" << endl;
    cout << "1.A-B \n2.B-A" << endl;
    cin >> c;

    if (c == 1)
    {
      cout << "Difference (A-B): { ";
      for (int i = 0; i < n1; i++)
      {
        d[i] = a[i];
      }

      for (int i = 0; i < n1; i++)
      {
        int k = 0;
        for (int j = 0; j < n2; j++)
        {
          if (d[i] == b[j])
          {
            k = 1;
            break;
          }
        }
        if (k == 0)
        {
          cout << d[i] << " ";
        }
      }
      cout << "}" << endl;
    }

    if (c == 2)
    {
      cout << "Difference (B-A): { ";
      for (int i = 0; i < n2; i++)
      {
        d[i] = b[i];
      }

      for (int i = 0; i < n2; i++)
      {
        int k = 0;
        for (int j = 0; j < n1; j++)
        {
          if (d[i] == a[j])
          {
            k = 1;
            break;
          }
        }
        if (k == 0)
        {
          cout << d[i] << " ";
        }
      }
      cout << "}" << endl;
    }
  }

  bool subset()
  {
    for (int j = 0; j < n2; j++)
    {
      int found = 0;
      for (int i = 0; i < n1; i++)
      {
        if (b[j] == a[j])
        {
          found=1;
          break;
        }
      }
      if (found == 0)
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Set s;
  int ch;
  do
  {
    cout << "\n--SET OPERATIONS--" << endl;
    cout << "\n1.Create\n2.Display\n3.Add\n4.Remove\n5.Size\n6.Intersection\n7.Union\n8.Difference\n9.Subset\n10.Exit" << endl;
    cout << "\nEnter your Choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      s.create();
      break;
    case 2:
      cout << "\n";
      s.display();
      break;
    case 3:
      s.add();
      s.display();
      break;
    case 4:
      s.remove();
      s.display();
      break;
    case 5:
      s.size();
      break;
    case 6:
      s.intersection();
      break;
    case 7:
      s.Union();
      break;
    case 8:
      s.Diff();
      break;
    case 9:
      if (s.subset())
      {
        cout << "SET B is Subset of SET A" << endl;
      }
      else
      {
        cout << "No!!! SET B is not Subset of SET A" << endl;
      }
      break;
    case 10:
      cout << "Exiting Program" << endl;
      break;
    default:
      cout << "Invalid Choice" << endl;
      break;
    }

  } while (ch != 10);

  return 0;
}