#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void decToBinary(int n)
{
    
    int counter{ 0 };
    
    // array to store binary number 
    int binaryNum[64];

    // counter for binary array 
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array 
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--)
        if (binaryNum[j] == 1)
            ++counter;

    cout << counter << endl;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x; cin.ignore();
        decToBinary(x);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    
}