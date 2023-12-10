#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;
enum class ContactGroup{
    Friends, Family , Coworker , Acquaintance
};
class Contact{
private:
    string first_name;
    string last_name;
    string phone_number;
    string sec_phone_number;
    string email;
    string address;
    string company;
    ContactGroup group;
public:

    Contact(string firstName, string lastName, string phoneNumber, string secPhoneNumber,
            string email, string address, string company, ContactGroup group) : first_name(std::move(
            firstName)), last_name(std::move(lastName)), phone_number(std::move(phoneNumber)), sec_phone_number(std::move(secPhoneNumber)), email(std::move(email)),
                                                                                                     address(std::move(address)),
                                                                                                     company(std::move(company)),
                                                                                                     group(group) {}

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "first_name: " << contact.first_name << " last_name: " << contact.last_name << " phone_number: "
           << contact.phone_number << " sec_phone_number: " << contact.sec_phone_number << " email: " << contact.email
           << " address: " << contact.address << " company: " << contact.company << " group: " << getContactGroupString(contact.group);
        return os;
    }

    const string &getFirstName() const {
        return first_name;
    }
    void setFirstName(const string &firstName) {
        first_name = firstName;
    }
    const string &getLastName() const {
        return last_name;
    }
    void setLastName(const string &lastName) {
        last_name = lastName;
    }
    const string &getPhoneNumber() const {
        return phone_number;
    }
    void setPhoneNumber(const string &phoneNumber) {
        phone_number = phoneNumber;
    }
    const string &getSecPhoneNumber() const {
        return sec_phone_number;
    }
    void setSecPhoneNumber(const string &secPhoneNumber) {
        sec_phone_number = secPhoneNumber;
    }
    const string &getEmail() const {
        return email;
    }
    void setEmail(const string &email) {
        Contact::email = email;
    }
    const string &getAddress() const {
        return address;
    }
    void setAddress(const string &address) {
        Contact::address = address;
    }
    const string &getCompany() const {
        return company;
    }
    void setCompany(const string &company) {
        Contact::company = company;
    }
    ContactGroup getGroup() const {
        return group;
    }
    void setGroup(ContactGroup group) {
        Contact::group = group;
    }
    static std::string getContactGroupString(ContactGroup group) {
        switch (group) {
            case ContactGroup::Friends:
                return "Friends";
            case ContactGroup::Family:
                return "Family";
            case ContactGroup::Coworker:
                return "Coworker";
            case ContactGroup::Acquaintance:
                return "Acquaintance";
            default:
                return "Unknown";
        }
    }
};

struct firstNameSort{
    bool operator()(const Contact & a ,const Contact & b)const{
        return a.getFirstName() < b.getFirstName();
    }
};
struct lastNameSort{
    bool operator()(const Contact & a ,const Contact & b)const{
        return a.getLastName() < b.getLastName();
    }
};
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
