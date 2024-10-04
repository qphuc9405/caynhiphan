#include <iostream>

using namespace std;

int main() {
    int arr[] = { 3, 2, 4, 1, 9};
    short* p = (short*)&arr[0];
    cout << *(p + 6);
    return 0;
}