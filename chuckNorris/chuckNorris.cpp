#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using vector_int = vector<int>;

string decToBinary(int n)
{

    int counter{ 0 };

    // array to store binary number 
    int binaryNum[32];

    // counter for binary array 
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array 
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    string binaries;

    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--)
        binaries += '0' + binaryNum[j];

    return binaries;


}

string getBinaries(string& message)
{
    
    string binaries{};
    
    for (string::size_type i = 0; i < message.size(); ++i)    
        binaries += decToBinary((int)message[i]);    
       
    return binaries;
}

int countDigits(string& binaries, int index)
{
    int count{ 1 };
    while (binaries[index] == binaries[index + 1])
    {
        ++index;
        ++count;
    }

    return count;
}

void addBits(string& encodedBin, int index, int digitsNumber, char bit)
{
    for (int i = index; i <= digitsNumber; ++i)
    {
        encodedBin[i] = bit;
    }
}

string encode(string& binaries)
{
    int index{ 0 };
    string encodedBin{};


    for (std::string::size_type i = 0; i < binaries.size(); i++)
    {
        if (binaries[i]) // 1
        {
            int digitsNumber{ countDigits(binaries, index) };
            encodedBin[index] = '0';
            encodedBin[index + 1] = ' ';
            addBits(encodedBin, index + 2, digitsNumber, '1');
            index += 2 + digitsNumber;
            cerr << index;
        }
        else // 0
        {
            int digitsNumber{ countDigits(binaries, index) };
            encodedBin[index] = '0';
            encodedBin[index + 1] = '0';
            encodedBin[index + 2] = ' ';
            addBits(encodedBin, index + 2, digitsNumber, '0');
            index += 3 + digitsNumber;
            cerr << index;
        }
    }

    return encodedBin;
}




int main()
{
    string MESSAGE = "CC";
    //getline(cin, MESSAGE);

    string binaries{ getBinaries(MESSAGE) };
    string outPut{ encode(binaries) };

    cerr << outPut;



    
   
    return 0;
    
}