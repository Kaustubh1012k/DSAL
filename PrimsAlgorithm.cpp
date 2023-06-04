#include<iostream>
using namespace std;

class Office{
    int n;
    int a[10][10];
    string office[10];

    public:

    void input(){
        cout<<"Enter Number of Offices: ";
        cin>>n;
        cout<<"Enter the Location of Offices: ";
        for(int i=0;i<n;i++){
            cin>>office[i];
        }

        cout<<"\nEnter the Cost to Connect the Offices: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j){
                    a[i][j]=0;
                    continue;
                }

                cout<<"Enter the cost to connect "<<office[i]<<" and "<<office[j]<<" : ";
                cin>>a[i][j];
                a[j][i]=a[i][j];
            }
        }
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<"\n";
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<"\t";
            }
        }
    }

    void Prims(){
        int visit[n],minCost=0,count=n-1,minIndex,cost=0;
        for(int i=0;i<n;i++){
            visit[i]=0;
        }

        cout<<"\nShortest Path: ";
        visit[0]=1;
        cout<<office[0]<<" -> ";

        while(count--){
            minCost=100;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(visit[i]==1 && a[i][j]!=0 && a[i][j]<minCost && visit[j]==0){
                        minCost=a[i][j];
                        minIndex=j;
                    }
                }
            }

            visit[minIndex]=1;
            cout<<office[minIndex]<<" -> ";
            cost=cost+minCost;
        }
        cout<<"End";

        cout<<"\nMinimum Cost: "<<cost;
    }
};

int main(){
    Office o1;
    int choice;
    do
    {
        cout<<"\n---PRIMS ALGORITHM---"<<endl;
        cout<<"\n-Main Menu-"<<endl;
        cout<<"1.Input Data"<<endl;
        cout<<"2.Display Data"<<endl;
        cout<<"3.Calculate Minimum cost"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"\nEnter your Choice: ";
        cin>>choice;
        cout<<"\n";

        switch (choice)
        {
        case 1:
            o1.input();
            break;
        
        case 2:
            o1.display();
            break;

        case 3:
            o1.Prims();
            break;
        case 4:
            cout<<"Exiting The Program !!!"<<endl;
            break;
        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    } while (choice!=4);
    
    return 0;
}