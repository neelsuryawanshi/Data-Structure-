// write a program menu driven for simple bank token system that allows the user to issue the token, display all tokens , serve customer and exit the program 
#include <iostream>
#include <string>
using namespace std;

int main() {

    int bank[10];
    int n = 0;
    int choice;
    int searchtoken;

    do{
        cout<<"\n=============Bank System=================";
        cout << "\n1. Issue Token.";
        cout << "\n2. Display all tokens.";
        cout << "\n3. Search by token number";
        cout << "\n4. Exit.";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if(choice == 1){
            cout<<"Enter Bank token number: ";
            cin>>bank[n];
            n++;
            cout<<"Token Added";
        }
        else if(choice ==2){
            cout<<"Tokens added in bank";

            for(int i = 0;i<n;i++){
                cout<<bank[i]<<endl;
            }
        }
        else if(choice == 3)
        {
            cout << "\nEnter token number to search: ";
            cin >> searchtoken;

            bool found = false;

            for(int i = 0; i < n; i++)
            {
                if(bank[i] == searchtoken)
                {
                    found = true;
                }
            }

            if(found)
            {
                cout << "token number Found.";
            }
            else
            {
                cout << "Token number not Found.";
            }
        }
        else if(choice == 4)
        {
            cout << "Thank you!";
        }
        else
        {
            cout << "Invalid Choice!";
        }
    }
    while(choice!=4);
    return 0;
}
