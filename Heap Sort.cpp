#include<iostream>
using namespace std;

class heap
{
    int a[10],sort[10],n;
    public:
    void insert(int a[],int x)
    {
       
        n=a[0];
        a[n+1]=x;
        a[0]=n+1;
        
        upadjust(a,n+1);
    }
    void upadjust(int a[],int i)
    {
        while(i>1 && a[i]>a[i/2])
        {
            if(a[i]>a[i/2])
            {
                int t=a[i/2];
                a[i/2]=a[i];
                a[i]=t;
            }
            i=i/2;
        }
    }
    void display(int a[])
    {
        int p=a[0];
        cout<<"The max heap is:"<<endl;
        for(int k=1;k<p+1;k++)
        {
            cout<<a[k]<<endl;
        }
    }

    void heapsort(int a[],int n)
    {
        int m=n;
        int i=0;
        while(n>0)
        {
            int t=a[1];
            a[1]=a[n];
            a[n]=t;
            n--;
            upadjust(a,n);
            sort[i]=t;
            i++;
        }
        cout<<"Max:"<<sort[0]<<endl;
        cout<<"Min:"<<sort[m-1];
}
};
int main()
{
    heap h;
    int a[10],n,x;
    a[0]=0;
    
    cout<<"Enter no. of students:"<<endl;
    cin>>n;
    cout<<"Enter marks of students:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        h.insert(a,x);

    }
    h.heapsort(a,n);
    return 0;
}
