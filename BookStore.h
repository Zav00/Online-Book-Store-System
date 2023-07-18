#ifndef ONLINE_BOOK_STORE_SYSTEM_BOOKSTORE_H
#define ONLINE_BOOK_STORE_SYSTEM_BOOKSTORE_H
#include "Book.h"
#include "Customer.h"
#include <string>
#include <vector>

class BookStore {
private:
    std::vector<Book> books;
    std::vector<Customer> customers;
    std::vector<Book> shoppingCart;
public:
    void registerBook(const std::string &title, const std::string &author, const std::string &genre, double price,
                      int quantity) {
        Book book(title, author, genre, price, quantity);
        books.push_back(book);
        std::cout << "Book registered: " << std::endl;
    }

    void registerCustomer(const std::string &name, const std::string &contactInfo) {
        Customer customer(name, contactInfo);
        customers.push_back(customer);
        std::cout << "Customer registered successfully. " << std::endl;
    }

    void addToCart(const std::string &title) {
        Book * book = findBookByTitle(title);
        if (book != nullptr) {
            shoppingCart.push_back(*book);
            std::cout << "Book added to the Cart " << std::endl;
        } else { std::cout << "Book not found " << std::endl; }
    }

    void removeFromCart(const std::string &title) {
        for (auto it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
            if (it->getTitle() == title) {
                shoppingCart.erase(it);
                std::cout << "Bool removed from the cart. " << std::endl;
                return;
            }
        }
        std::cout << "Book not found in the cart " << std::endl;
    }

    double calculateTheCost() {
        double totalCost = 0;
        for (const Book &book: shoppingCart) {
            totalCost += book.getPrice();
        }
        return totalCost;
    }

    void processPurchase() {
        for (const Book &book: shoppingCart) {
            Book * bookInStock = findBookByTitle(book.getTitle());
            if (bookInStock != nullptr && bookInStock->getQuantity() > 0) {
                bookInStock->setQuantity(bookInStock->getQuantity() - 1);
            }
        }
        shoppingCart.clear();
        std::cout << "Purchase processed successfilly. " << std::endl;
    }

    void generatePurchaseHistoryReport() {
        std::ofstream file("purchase_history.txt");
        if (file.is_open()) {
            file << "Purchase History Report " << std::endl;
            file << "--------------------------------" << std::endl;
            for (const Book &book: shoppingCart) {
                file << "Title: " << book.getTitle() << std::endl;
                file << "Author: " << book.getAuthor() << std::endl;
                file << "Price: " << book.getPrice() << std::endl;
                file << "----------------------------";
            }
            file << "Total cost: " << calculateTheCost() << std::endl;
            file.close();
            std::cout << "Purchase history report generated successfully," << std::endl;
        } else {
            std::cout << "Failed to generate purchase history " << std::endl;
        }
    }

    void printBooksInStock() {
        std::cout << "Books in Stock: " << std::endl;
        std::cout << "----------------------" << std::endl;
        for (const Book &book: books) {
            std::cout << "Title: " << book.getTitle() << std::endl;
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Genre: " << book.getGenre() << std::endl;
            std::cout << "Price: $" << book.getPrice() << std::endl;
            std::cout << "Quantity in Stock: " << book.getQuantity() << std::endl;
            std::cout << "-------------------" << std::endl;
        }
    }

    void printCustomers() const {
        std::cout << "Registered Customers: " << std::endl;
        std::cout << "---------------------" << std::endl;
        for (const Customer &customer: customers) {
            std::cout << "Name: " << customer.getName() << std::endl;
            std::cout << "Contact Info: " << customer.getContactInfo() << std::endl;
            std::cout << "---------------------" << std::endl;
        }
    }

private:
    Book *findBookByTitle(const std::string &title) {
        for (Book &book: books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }
};
#endif //ONLINE_BOOK_STORE_SYSTEM_BOOKSTORE_H
