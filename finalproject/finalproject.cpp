#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

int checkDay(int day, int month, int year)
{
    if (month <= 0 || month > 12)
    {
        return -2;
    }
    int daysPerMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    {
        return 1;
    }
    if (day > 0 && day <= daysPerMonth[month])
    {
        return 1;
    }
    return -1;
}

string StringToUpper(string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}

struct Staff // initiate the Staff type
{
    int ID; // MS nhan vien
    string stafName;
    string iden_ID; // CCCD
    Date birthDay;  // Staff's birthday
    string gender;
    string phone_Num;
    string Address;
    int working_time; // Staff's workingtime
    string job;  // Staff's job
    int Salary;       // Salary after caculating by multiple between working time and their salary per hour
    int department;
    Staff() {}        // constructor

    void inputStaffMODI(int StaffID)
    {

        this->ID = StaffID;
        bool flag = false;
        do
        {
            flag = true;
            cout << "Enter the Staff's Name :" << endl;
            cin.ignore();
            getline(cin, this->stafName);
            for (int i = 0; i < stafName.length(); i++)
            {
                if (!isalpha(stafName[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);
        do
        {
            flag = true;
            cout << "Enter the Staff's Identify ID:" << endl;
            // cin.ignore();
            getline(cin, this->iden_ID);
            for (int i = 0; i < iden_ID.length(); i++)
            {
                if (!isdigit(iden_ID[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);

        cout << "Enter the Staff's Birthday :" << endl;

        do
        {
            do
            {
                cout << "Input staff day of birth: ";
                cin >> this->birthDay.day;

                if (this->birthDay.day < 1 || this->birthDay.day > 31)
                {
                    cout << "Please, Input staff day of birth Again (1 -. 31): " << endl;
                }
            } while (this->birthDay.day < 1 || this->birthDay.day > 31); // check lai

            do
            {
                cout << "Input staff month of birth: ";
                cin >> this->birthDay.month;
                if (this->birthDay.month < 1 || this->birthDay.month > 12)
                {
                    cout << "Please, Input staff month of birth Again (1 -. 12): " << endl;
                }
            } while (this->birthDay.month < 1 || this->birthDay.month > 12); // check lai

            do
            {
                cout << "Input student year of birth: ";
                cin >> this->birthDay.year;
                if (this->birthDay.year < 1980 || this->birthDay.year > 2022)
                {
                    cout << "Please, Input staff year of birth Again (1980 -. 2022): " << endl;
                }
            } while (this->birthDay.year < 1980 || this->birthDay.year > 2022); // check lai

            if (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0)
            {
                cout << "Please, Input birthday again!\n";
            }
        } while (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0);
        char dgender;
        cout << "Enter gender (M/m or F/f): ";
        cin >> dgender;

        switch (dgender)
        {
        case 'M':
        case 'm':
            this->gender = "Male";
            break;
        case 'F':
        case 'f':
            this->gender = "Female";
            break;
        default:
            cout << "Unspecified Gender" << endl;
        }

        do
        {
            flag = true;
            cout << "Enter the Staff's Phone number  :" << endl;

            cin.ignore();
            getline(cin, this->phone_Num);
            for (int i = 0; i < phone_Num.length(); i++)
            {
                if (!isdigit(phone_Num[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);

        cout << "Enter the Staff's Address  :" << endl;
        getline(cin, this->Address);
        cout << "Enter the Staff's Working Time  :" << endl;
        cin >> this->working_time;
        int check = 0, option = 0;
        cout << "Enter the Staff's job in company  :" << endl;
        while (check == 0) {
            cout << "* 1.programmer / 2.tester / 3.designer / 4.manager *" << endl;
            cout << "Please choose an option:";
            cin >> option;
            if (option < 1 || option >4) {
                cout << "Enter the Staff's job in company again! :" << endl;
            }
            if (option == 1) {
                this->job = "programmer";
                check = 1;
            }
            if (option == 2) {
                this->job = "tester";
                check = 1;
            }
            if (option == 3) {
                this->job = "designer";
                check = 1;
            }
            if (option == 4) {
                this->job = "manager";
                check = 1;
            }
        }
        cout << "Enter the Staff's Department in company  (1->5) :" << endl;
        cin >> this->department;
        while (department < 1 || department>5) {
            cout << "Please enter the Staff's Department again!(1->5)" << endl;
            cin >> this->department;
        }
        this->Salary = salaryFunction();
    }

    Staff(int id, string name, string idenid, int bDay, int bMon, int byear, char gen, string phone, string Address, int working, string job, int department)
    {
        this->ID = id;
        this->stafName = name;
        this->iden_ID = idenid;
        this->birthDay.day = bDay;
        this->birthDay.month = bMon;
        this->birthDay.year = byear;
        switch (gen)
        {
        case 'M':
        case 'm':
            this->gender = "Male";
            break;
        case 'F':
        case 'f':
            this->gender = "Female";
            break;
        default:
            cout << "Unspecified Gender" << endl;
        }
        // this->gender = gen;
        this->phone_Num = phone;
        this->Address = Address;
        this->working_time = working;
        this->job = job;
        this->department = department;
        this->Salary = salaryFunction();
    }

    int salaryFunction()
    {
        int iSalary = 0;
        if (this->job == "tester")
        {
            iSalary = this->working_time * 22000;
            return iSalary;
        }
        if (this->job == "programmer")
        {
            iSalary = this->working_time * 30000;
            return iSalary;
        }
        if (this->job == "manager")
        {
            iSalary = this->working_time * 25000;
            return iSalary;
        }
        if (this->job == "designer")
        {
            iSalary = this->working_time * 27000;
            return iSalary;
        }

        else
            return 0;
    }
    void inputStaff()
    {
        cout << "Enter the Staff's ID :\n";
        cin >> this->ID;
        bool flag = false;
        do
        {
            flag = true;
            cout << "Enter the Staff's Name :" << endl;
            cin.ignore();
            getline(cin, this->stafName);
            for (int i = 0; i < stafName.length(); i++)
            {
                if (!isalpha(stafName[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);
        do
        {
            flag = true;
            cout << "Enter the Staff's Identify ID:" << endl;
            // cin.ignore();
            getline(cin, this->iden_ID);
            for (int i = 0; i < iden_ID.length(); i++)
            {
                if (!isdigit(iden_ID[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);

        cout << "Enter the Staff's Birthday :" << endl;

        do
        {

            do
            {
                cout << "Input staff day of birth: ";
                cin >> this->birthDay.day;

                if (this->birthDay.day < 1 || this->birthDay.day > 31)
                {
                    cout << "Please, Input staff day of birth Again (1 - 31): " << endl;
                }
            } while (this->birthDay.day < 1 || this->birthDay.day > 31); // check lai

            do
            {
                cout << "Input staff month of birth: ";
                cin >> this->birthDay.month;
                if (this->birthDay.month < 1 || this->birthDay.month > 12)
                {
                    cout << "Please, Input staff month of birth Again (1 - 12): " << endl;
                }
            } while (this->birthDay.month < 1 || this->birthDay.month > 12); // check lai

            do
            {
                cout << "Input student year of birth: ";
                cin >> this->birthDay.year;
                if (this->birthDay.year < 1980 || this->birthDay.year > 2022)
                {
                    cout << "Please, Input staff year of birth Again (1980 - 2022): " << endl;
                }
            } while (this->birthDay.year < 1980 || this->birthDay.year > 2022); // check lai

            if (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0)
            {
                cout << "Please, Input birthday again!\n";
            }
        } while (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0);
        char dgender;
        cout << "Enter gender (M/m or F/f): ";
        cin >> dgender;

        switch (dgender)
        {
        case 'M':
        case 'm':
            this->gender = "Male";
            break;
        case 'F':
        case 'f':
            this->gender = "Female";
            break;
        default:
            cout << "Unspecified Gender" << endl;
        }

        do
        {
            flag = true;
            cout << "Enter the Staff's Phone number: " << endl;

            cin.ignore();
            getline(cin, this->phone_Num);
            for (int i = 0; i < phone_Num.length(); i++)
            {
                if (!isdigit(phone_Num[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);

        cin.ignore();
        cout << "Enter the Staff's Address  :" << endl;
        getline(cin, this->Address);

        cout << "Enter the Staff's Working Time  :" << endl;
        cin >> this->working_time;
        int check = 0, option = 0;
        cout << "Enter the Staff's job in company  :" << endl;
        while (check == 0) {
            cout << "* 1.programmer / 2.tester / 3.designer / 4.manager *" << endl;
            cout << "Please choose an option:";
            cin >> option;
            if (option < 1 || option >4) {
                cout << "Enter the Staff's job in company again! :" << endl;
            }
            if (option == 1) {
                this->job = "programmer";
                check = 1;
            }
            if (option == 2) {
                this->job = "tester";
                check = 1;
            }
            if (option == 3) {
                this->job = "designer";
                check = 1;
            }
            if (option == 4) {
                this->job = "manager";
                check = 1;
            }
        }
        cout << "Enter the Staff's Department in company  (1->5) :" << endl;
        cin >> this->department;
        while (department < 1 || department>5) {
            cout << "Please enter the Staff's Department again!(1->5)" << endl;
            cin >> this->department;
        }
        this->Salary = salaryFunction();
    }
    void print()
    { 
        cout << "|" << setw(4) << left << this->ID << "|"
            << setw(9) << left << StringToUpper(this->stafName) << "|"
            << setw(9) << left << this->iden_ID << "|"
            << this->birthDay.day << "/" << this->birthDay.month << "/" << this->birthDay.year << "\t"
            << "|"
            << setw(9) << left << StringToUpper(this->gender) << "|"
            << setw(9) << left << this->phone_Num << "|"
            << setw(12) << left << StringToUpper(this->Address) << "|"
            << setw(12) << left << this->working_time << "|"
            << setw(11) << left << StringToUpper(this->job) << "|"
            << setw(10) << left << this->Salary << "|"  
            << left << this->department << "|" << endl;

    
    }
    void printSalary(int x)
    {
        cout << "|" << setw(4) << left << this->ID << "|"
            << setw(9) << left << StringToUpper(this->stafName) << "|"
            << setw(10) << left << this->Salary * x << "|"  // << "|" << '\n';
            << left << this->department << "|" << endl;
    }
};
//================================================= linked list=============================================
struct Node 
{
public:
    Staff stafData; 
    Node* next;   
    void Init(Staff nv)
    {
        stafData = nv;
        next = NULL;
    }
};
struct list_Staff
{
    int id;
    Staff* value;
};
class SinglyList 
{
private:
    Node* pHead = NULL; 
    int len;          
public:
   
    SinglyList()
    {
        pHead = NULL;
        len = 0;
    }
    Node* getRoot()
    {
        return pHead;
    }
    bool isEmptyL()
    {
        return pHead == NULL;
    }
    int addtoTail(Staff nv)
    { 
        Node* p = new Node();
        p->stafData = nv;
        p->next = NULL;
        if (isEmptyL())
        { 
            pHead = p;
            len++;
            return 1;
        }
        else
        {                       
            Node* temp = pHead; 
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
            len++;
            return 1;
        }
        return 0;
    }
    int removeNode(int StaffID)
    {
        Node* temp = pHead;
        int finalnodecheck = 0;
        if (isEmptyL())
        { 
            cout << "Can't find any Staff with that ID \n";
            return 0;
        }
       
        else if (temp->stafData.ID == StaffID)
        {
           
            pHead = temp->next;

            
            free(temp);
            return 1;
        }
        else
        {
            while (temp->next->stafData.ID != StaffID)
            {
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL)
                return 0;

            Node* next = temp->next->next;

            free(temp->next); 

            temp->next = next;

            return 1;
        }
        return 0;
    }
    Staff searchNode(int StaffID)
    {
        Node* temp = pHead; 
        int finalnodecheck = 0;
        if (isEmptyL())
        { 
            cout << "Can't find any Staff with that ID \n";
            Staff temp1;
            return temp1;
        }
        else
        {
            while (temp->stafData.ID != StaffID)
            {
                temp = temp->next;
            }
            return temp->stafData;
        }
    }
    void printList()
    {

        cout << setw(5) << left << "|ID"
            << setw(10) << left << "|Name"
            << setw(10) << left << "|CCCD"
            << setw(15) << left << "|Birhday"
            << setw(10) << left << "|Gender"
            << setw(10) << left << "|Phone"
            << setw(13) << left << "|Address"
            << setw(13) << left << "|Working_time"
            << setw(12) << left << "|Job"
            << setw(11) << left << "|Salary"
            << setw(10) << left << "|Department" << "\n";
        cout << endl;

        for (Node* k = pHead; k != NULL; k = k->next)
        {

            k->stafData.print();
            cout << '\n';
        }
    }

    void modiStaf(int StaffID)
    {
        Node* temp = pHead; 
        Staff modi;
        modi.inputStaffMODI(StaffID);
        Node* p = new Node();
        p->stafData = modi;
        p->next = NULL;
        int finalnodecheck = 0;
        if (isEmptyL())
        { 
            cout << "Can't find any Staff with that ID \n";
            Staff temp1;
        }
        else if (temp->stafData.ID == StaffID)
        {
            pHead = p;
            free(temp);
        }
        else
        {
            while (temp->next->stafData.ID != StaffID)
            {
                temp = temp->next;
            }
            Node* next = temp->next->next;
            temp->next = p;
            p->next = next;
        }
    }
};
//===================== Queue ===========================
class QNode {
public:
    int data;
    QNode* next;
    QNode(int x) {
        data = x;
        next = NULL;
    }
};
class LQueue {
private:
    QNode* front, * rear;
public:
    LQueue() {
        front = rear = NULL;
    }
    void SetQueue() {
        front = rear = NULL;
    }
    void enQueue(int x) {
        QNode* temp = new QNode(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void deQueue() {
        if (front == NULL) return;
        QNode* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete (temp);
    }
    QNode* queueFront() {
        if (front == NULL) {
            cout << "There is no staff!" << endl;
            return {};
        }
        return front;
    }
    void displayQueue(int a[]) {
        if (front->data == NULL) {
            cout << "There is no staff!" << endl;
            return;
        }
        QNode* temp = front;
        while (temp != NULL) {
            for (int i = 0; i < 5; i++) {
                if (temp->data == a[i]) {
                    cout << "Department " << i + 1 << ":";
                    cout << temp->data << endl;
                }
            }
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    void Bubble_Sort(int x) {
        if (x == 1) {
            for (QNode* i = front; i != NULL; i = i->next) {
                for (QNode* j = i->next; j != NULL; j = j->next) {
                    if (i->data > j->data)
                    {
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }
        if (x == 2) {
            for (QNode* i = front; i != NULL; i = i->next) {
                for (QNode* j = i->next; j != NULL; j = j->next) {
                    if (i->data < j->data)
                    {
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }
    }
};
void AddSalaryToQueue(LQueue& Queue, list_Staff Lists[], int k, int day) {
    int totalSalary = 0;
    if (day == 1) {
        for (int i = 1; i <= 5; i++) {
            totalSalary = 0;
            for (int j = 0; j < k; j++) {
                if (Lists[j].value->department == i) {
                    totalSalary += Lists[j].value->Salary;
                }
            }
            Queue.enQueue(totalSalary);
        }
    }
    if (day == 30) {
        for (int i = 1; i <= 5; i++) {
            totalSalary = 0;
            for (int j = 0; j < k; j++) {
                if (Lists[j].value->department == i) {
                    totalSalary += (Lists[j].value->Salary * 30);
                }
            }
            Queue.enQueue(totalSalary);
        }
    }
    if (day == 365) {
        for (int i = 1; i <= 5; i++) {
            totalSalary = 0;
            for (int j = 0; j < k; j++) {
                if (Lists[j].value->department == i) {
                    totalSalary += (Lists[j].value->Salary * 365);
                }
            }
            Queue.enQueue(totalSalary);
        }
    }
}
//==================== Hash table ====================
class Hashtable
{

private:
    int hashGroups = 11;    // the bucket capacity
    SinglyList* StafBucket; // the node pointer to the main array
    /*
     * List 1 - Index 0,
     * List 2 - Index 1,
     * ...
     */
public:
    Hashtable(int ListNum)
    {
        this->hashGroups = ListNum;
        StafBucket = new SinglyList[hashGroups]; // point to the node array
    }
    bool isEmpty(); // check whether bucket empty or not
    int hashFunction(Staff value);
    void insertStaf(Staff value);
    void removeStaf(int StaffID);
    void searchTable(int StaffID);
    void printTable();
    void hash_to_list(list_Staff list[], int& k);
    void modiStaf(int StaffID);
};

void Hashtable::modiStaf(int StaffID)
{
    Staff term;
    int hashValue = StaffID % hashGroups;
    term = StafBucket[hashValue].searchNode(StaffID);
    if (term.ID < 0)
    {
        cout << "Can't find any Staff with that ID \n";
    }
    else
    {
        StafBucket[hashValue].modiStaf(StaffID);
    }
}

void Hashtable::hash_to_list(list_Staff list[], int& k)
{
    k = 0;
    for (int i = 0; i < hashGroups; i++)
    {
        if (StafBucket[i].isEmptyL() == false)
        {
            Node* p = StafBucket[i].getRoot();
            while (p != NULL)
            {
                list[k].id = p->stafData.ID;
                list[k].value = &p->stafData;
                k++;
                p = p->next;
            }
        }
    }
}

bool Hashtable::isEmpty()
{
    int sum = 0;
    for (int i = 0; i < hashGroups; i++)
    {
        if (StafBucket[i].isEmptyL() == false)
        {
            sum++;
        }
    }
    return sum == 0;
}
int Hashtable::hashFunction(Staff value)
{
    return value.ID % hashGroups;
}
void Hashtable::insertStaf(Staff value)
{
    int hashValue = hashFunction(value);
    StafBucket[hashValue].addtoTail(value);
}
void Hashtable::removeStaf(int StaffID)
{
    int hashValue = StaffID % hashGroups;
    StafBucket[hashValue].removeNode(StaffID);
    return;
}
void Hashtable::printTable()
{
    for (int i = 0; i < hashGroups; i++)
    {
        if (StafBucket[i].isEmptyL() == true)continue;
        cout << "[TARGET] : No." << i << endl;
        cout << "***************************************************************************************************************************" << endl;
        StafBucket[i].printList();
        cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
    return;
}
void Hashtable::searchTable(int StaffID)
{
    Staff term;
    int hashValue = StaffID % hashGroups;
    term = StafBucket[hashValue].searchNode(StaffID);
    if (term.ID < 0)
    {
        // cout << "Can't find any Staff with that ID \n";
    }
    else
    {
        term.print();
    }
}

//============================================================================
void swap(list_Staff& a, list_Staff& b)
{
    list_Staff c = a;
    a = b;
    b = c;
}

void Increase(list_Staff list[], int k, int index)
{

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (index == 1)
            {
                if (list[i].id > list[j].id)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 2)
            {
                if (list[i].value->Salary > list[j].value->Salary)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 3)
            {
                if (list[i].value->working_time > list[j].value->working_time)
                {
                    swap(list[i], list[j]);
                }
            }
        }
    }
}

void Decrease(list_Staff list[], int k, int index)
{

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (index == 1)
            {
                if (list[i].id < list[j].id)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 2)
            {
                if (list[i].value->Salary < list[j].value->Salary)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 3)
            {
                if (list[i].value->working_time < list[j].value->working_time)
                {
                    swap(list[i], list[j]);
                }
            }
        }
    }
}

void PrintEMList(list_Staff list[], int k, int room, string x)
{
    cout << "********************************************************************************************************************************\n";
    cout << setw(5) << left << "ID"
        << setw(10) << left << "Name" << "\t"
        << setw(10) << left << "CCCD"
        << setw(14) << left << "Birhday"
        << setw(10) << left << "Gender"
        << setw(10) << left << "Phone"
        << setw(13) << left << "Address"
        << setw(15) << left << "Working_time"
        << setw(11) << left << "Job"
        << setw(10) << left << "Salary"
        << setw(10) << left << "Department" << "\n";

    for (int i = 0; i < k; i++)
    {
        if (room == 6) {
            list[i].value->print();
            cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\n";
        }
        if (room <= 5) {
            if (list[i].value->department == room) {
                list[i].value->print();
                cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n";
            }
        }
        if (room == 7) {
            if (list[i].value->job == x) {
                list[i].value->print();
                cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n";
            }
        }
    }
    cout << endl;
}
void PrintEMListSalary(list_Staff list[], int k, int x)
{
    cout << "*********************************************************************************************************************************\n";
    cout << setw(5) << left << "ID"
        << setw(10) << left << "Name" << "\t"
        << setw(10) << left << "Salary"
        << setw(10) << left << "Department" << "\n";

    for (int i = 0; i < k; i++)
    {
        list[i].value->printSalary(x);
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n";
    }
    cout << endl;
}
// Dang excel
void PrintEMList_Excel(list_Staff list[], int k)
{
    cout << "*********************************************************************************************************************************\n";
    cout << setw(5) << left << "ID"
        << setw(10) << left << "Name" << "\t"
        << setw(10) << left << "CCCD"
        << setw(14) << left << "Birhday"
        << setw(10) << left << "Gender"
        << setw(10) << left << "Phone"
        << setw(13) << left << "Address"
        << setw(15) << left << "Working_time"
        << setw(11) << left << "Position"
        << setw(10) << left << "Salary"
        << setw(10) << left << "Department" << "\n";

    for (int i = 0; i < k; i++)
    {
        // cout << "ID :";
        list[i].value->print();
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << endl;
}

void Input(Hashtable heads, string arr[], int n)
{
    int step = n / 12;
    for (int i = 0; i < step; i++)
    {
        int a = i * 12;
        Staff dt;
        dt.ID = stoi(arr[a]);
        dt.stafName = arr[a + 1];
        dt.iden_ID = arr[a + 2];
        dt.birthDay.day = stoi(arr[a + 3]);
        dt.birthDay.month = stoi(arr[a + 4]);
        dt.birthDay.year = stoi(arr[a + 5]);
        dt.gender = arr[a + 6];
        dt.phone_Num = arr[a + 7];
        dt.Address = arr[a + 8];
        dt.working_time = stoi(arr[a + 9]);
        dt.job = arr[a + 10];
        dt.Salary = dt.salaryFunction();
        dt.department = stoi(arr[a + 11]);

        heads.insertStaf(dt);
    }
}


void ReadFile(string arr[], int& n)
{
    fstream read_File;
    string s;
    n = 0;
    read_File.open("D:/DATA/ds.txt", ios_base::in);
    if (!read_File)
    {
        cout << "Khong the mo file!";
    }
    else
    {
        char ch;

        while (1)
        {
            read_File >> ch;
            if (read_File.eof())
                break;
            if (ch != ',' && ch != '/')
            {
                s += ch;
            }
            else
            {
                arr[n] = s;
                s = "";
                n++;
            }
        }
    }
}

void TextColor(int x) // X lÃ  mÃ£ mÃ u
{
    // CÃ¡c hÃ m nÃ y lÃ  hÃ m thao tÃ¡c API vá»›i windows báº¡n cá»© coppy thÃ´i khÃ´ng cáº§n pháº£i hiá»ƒu quÃ¡ sÃ¢u
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

int main()
{
    int id, Choose, chon = 0, k = 0, n = 0;
    Hashtable HashTb(10);
    Staff term, result;
    string arr[300];
    int field, luachon;
    list_Staff ListStaf[10];
    LQueue QueueStaf;

    do
    {
        system("cls");
        TextColor(12);
        printf(" ********************GROUP 2*******************\n");
        printf("||GROUP TOPIC : STAFF MANAGEMENT SYSTEM       |\n");
        printf("||GROUP 2 MEMBER LIST :                       |\n");
        printf("||1-NGUYEN QUOC HUNG  - 22110039              |\n");
        printf("||2-NGUYEN NGOC HONG ANH  - 21110754          |\n");
        printf("||3-DINH TO QUOC THANG - 22110070             |\n");
        printf("||4-DANG HOANG VIET - 22110089                |\n");
        printf(" **********************************************\n");
        TextColor(7);


        printf("\n\n\n\n\n");
        printf("\t\t\t\t *********************MENU**************************\n");
        printf("\t\t\t\t |1. Them danh sach nhan vien tu file              |\n");
        printf("\t\t\t\t |2. Xuat danh sach nhan vien                      |\n");
        printf("\t\t\t\t |3. Tim Kiem nhan vien ma ID                      |\n");
        printf("\t\t\t\t |4. Xuat danh sach nhan vien                      |\n");
        printf("\t\t\t\t |5. Xoa nhan vien theo ma ID                      |\n");
        printf("\t\t\t\t |6. Them mot nhan vien                            |\n");
        printf("\t\t\t\t |7. Sua nhan vien theo ID                         |\n");
        printf("\t\t\t\t |8. Xuat luong theo phong ban                     |\n");
        printf("\t\t\t\t |9. Xuat luong nhan vien                          |\n");
        printf("\t\t\t\t |0. Thoat                                         |\n");
        printf("\t\t\t\t ***************************************************\n");

        printf("Moi ban chon: ");
        cin >> chon;
        switch (chon)
        {
        case 1:
            ReadFile(arr, n);
            Input(HashTb, arr, n);
            system("pause");
            break;
        case 2:
            HashTb.printTable();
            system("pause");
            break;
        case 3:
            cout << "Nhap ID ban muon tim kiem: "; cin >> id;
            cout << "************************************************************Search************************************************************" << endl;
            HashTb.searchTable(id);
            system("pause");
            break;
        case 4:

            //cout << "\n Sap xep thong tin nhan vien TANG/GIAM theo ID/SALARY/WORKING_TIME" << endl;
            //cout << "Nhap 0 de thoat sap xep!" << endl;


            while (true)
            {
                system("cls");
                cout << "\n Sap xep thong tin nhan vien TANG/GIAM theo ID/SALARY/WORKING_TIME" << endl;
                printf(" *********************MENU**************************\n");
                printf(" |1. Xuat danh sach nhan vien                      |\n");
                printf(" |2. Xuat danh sach nhan vien - Dang Excel         |\n");
                printf(" |3. Xuat danh sach theo phong ban                 |\n");
                printf(" |4. Xuat danh sach nhan vien theo ID              |\n");
                printf(" |5. Xuat danh sach nhan vien theo Salary          |\n");
                printf(" |6. Xuat danh sach nhan vien theo Working time    |\n");
                printf(" |7. Xuat danh sach theo chuc vu                   |\n");
                printf(" |0. Thoat                                         |\n");
                printf(" ***************************************************\n");
                /*cout << "\n**Note: id hoac ID";
                cout << "\n**Note: Salary hoac salary hoac s hoac S" << endl;
                cout << "**Note: 0 Thoat sap xep" << endl;*/
                cout << "\n Xin vui long nhap lua chon: ";
                cin >> field;

                if (field == 0) {     // thoat khoi vong lap nhap field: khong can nhap id hoac salary de sap xep
                    break;
                }
                else {
                    while (true)
                    {
                        system("cls");

                        if (field == 1) {
                            cout << "\t\t\t*********************************List of Staff***********************************\n";
                            HashTb.hash_to_list(ListStaf, k);
                            PrintEMList(ListStaf, k, 6, "x");
                            system("pause");
                            break;
                        }
                        else if (field == 2) {
                            cout << "\t\t\t*********************************List of Staff - Excel*********************************\n";
                            HashTb.hash_to_list(ListStaf, k);
                            PrintEMList_Excel(ListStaf, k);
                            system("pause");
                            break;
                        }
                        else if (field == 3) {
                            printf(" *************************PHONG BAN**************************\n");
                            printf(" |1. Phong ban 1                                            |\n");
                            printf(" |2. Phong ban 2                                            |\n");
                            printf(" |3. Phong ban 3                                            |\n");
                            printf(" |4. Phong ban 4                                            |\n");
                            printf(" |5. Phong ban 5                                            |\n");
                            printf(" |0. Thoat                                                  |\n");
                            printf(" ************************************************************\n");
                            cout << "\n Vui long lua chon phong ban: ";
                            cin >> luachon;
                            if (luachon == 1) {
                                cout << "\t\t\t**************************PHONG BAN 1***********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 1, "x");
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t**************************PHONG BAN 2***********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 2, "x");
                            }
                            else if (luachon == 3) {
                                cout << "\t\t\t**************************PHONG BAN 3***********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 3, "x");
                            }
                            else if (luachon == 4) {
                                cout << "\t\t\t**************************PHONG BAN 4***********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 4, "x");
                            }
                            else if (luachon == 5) {
                                cout << "\t\t\t**************************PHONG BAN 5**********************************=\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 5, "x");
                            }
                            else if (luachon == 0)
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                            }
                            system("pause");

                        }
                        else if (field == 4) {
                            printf(" ******************MENU TANG GIAM - ID*******************\n");
                            printf(" |1. Sap xep tang dan                                   |\n");
                            printf(" |2. Sap xep giam dan                                   |\n");
                            printf(" |0. Thoat                                              |\n");
                            printf(" ********************************************************\n");
                            cout << "\n Vui long nhap lua chon: ";
                            cin >> luachon;
                            if (luachon == 1) {
                                cout << "\t\t\t***********************Increase List By ID**********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                Increase(ListStaf, k, 1);
                                PrintEMList(ListStaf, k, 6, "x");
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t************************Decrease List By ID*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                Decrease(ListStaf, k, 1);
                                PrintEMList(ListStaf, k, 6, "x");
                            }
                            else if (luachon == 0)        // thoat khoi sap xep theo ID
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                            }
                            system("pause");

                        }
                        else if (field == 5) {
                            printf(" *********************MENU TANG GIAM - SALARY****************\n");
                            printf(" |1. Sap xep tang dan                                       |\n");
                            printf(" |2. Sap xep giam dan                                       |\n");
                            printf(" |0. Thoat                                                  |\n");
                            printf(" ************************************************************\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> luachon;

                            if (luachon == 1) {
                                cout << "\t\t\t************************Increase List By Salary*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                Increase(ListStaf, k, 2);
                                PrintEMList(ListStaf, k, 6, "x");
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t************************Decrease List By Salary*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                Decrease(ListStaf, k, 2);
                                PrintEMList(ListStaf, k, 6, "x");
                            }

                            else if (luachon == 0)    // thoat khoi sap xep theo Salary
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                                break;
                            }
                            system("pause");

                        }
                        else if (field == 6) {
                            printf(" ********************=MENU TANG GIAM - WORKING TIME****************\n");
                            printf(" |1. Sap xep tang dan                                             |\n");
                            printf(" |2. Sap xep giam dan                                             |\n");
                            printf(" |0. Thoat                                                        |\n");
                            printf(" ******************************************************************\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> luachon;

                            if (luachon == 1) {
                                cout << "\t\t\t************************Increase List By Working Time*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                Increase(ListStaf, k, 3);
                                PrintEMList(ListStaf, k, 6, "x");
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t*************************Decrease List By Working Time********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                Decrease(ListStaf, k, 3);
                                PrintEMList(ListStaf, k, 6, "x");
                            }

                            else if (luachon == 0)    // thoat khoi sap xep theo Salary
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                                break;
                            }
                            system("pause");

                        }
                        else if (field == 7) {
                            printf(" ****************************CHUC VU*******************************\n");
                            printf(" |1. Manager                                                      |\n");
                            printf(" |2. Programmer                                                   |\n");
                            printf(" |3. Tester                                                       |\n");
                            printf(" |4. Designer                                                     |\n");
                            printf(" |0. Thoat                                                        |\n");
                            printf("*******************************************************************\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> luachon;
                            if (luachon == 1) {
                                cout << "\t\t\t**************************MANAGER*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 7, "manager");
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t***********************PROGRAMMER*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 7, "programmer");
                            }
                            else if (luachon == 3) {
                                cout << "\t\t\t***************************TESTER*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 7, "tester");
                            }
                            else if (luachon == 4) {
                                cout << "\t\t\t*************************DESIGNER*********************************\n";
                                HashTb.hash_to_list(ListStaf, k);
                                PrintEMList(ListStaf, k, 7, "designer");
                            }
                            else if (luachon == 0)
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                            }
                            system("pause");
                        }
                        else {
                            cout << "\n Xin vui long nhap lai!" << endl;
                            break;
                        }

                    }
                }

            }
            system("pause");
            break;
        case 5:
            cout << "Nhap ID ban muon xoa: "; cin >> id;
            HashTb.removeStaf(id);
            system("pause");
            break;
        case 6:
            term.inputStaff();
            HashTb.insertStaf(term);
            system("pause");
            break;
        case 7:
            int empID;
            cout << "Enter the Employee's ID you want to modify : ";
            cin >> empID;
            HashTb.modiStaf(empID);
            system("pause");
            break;
        case 8:
            luachon = 4;
            Choose = 3;
            int a[5];
            while (true)
            {
                system("cls");
                cout << "\n Sap xep tien luong nhan vien TANG/GIAM theo DEPARTMENT" << endl;
                printf(" **********************MENU-DEPARTMENT SALARY**********************\n");
                printf(" |1. Luong theo ngay                                              |\n");
                printf(" |2. Luong theo thang                                             |\n");
                printf(" |3. Luong theo nam                                               |\n");
                printf(" |0. Thoat                                                        |\n");
                printf("*******************************************************************\n");
                cout << "\n Xin vui long nhap lua chon: ";
                cin >> luachon;

                if (luachon == 0) {     // thoat khoi vong lap nhap field: khong can nhap id hoac salary de sap xep
                    break;
                }
                else {
                    while (true)
                    {
                        system("cls");
                        if (luachon == 1) {
                            printf("*******************MENU TANG GIAM-DEPARTMENT SALARY****************\n");
                            printf(" |1. Sap xep tang dan                                             |\n");
                            printf(" |2. Sap xem giam dan                                             |\n");
                            printf(" |0. Thoat                                                        |\n");
                            printf(" ******************************************************************\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> Choose;
                            if (Choose == 1) {
                                QueueStaf.SetQueue();
                                HashTb.hash_to_list(ListStaf, k);
                                AddSalaryToQueue(QueueStaf, ListStaf, k, 1);
                                QNode* temp = QueueStaf.queueFront();
                                for (int i = 0; i < 5; i++) {
                                    a[i] = temp->data;
                                    temp = temp->next;
                                }
                                QueueStaf.Bubble_Sort(1);
                                QueueStaf.displayQueue(a);
                            }
                            else if (Choose == 2) {
                                QueueStaf.SetQueue();
                                HashTb.hash_to_list(ListStaf, k);
                                AddSalaryToQueue(QueueStaf, ListStaf, k, 1);
                                QNode* temp = QueueStaf.queueFront();
                                for (int i = 0; i < 5; i++) {
                                    a[i] = temp->data;
                                    temp = temp->next;
                                }
                                QueueStaf.Bubble_Sort(2);
                                QueueStaf.displayQueue(a);
                            }
                            else if (Choose == 0)
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                            }
                            system("pause");
                        }
                        if (luachon == 2) {
                            printf(" ==================MENU TANG GIAM-DEPARTMENT SALARY================\n");
                            printf(" |1. Sap xep tang dan                                             |\n");
                            printf(" |2. Sap xem giam dan                                             |\n");
                            printf(" |0. Thoat                                                        |\n");
                            printf(" ******************************************************************\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> Choose;
                            if (Choose == 1) {
                                QueueStaf.SetQueue();
                                HashTb.hash_to_list(ListStaf, k);
                                AddSalaryToQueue(QueueStaf, ListStaf, k, 30);
                                QNode* temp = QueueStaf.queueFront();
                                for (int i = 0; i < 5; i++) {
                                    a[i] = temp->data;
                                    temp = temp->next;
                                }
                                QueueStaf.Bubble_Sort(1);
                                QueueStaf.displayQueue(a);
                            }
                            else if (Choose == 2) {
                                QueueStaf.SetQueue();
                                HashTb.hash_to_list(ListStaf, k);
                                AddSalaryToQueue(QueueStaf, ListStaf, k, 30);
                                QNode* temp = QueueStaf.queueFront();
                                for (int i = 0; i < 5; i++) {
                                    a[i] = temp->data;
                                    temp = temp->next;
                                }
                                QueueStaf.Bubble_Sort(2);
                                QueueStaf.displayQueue(a);
                            }
                            else if (Choose == 0)
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                            }
                            system("pause");
                        }
                        if (luachon == 3) {
                            printf(" ==================MENU TANG GIAM-DEPARTMENT SALARY================\n");
                            printf(" |1. Sap xep tang dan                                             |\n");
                            printf(" |2. Sap xem giam dan                                             |\n");
                            printf(" |0. Thoat                                                        |\n");
                            printf(" ******************************************************************\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> Choose;
                            if (Choose == 1) {
                                QueueStaf.SetQueue();
                                HashTb.hash_to_list(ListStaf, k);
                                AddSalaryToQueue(QueueStaf, ListStaf, k, 365);
                                QNode* temp = QueueStaf.queueFront();
                                for (int i = 0; i < 5; i++) {
                                    a[i] = temp->data;
                                    temp = temp->next;
                                }
                                QueueStaf.Bubble_Sort(1);
                                QueueStaf.displayQueue(a);
                            }
                            else if (Choose == 2) {
                                QueueStaf.SetQueue();
                                HashTb.hash_to_list(ListStaf, k);
                                AddSalaryToQueue(QueueStaf, ListStaf, k, 365);
                                QNode* temp = QueueStaf.queueFront();
                                for (int i = 0; i < 5; i++) {
                                    a[i] = temp->data;
                                    temp = temp->next;
                                }
                                QueueStaf.Bubble_Sort(2);
                                QueueStaf.displayQueue(a);
                            }
                            else if (Choose == 0)
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                            }
                            system("pause");

                        }
                    }
                }
            }
            system("pause");
            break;
        case 9:
            luachon = 3;
            while (luachon != 0) {
                system("cls");
                printf(" ****************************STAFF SALARY**************************\n");
                printf(" |1. Danh sach luong theo thang                                   |\n");
                printf(" |2. Danh sach luong theo nam                                     |\n");
                printf(" |0. Thoat                                                        |\n");
                printf(" ******************************************************************\n");

                cout << "\n Vui long nhap lua chon: ";
                cin >> luachon;
                if (luachon == 1) {
                    HashTb.hash_to_list(ListStaf, k);
                    PrintEMListSalary(ListStaf, k, 30);
                }
                else if (luachon == 2) {
                    HashTb.hash_to_list(ListStaf, k);
                    PrintEMListSalary(ListStaf, k, 365);
                }
                else if (luachon == 0) {
                    break;
                }
                else {
                    cout << "\n Xin vui long nhap lai!" << endl;
                }
                system("pause");
            }
        case 0:
            break;
        default:
            printf("Ban chon sai. Moi ban chon lai MENU!\n");
            system("pause");
            break;
        }
    } while (chon != 0);
    return 0;

}

