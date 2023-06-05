#include <iostream>
#define size 20
using namespace std;

struct node
{
	int x;
	node *next;

	node(int x)
	{
		this->x = x;
		next = NULL;
	}
};

class Stack
{
	char top;
	int s[20];

public:
	Stack()
	{
		top = -1;
	}

	void push(int p)
	{
		if (top == size - 1)
		{
			cout << "Stack is Full!!!" << endl;
		}
		else
		{
			top++;
			s[top] = p;
		}
	}

	int pop()
	{
		int x;
		if (top == -1)
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			x = s[top];
			top--;
			return x;
		}
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Queue
{
	int front, rear;
	int q[size];

public:
	Queue()
	{
		front = -1;
		rear = -1;
	}

	bool Isempty()
	{
		if (rear == -1 && front == -1)
		{
			return true;
		}
		return false;
	}

	bool isFull()
	{
		if (rear == size - 1)
		{
			return true;
		}
		return false;
	}

	void enqueue(int s)
	{
		if (isFull())
		{
			cout << "Overflow Condition" << endl;
		}
		else if (Isempty())
		{
			front = rear = 0;
			q[rear] = s;
		}
		else
		{
			rear++;
			q[rear] = s;
		}
	}

	int dequeue()
	{
		int r;
		if (Isempty())
		{
			cout << "Underflow condition!!!" << endl;
			return 0;
		}
		else
		{
			if (front == rear)
			{
				r = q[front];
				front = rear = -1;
			}
			else
			{
				r = q[front];
				front++;
			}
			return r;
		}
	}
};

class Graph
{
	node *adjList[10];
	int v, e;
	string name[10];
	int *visited;
	int **adjMatrix[10][10];

public:
	Graph(int v, int e)
	{
		this->v = v;
		this->e = e;
		visited = new int[v];
		for (int i = 0; i < v; i++)
		{
			adjList[i] = NULL;
			visited[i] = 0;
			for(int j=0;j<v;j++){
				adjMatrix[i][j]=0;
			}
		}
	}

	void read()
	{
		int s, d;
		string n1, n2;
		cout << "Enter the Names of the Places" << endl;
		for (int i = 0; i < v; i++)
		{
			cin >> name[i];
		}

		for (int i = 0; i < e; i++)
		{
			cout << "Enter the Source and Destination Places" << endl;
			cin >> n1 >> n2;
			for (int j = 0; j < v; j++)
			{
				if (n1 == name[j])
				{
					s = j;
					break;
				}
			}
			for (int j = 0; j < v; j++)
			{
				if (n2 == name[j])
				{
					d = j;
					break;
				}
			}
			node *t1 = new node(s);
			node *t2 = new node(d);

			if (adjList[s] == NULL)
			{
				adjList[s] = t1;
				adjList[s]->next = t2;
			}
			else
			{
				node *head = adjList[s];
				while (head->next != NULL)
				{
					head = head->next;
				}
				head->next = t2;
			}
		}
	}

	void display(){
		node *temp;
		for(int i=0;i<v;i++){
			temp=adjList[i];
			while(temp!=NULL){
				cout<<name[temp->x]<<" -> ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	void DFS(int s,Stack st){
		for(int i=0;i<v;i++){
			visited[i]=0;
		}
		node *temp;
		cout<<name[s]<<" -> ";
		st.push(s);
		visited[s]=1;
		while(!st.isEmpty()){
			int a=st.pop();
			if(visited[a]==0){
				cout<<name[a]<<" -> ";
				visited[a]=1;
			}
			temp=adjList[a];
			while(temp!=NULL){
				if (visited[temp->x]==0){
					st.push(temp->x);
				}
				temp=temp->next;
			}
		}
	}

	void BFS(int s){
		for(int i=0;i<v;i++){
			visited[i]=0;
		}
		Queue q;
		visited[s]=1;
		q.enqueue(s);
		node *temp;
		while(!q.Isempty()){
			s=q.dequeue();
			cout<<name[s]<<" -> ";
			temp=adjList[s];
			while(temp!=NULL){
				if(visited[temp->x]==0){
					q.enqueue(temp->x);
					visited[temp->x]=1;
				}
				temp=temp->next;
			}
		}
	}
};

int main()
{
	int v,e;
	int ch;
	cout<<"Enter the No. of Vertices"<<endl;
	cin>>v;
	cout<<"Enter the No. of Edges"<<endl;
	cin>>e;
	Graph g(v,e);
	Stack s;
	do
	{
		cout<<"\nMenu"<<endl;
		cout<<"1.Read the Graph"<<endl;
		cout<<"2.Display the Graph"<<endl;
		cout<<"3.DFS of the Graph"<<endl;
		cout<<"4.BFS of the Graph"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;

		switch (ch)
		{
		case 1:
			g.read();
			break;
		case 2:
			g.display();
			break;
		case 3:
			g.DFS(0,s);
			break;
		case 4:
			g.BFS(0);
			break;
		case 5:
			cout<<"Exiting the Program!!!"<<endl;
			break;
		default:
			cout<<"Invalid Choice"<<endl;
			break;
		}
	} while (ch!=5);
	
	return 0;
}