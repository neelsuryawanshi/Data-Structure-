// Smart Hospital Patient Record Management System
// A hospital requires a system to efficiently manage patient records. 
// The system should allow hospital staff to register new patients, update patient information, discharge patients, 
// and display all patient records. Since the number of patients changes frequently, the records should be maintained 
// using a Linked List to support dynamic insertion and deletion. Each patient should be assigned a unique Patient ID, 
// enabling quick retrieval of patient information using a Hash Table. If multiple Patient IDs map to the same hash 
// location, the system should implement suitable collision resolution techniques such as Chaining or Open Addressing 
// to ensure efficient data retrieval.

#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
    Patient* next;     
    Patient* hashNext; 
};

Patient* head = NULL;
const int SIZE = 10;
Patient* hashTable[SIZE] = {NULL};

int hashFunction(int id)
{
    return id % SIZE;
}

void registerPatient()
{
    Patient* p = new Patient;
    cout << "Enter Patient ID:";
    cin >> p->id;

    int index = hashFunction(p->id);
    Patient* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == p->id)
        {
            cout << "Patient ID already exists!\n";
            delete p;
            return;
        }
        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Patient Name: ";
    getline(cin, p->name);

    cout << "Enter Age: ";
    cin >> p->age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Disease: ";
    getline(cin, p->disease);

    p->next = head;
    head = p;

    p->hashNext = hashTable[index];
    hashTable[index] = p;

    cout << "Patient registered successfully!\n";
}

void searchPatient()
{
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;

    int index = hashFunction(id);
    Patient* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nPatient Found!\n";
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Disease: " << temp->disease << endl;
            return;
        }
        temp = temp->hashNext;
    }
    cout << "Patient not found!\n";
}

void displayPatients()
{
    Patient* temp = head;

    if (temp == NULL)
    {
        cout << "No patient records available.\n";
        return;
    }

    cout << "\n--- All Patient Records ---\n";
    while (temp != NULL)
    {
        cout << "\nPatient ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Disease: " << temp->disease << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Register Patient\n";
        cout << "2. Search Patient\n";
        cout << "3. Display All Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerPatient();
                break;
            case 2:
                searchPatient();
                break;
            case 3:
                displayPatients();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:

                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}
