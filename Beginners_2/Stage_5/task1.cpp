/*
  This C++ program defines a 'Set' class that represents a set of integers and provides various set operations.

  - The 'Set' class has private data members 'data', 'noOfElements', and 'capacity' to store the set elements,
    the number of elements in the set, and the capacity of the set, respectively.

  - The class has constructors to create a set object and initialize its properties.
    The destructor is provided to free the dynamically allocated memory for the set.

  - The 'insert' function inserts a new element into the set.

  - The 'remove' function removes an element from the set.

  - The 'getCardinality' function returns the number of elements in the set.

  - The 'calcUnion', 'calcSymmetricDifference', and 'calcDifference' functions perform set operations
    Union, Symmetric Difference, and Difference, respectively, and return a new set object with the result.

  - The 'isMember' function checks if an element is present in the set.

  - The 'isSubSet' function checks if the current set is a proper or improper subset of another set.

  - The 'reSize' function resizes the set to the specified new capacity.

  - The 'update' function updates the value of an element in the set with a new value.

  - The 'show' function displays the elements of the set.

  Note: The program demonstrates the implementation of a set using dynamic memory allocation.
  It showcases various set operations and how elements can be inserted, removed, and updated in the set.
*/
#include <iostream>
using namespace std;

class Set {
private:
    int* data;
    int noOfElements;
    int capacity;

public:
    Set(int cap = 0);
    Set(const Set& ref);
    ~Set();
    void insert(int element);
    void remove(int element);
    int getCardinality() const;
    Set calcUnion(const Set& s2) const;
    Set calcSymmetricDifference(const Set& s2) const;
    Set calcDifference(const Set& s2) const;
    int isMember(int val) const;
    int isSubSet(const Set& s2) const;
    void reSize(int newcapacity);
    void update(int prVal, int curVal);
    void show() const;
};

Set::Set(int cap) {
    // Ensure capacity is not negative
    if (cap < 0) {
        cap = 0;
    }

    this->data = new int[cap];
    this->capacity = cap;
    this->noOfElements = 0;
}

Set::Set(const Set& ref) {
    noOfElements = ref.noOfElements;
    data = new int[ref.capacity];
    for (int i = 0; i < noOfElements; i++) {
        data[i] = ref.data[i];
    }
}

Set::~Set() {
    delete[] data;
}

void Set::insert(int element) {
    int* ptr = new int[this->noOfElements + 1];
    for (int i = 0; i < noOfElements; i++) {
        ptr[i] = data[i];
    }
    ptr[noOfElements] = element;
    delete[] data;
    data = ptr;
    noOfElements++;
}

void Set::remove(int element) {
    int* ptr = new int[this->noOfElements - 1];
    int j = 0;
    for (int i = 0; i < noOfElements; i++) {
        if (data[i] != element) {
            ptr[j] = data[i];
            j++;
        }
    }
    delete[] data;
    data = ptr;
    noOfElements--;

    // Check if the Set needs to be resized
    if (noOfElements <= capacity / 2) {
        reSize(capacity - capacity / 4);
    }
}

int Set::getCardinality() const {
    return noOfElements;
}

Set Set::calcUnion(const Set& s2) const {
    Set result(this->capacity + s2.capacity);
    for (int i = 0; i < this->noOfElements; i++) {
        result.insert(this->data[i]);
    }
    for (int i = 0; i < s2.noOfElements; i++) {
        if (!this->isMember(s2.data[i])) {
            result.insert(s2.data[i]);
        }
    }
    return result;
}

Set Set::calcSymmetricDifference(const Set& s2) const {
    Set result(this->capacity + s2.capacity);
    for (int i = 0; i < this->noOfElements; i++) {
        if (!s2.isMember(this->data[i])) {
            result.insert(this->data[i]);
        }
    }
    for (int i = 0; i < s2.noOfElements; i++) {
        if (!this->isMember(s2.data[i])) {
            result.insert(s2.data[i]);
        }
    }
    return result;
}

Set Set::calcDifference(const Set& s2) const {
    Set result(this->capacity);
    for (int i = 0; i < this->noOfElements; i++) {
        if (s2.isMember(this->data[i])) {
            result.insert(this->data[i]);
        }
    }
    return result;
}

int Set::isMember(int val) const {
    for (int i = 0; i < this->noOfElements; i++) {
        if (this->data[i] == val) {
            return 1;
        }
    }
    return 0;
}

int Set::isSubSet(const Set& s2) const {
    int count = 0;
    for (int i = 0; i < s2.noOfElements; i++) {
        if (this->isMember(s2.data[i])) {
            count++;
        }
    }
    if (count == this->noOfElements && count < s2.noOfElements) {
        return 1; // Proper Subset
    } else if (count == this->noOfElements && count == s2.noOfElements) {
        return 2; // Improper Subset
    } else {
        return 0; // Not a Subset
    }
}

void Set::reSize(int newcapacity) {
    if (newcapacity < 0) {
        newcapacity = 0;
    }

    if (newcapacity >= this->noOfElements) {
        int* newdata = new int[newcapacity];
        for (int i = 0; i < this->noOfElements; i++) {
            newdata[i] = data[i];
        }

        delete[] data;
        data = newdata;
        capacity = newcapacity;
    }
}

void Set::update(int prVal, int curVal) {
    if (!isMember(prVal)) {
        cout << "Target value not found." << endl;
        return;
    }

    if (isMember(curVal)) {
        cout << "Violation set property. Can't Modify the data." << endl;
        return;
    }

    for (int i = 0; i < noOfElements; i++) {
        if (data[i] == prVal) {
            data[i] = curVal;
        }
    }
    cout << "Record update successfully." << endl;
}

void Set::show() const {
    for (int i = 0; i < noOfElements; i++) {
        cout << data[i] << " ";
    }
}

int main() {
    Set s(10);

    s.insert(5);
    s.insert(10);
    s.insert(15);

    Set s2 = s;
    s2.insert(20);

    Set s3 = s.calcUnion(s2);
    Set s4 = s.calcSymmetricDifference(s2);
    Set s5 = s.calcDifference(s2);

    s.show(); // Output: 5 10 15
    cout << endl;

    s2.show(); // Output: 5 10 15 20
    cout << endl;

    s3.show(); // Output: 5 10 15 20
    cout << endl;

    s4.show(); // Output: 20
    cout << endl;

    s5.show(); // Output: 5 10 15
    cout << endl;

    s.update(5, 25); // Record update successfully.

    s.show(); // Output: 25 10 15
    cout << endl;

    return 0;
}
