#include <iostream>
using namespace std;

// Template class to handle different data types
template <typename T>
class LargestFinder {
public:
    // Method to find the largest of three numbers
    T findLargest(T a, T b, T c) {
        T largest = a; // Assume a is the largest initially
        if (b > largest) {
            largest = b;
        }
        if (c > largest) {
            largest = c;
        }
        return largest;
    }
};
int main() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    LargestFinder<int> intFinder;
    cout << "Largest of " << a << ", " << b << ", " << c << " (int): " 
         << intFinder.findLargest(a, b, c) << endl;
