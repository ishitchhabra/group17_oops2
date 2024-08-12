#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T elements[100];
    int size;

public:
    Vector() : size(0) {}

    void addElement(T element) {
        if (size < 100) {
            elements[size++] = element;
        }
    }

    T smallestElement() {
        if (size == 0) {
            cout << "Vector is empty." << endl;
            return T();
        }

        T smallest = elements[0];
        for (int i = 1; i < size; i++) {
            if (elements[i] < smallest) {
                smallest = elements[i];
            }
        }
        return smallest;
    }
 }

    int searchElement(T element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return i;
            }
        }
        return -1; // Element not found
    }

    T averageElement() {
        if (size == 0) {
            cout << "Vector is empty." << endl;
            return T();
        }

        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += elements[i];
        }
        return sum / size;
    }

    int searchElement(T element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return i;
            }
        }
        return -1; // Element not found
    }

    T averageElement() {
        if (size == 0) {
            cout << "Vector is empty." << endl;
            return T();
        }

        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += elements[i];
        }
        return sum / size;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};
