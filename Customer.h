
#ifndef ONLINE_BOOK_STORE_SYSTEM_CUSTOMER_H
#define ONLINE_BOOK_STORE_SYSTEM_CUSTOMER_H
#include <string>
class Customer {
private:
    std::string name;
    std::string contactInfo;
public:
    Customer(const std::string &name, const std::string &contactInfo) : name(name), contactInfo(contactInfo) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }
};
#endif //ONLINE_BOOK_STORE_SYSTEM_CUSTOMER_H
