// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Array
{
private:
int n;
int *arr;
int pos, val, dpos;

public:

void getarray()
{
    cout<< "Read array size"<<endl;
    cin>>n;
    arr=new int [n];
    for (int i=0; i<n-1; i++)
    {
        cout<<"["<< i<<"]";
        cin >>arr[i];
    }
}

void insertarray(){
cout<<"Enter the position " << endl ;
cin >> pos;
cout<< "Enter value to insert at position"<< pos<<endl;
cin>> val;
n++;
cout << n-2;
for (int i=n-2;i> pos-1; i--)
arr[i+1]=arr[i];

arr[pos]=val;
}

void display()
{
    cout<< "Array elements are:" << endl;
    for (int i=0; i<n; i++)
    {
        cout<<" Value at index ";
        cout<<i; 
        cout<< "is:" << arr[i]<< endl;
    }
}

void deletarray(int dpos)
{
    for(int i=dpos;i<n; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
}
};

int main()
{
    int choice;
    Array A;
    int deletepos;
   int Yes=1;
   
   A.getarray();
   while(Yes)
   {
    cout<<" enter your choice"<<endl;
    cout<< "1:Display \n 2: Insert \n 3: Delete 4:Exit "<<endl;
    cin>> choice;
    switch (choice)
    {
      
        case 1:
          A.display();
          break;
          
        case 2:
         A.insertarray();
        break;
        
        case 3:
        cout<< "Enter the position of element to be deleted"<<endl;
        cin>>deletepos;
        A.deletarray(deletepos);
        cout<<"Array after deletion"<<endl;
        A.display();
        break;
        
        case 4:
        exit(0);
        
        default:
        cout<< "invalid choice"<< endl;
    }
    
    cout<< "Do you want to continue if yes press 1";
    cin>> Yes;
   }

}
