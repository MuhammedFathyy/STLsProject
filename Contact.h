#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

class Contact;

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

    Contact() = default;
    ~Contact() = default;


    Contact(string firstName, string lastName, string phoneNumber, string secPhoneNumber,
            string email, string address, string company, ContactGroup group);
    friend ostream &operator<<(ostream &os, const Contact &contact);

    const string &getFirstName() const;
    void setFirstName(const string &firstName);
    const string &getLastName() const;
    void setLastName(const string &lastName);
    const string &getPhoneNumber() const;
    void setPhoneNumber(const string &phoneNumber);
    const string &getSecPhoneNumber() const;
    void setSecPhoneNumber(const string &secPhoneNumber);
    const string &getEmail() const;
    void setEmail(const string &email);
    const string &getAddress() const;
    void setAddress(const string &address);
    const string &getCompany() const;
    void setCompany(const string &company);
    ContactGroup getGroup() const;
    void setGroup(ContactGroup group);
    static std::string getContactGroupString(ContactGroup group);
};


struct firstNameSort{
    bool operator()(const Contact & a ,const Contact & b)const;
};
struct lastNameSort{
    bool operator()(const Contact & a ,const Contact & b)const;
};


