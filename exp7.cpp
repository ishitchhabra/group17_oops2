#include <iostream>
#include <string>
using namespace std;

struct Book {
    int book_id;
    string author_name;
    double price;
    int no_of_pages;
    string publisher;
    int year_of_publishing;
};

// Function to input book details
void inputBookDetails(Book& book) {
    cout << "Enter book ID: ";
    cin >> book.book_id;
    cin.ignore(); // To ignore the new line after the integer input

    cout << "Enter author name: ";
    getline(cin, book.author_name);

    cout << "Enter price: ";
    cin >> book.price;

    cout << "Enter number of pages: ";
    cin >> book.no_of_pages;
    cin.ignore(); 
