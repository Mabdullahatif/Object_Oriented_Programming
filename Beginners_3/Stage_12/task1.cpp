/*
This C++ program demonstrates the use of a template class to create a fixed-size sequence container.

The 'Sequence' class is defined as a template class, which means it can work with different data types.
The class takes two template parameters: 'T' (the data type) and 'N' (the size of the sequence).
The class has a private member array 'memblock' of type 'T' and size 'N'.

The class provides two member functions: 'setmember' and 'getmember'.
- 'setmember' takes an index 'x' and a value of type 'T', and it sets the value at the given index in the 'memblock' array.
- 'getmember' takes an index 'x' and returns the value at that index in the 'memblock' array.

In the 'main' function, two instances of the 'Sequence' class are created: 'myints' with the data type 'int' and size 5,
and 'myfloats' with the data type 'double' and size 5.

We use the 'setmember' function to set the value 100 at index 0 in 'myints' and the value 3.1416 at index 3 in 'myfloats'.

Then, we use the 'getmember' function to retrieve the values set earlier and print them using 'cout'.

Sample output:
------------------
100
3.1416
------------------
Here, we see the values 100 and 3.1416 printed, which were set in 'myints' and 'myfloats', respectively.
*/

#include <iostream>
using namespace std;

template <class T, int N>
class Sequence {
private:
    T memblock[N];

public:
    void setmember(int x, T value) {
        memblock[x] = value;
    }

    T getmember(int x) {
        return memblock[x];
    }
};

int main() {
    Sequence<int, 5> myints;
    Sequence<double, 5> myfloats;

    myints.setmember(0, 100);
    myfloats.setmember(3, 3.1416);

    cout << myints.getmember(0) << '\n';
    cout << myfloats.getmember(3) << '\n';

    return 0;
}
