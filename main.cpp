#include <iostream>
#include "Contact.h"
int main() {

    // Creating contacts
    Contact contact1("John", "Doe", "1234567890", "9876543210", "john@example.com", "123 Main St", "ABC Inc.", ContactGroup::Friends);
    Contact contact2("Alice", "Smith", "5551234567", "", "alice@example.com", "456 Elm St", "XYZ Corp.", ContactGroup::Family);
    Contact contact3("Bob", "Johnson", "9998887777", "", "bob@example.com", "789 Oak St", "DEF Ltd.", ContactGroup::Coworker);
    cout << "Enter the way you want to sort the contacts \n1 for ascending order\n2 for descending order" << endl;
    string input;
    getline(cin ,input);
    int operation = stoi(input);
    if(operation == 1){
        set<Contact, firstNameSort> firstNameOrderedSet{contact1 , contact2 , contact3};
        cout << "Sorted contacts based on first name " << endl;
        for(const auto& it : firstNameOrderedSet){
            cout << it << endl;
        }
    } else if(operation == 2){
        set<Contact, lastNameSort> lastNameOrderedSet{contact1 , contact2 , contact3};
        cout << "Sorted contacts based on last name " << endl;
        for(const auto& it : lastNameOrderedSet){
            cout << it << endl;
        }
    }else{
        cout << "You have entered a wrong number" << endl;
    }


    return 0;
}
