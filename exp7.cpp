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
  cout << "Enter publisher: ";
    getline(cin, book.publisher);

    cout << "Enter year of publishing: ";
    cin >> book.year_of_publishing;
}

void outputBookDetails(const Book& book) {
    cout << book.book_id << ","
              << book.author_name << ","
              << book.price << ","
              << book.no_of_pages << ","
              << book.publisher << ","
              << book.year_of_publishing << std::endl;
}

// to sort books by author name
void sortBooksByAuthor(Book books[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (books[j].author_name > books[j + 1].author_name) {
                // Swap the books
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

