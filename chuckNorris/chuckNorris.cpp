#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vector_string = vector<std::string>;

bool test{ true }; 

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
        binaries += to_string(binaryNum[j]);

    return binaries;
}

string getBinaries(string& message)
{
    
    string binaries{};
    
    for (string::size_type i = 0; i <= message.size(); ++i)    
        binaries += decToBinary((int)message[i]);     
       
    return binaries;
}

void sliceString(string& binaries, vector_string& slices)
{
    
    int count{ 1 };
    int index{ 0 };
    
    for (string::size_type i = 0; i < binaries.size() - 1; ++i)
    {      
         if (binaries[i] == binaries[i + 1])
         {                    
            if (count == 1)
                index = i;
            
            ++count;

            if(i == binaries.size() - 2)
                slices.push_back(binaries.substr(index, count));
            
        }
        else
        {           
           slices.push_back(binaries.substr(index, count));                            
            
            count = 1;        

            if (i == binaries.size() - 2)
                slices.push_back(binaries.substr(index, count));
            
        }

    }
}

void testArray(vector_string& testArray)
{
    for (string element : testArray)
        cerr << element << '\n';
}

void pushNdigits(string& results, int n)
{
    for (int i = 0; i < n; ++i)
        results += '0';   
}

string pushElements(vector_string& slices)
{
    string results;

    for (string::size_type i = 0; i < slices.size(); ++i)
    {
        if (slices[i][0] == '1')        
            results += "0 ";      
        else        
            results += "00 ";

        pushNdigits(results, slices[i].size()); 

        if(i < slices.size() - 1)
            results += ' ';

    }

    return results;
}

int main()
{
    string MESSAGE;  
   
    if (test)    
        MESSAGE = '%';
    else
        getline(cin, MESSAGE);

    string binaries{ getBinaries(MESSAGE) };

    if (test)
    {
        cerr << binaries << '\n';
        cerr << '\n';
    }
       

    vector_string slices;
    sliceString(binaries, slices);


    if (test)
    {
        testArray(slices);
        cerr << '\n';
    }
    

    string results{ pushElements(slices) };

    cout << results;
   
    return 0;
    
}