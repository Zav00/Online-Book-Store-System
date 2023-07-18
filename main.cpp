#include <iostream>
#include<fstream>
#include "BookStore.h"





int main() {
    BookStore bookstore;
    bookstore.registerBook("Book 1", "Author 1", "Genre 1", 10.99, 5);
    bookstore.registerBook("Book 2", "Author 2", "Genre 2", 15.99, 3);
    bookstore.registerCustomer("Customer 1", "Contact 1");
    bookstore.registerCustomer("Customer 2", "Contact 2");
    bookstore.addToCart("Book 1");
    bookstore.addToCart("Book 2");
    bookstore.removeFromCart("Book 1");
    double totalCost = bookstore.calculateTheCost();
    std::cout << "Total Cost: $" << totalCost << "\n";
    bookstore.processPurchase();
    bookstore.generatePurchaseHistoryReport();
    bookstore.printBooksInStock();
    bookstore.printCustomers();
}