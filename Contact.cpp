#include "Contact.h"

    Contact::Contact(string firstName, string lastName, string phoneNumber, string secPhoneNumber,
            string email, string address, string company, ContactGroup group) : first_name(std::move(
            firstName)), last_name(std::move(lastName)), phone_number(std::move(phoneNumber)), sec_phone_number(std::move(secPhoneNumber)), email(std::move(email)),
                                                                                address(std::move(address)),
                                                                                company(std::move(company)),
                                                                                group(group) {}

    ostream &operator<<(ostream &os, const Contact &contact) {
        os << "first_name: " << contact.first_name << " last_name: " << contact.last_name << " phone_number: "
           << contact.phone_number << " sec_phone_number: " << contact.sec_phone_number << " email: " << contact.email
           << " address: " << contact.address << " company: " << contact.company << " group: " << Contact::getContactGroupString(contact.group);
        return os;
    }

    const string &Contact::getFirstName() const {
        return first_name;
    }
    void Contact::setFirstName(const string &firstName) {
        first_name = firstName;
    }
    const string &Contact::getLastName() const {
        return last_name;
    }
    void Contact::setLastName(const string &lastName) {
        last_name = lastName;
    }
    const string &Contact::getPhoneNumber() const {
        return phone_number;
    }
    void Contact::setPhoneNumber(const string &phoneNumber) {
        phone_number = phoneNumber;
    }
    const string &Contact::getSecPhoneNumber() const {
        return sec_phone_number;
    }
    void Contact::setSecPhoneNumber(const string &secPhoneNumber) {
        sec_phone_number = secPhoneNumber;
    }
    const string &Contact::getEmail() const {
        return email;
    }
    void Contact::setEmail(const string &email) {
        Contact::email = email;
    }
    const string &Contact::getAddress() const {
        return address;
    }
    void Contact::setAddress(const string &address) {
        Contact::address = address;
    }
    const string &Contact::getCompany() const {
        return company;
    }
    void Contact::setCompany(const string &company) {
        Contact::company = company;
    }
    ContactGroup Contact::getGroup() const {
        return group;
    }
    void Contact::setGroup(ContactGroup group) {
        Contact::group = group;
    }
    string Contact::getContactGroupString(ContactGroup group) {
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

bool firstNameSort::operator()(const Contact & a ,const Contact & b)const{
    return a.getFirstName() < b.getFirstName();
}
bool lastNameSort::operator()(const Contact & a ,const Contact & b)const{
    return a.getLastName() < b.getLastName();
}



