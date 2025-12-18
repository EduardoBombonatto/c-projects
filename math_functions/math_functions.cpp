#include <iostream>

using namespace std;

int add(int a = 5, int b = 5, int c = 5) {
    return a + b + c;
}

float add(float a = 4.0, float b = 3.5) {
    return a + b;
}

int main()
{
    cout << "Double Addition (2 params): " << add(4.0f) << endl;
    cout << "Integer Addition (3 params): " << add(5) << endl;
    return 0;
}