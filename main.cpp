
#include <bits/stdc++.h>
using namespace std;
 
// Node Class
class chain;

class Node {
    friend class chain;
private:
    string USN;
    string Name;
    string Branch;
    int Sem;
    int phno;
    Node* next;

};

class chain{
private:
    Node *head;
public:
chain()
{
    head=0;
}
bool check(string x)
{
    // Base Case
    if (head == NULL)
        return false;
 
    Node* t= new Node();
    t=head;
    // Traverse the Linked List
    while (t != NULL) {
        if (t->USN == x)
            return true;
        t = t->next;
    }
 
    return false;
} 

void Insert_Record(string USN, string Name, string Branch, int Sem, int phno)
{
    // if Record Already Exist
   if (check(USN)) {
        cout << "Student with this "
             << "record Already Exists\n";
        return;
    } 
 //cout<<"Hello";
    // Create new Node to Insert Record
    Node* t = new Node();
    t->USN = USN;
    t->Name = Name;
    t->Branch = Branch;
    t->Sem = Sem;
    t->phno=phno;
    t->next = NULL;
 
    // Insert at Begin
    if (head == NULL|| (head->USN >= t->USN)) {
        t->next = head;
        head = t;
    }
 
    // Insert at middle or End
    else {
        Node* c = head;
        while (c->next != NULL
               && c->next->USN < t->USN) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
 
    cout << "Record Inserted "
         << "Successfully\n";
}

 void Search_Record(string USN)
{
    // if head is NULL
    if (!head) {
        cout << "No such Record "
             << "Available\n";
        return;
    }
 
    // Otherwise
    else {
        Node* p = head;
        while (p) {
            if (p->USN == USN) {
                cout << "USN \t"<< p->USN << endl;
                cout << "Name\t\t"<< p->Name << endl;
                cout << "Branch\t"<< p->Branch << endl;
                cout << "Semester\t\t"<< p->Sem << endl;
                cout << "Phone Number\t\t"<< p->phno << endl;
                return;
            }
            p = p->next;
        }
 
        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}
 
int Delete_Record(string USN)
{
    Node* t = head;
    Node* p = NULL;
 
    // Deletion at Begin
    if (t != NULL
        && t->USN == USN) {
        head = t->next;
        delete t;
 
        cout << "Record Deleted "
             << "Successfully\n";
        return 0;
    }
 
    // Deletion Other than Begin
    while (t != NULL && t->USN != USN) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;
 
        delete t;
        cout << "Record Deleted "
             << "Successfully\n";
 
        return 0;
    }
}
 
void Show_Record()
{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record "
             << "Available\n";
    }
    else {
        cout << "USN\tName\t Branch\t Sem \t PhNo\n"<<endl;
 
        // Until p is not NULL
        while (p != NULL) {
            cout << p->USN << "\t" << p->Name << "\t"
                 << p->Branch << "\t"
                 << p->Sem << "\t"
                 << p->phno<<endl;
            p = p->next;
        }
    }
}
    
};


int main()
{
    chain c;
    int flag=0;
    string stname;
  string stUSN;
    string stBranch;
    int stsem;
int stphno;
    
    // Menu-driven program
    while (true) {
        cout << "\n\t\tWelcome to Student Record "
                "Management System\n\n\tPress\n\t1 to "
                "create a new Record\n\t2 to delete a "
                "student record\n\t3 to Search a Student "
                "Record\n\t4 to view all students "
                "record\n\t5 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;
 
        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Name of Student\n";
            cin >> stname;
            cout << "Enter USN of Student\n";
            cin >> stUSN;
            cout << "Enter Department of Student \n";
            cin >> stBranch;
            cout << "Enter Semester of Student\n";
            cin >> stsem;
            cout << "Enter Phone number of Student\n";
            cin >> stphno;
           // flag=c.check(stroll);
           // cout<<flag;
            //if (flag==0)
            c.Insert_Record(stUSN, stname, stBranch, stsem, stphno);
            //else 
            //cout<<"duplicate entry";
        }
        else if (Choice == 2) {
            cout << "Enter Roll Number of Student whose "
                    "record is to be deleted\n";
            cin >> stUSN;
            c.Delete_Record(stUSN);
        }
        else if (Choice == 3) {
            cout << "Enter Roll Number of Student whose "
                    "record you want to Search\n";
            cin >> stUSN;
            c.Search_Record(stUSN);
        }
        else if (Choice == 4) {
            c.Show_Record();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}
