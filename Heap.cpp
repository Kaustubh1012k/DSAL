#include <iostream>
using namespace std;
#define Max 10
class heap
{
    int Minheap[Max], Maxheap[Max];

public:
    void createHeap()
    {
        int n;
        int x;
        cout << "\nEnter Number of Students: ";
        cin >> n;

        Minheap[0] = 0;
        Maxheap[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the Marks of Student " << i + 1 << " : ";
            cin >> x;
            insertMinHeap(x);
            insertMaxHeap(x);
        }
    }

    void insertMinHeap(int x)
    {
        int n = Minheap[0];
        Minheap[n + 1] = x;
        Minheap[0] = n + 1;
        upAdjustMinHeap(n + 1);
    }

    void insertMaxHeap(int x)
    {
        int n = Maxheap[0];
        Maxheap[n + 1] = x;
        Maxheap[0] = n + 1;
        upAdjustMaxHeap(n + 1);
    }

    void upAdjustMinHeap(int u)
    {
        while (u > 1 && Minheap[u] < Minheap[u / 2])
        {
            if(Minheap[u/2]>Minheap[u]){
            int temp = Minheap[u / 2];
            Minheap[u / 2] = Minheap[u];
            Minheap[u] = temp;
            }
            u = u / 2;
        }
    }

    void upAdjustMaxHeap(int u)
    {
        while (u > 1 && Maxheap[u] > Maxheap[u / 2])
        {
            if(Maxheap[u/2]<Maxheap[u]){
            int temp = Maxheap[u / 2];
            Maxheap[u / 2] = Maxheap[u];
            Maxheap[u] = temp;
            }
            u = u / 2;
        }
    }

    int findMax()
    {
        return Maxheap[1];
    }

    int findMin()
    {
        return Minheap[1];
    }
};
int main()
{
    heap H;
    H.createHeap();
    cout << "The max value is :" << H.findMax() << endl;
    cout << "The min value is :" << H.findMin() << endl;
    return 0;
}
