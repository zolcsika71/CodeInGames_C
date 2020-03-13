#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vector_string = vector<std::string>;

bool test{ true }; 
bool testInput{ true };

string decToBinary(int n)
{

    int counter{ 0 };
    
    int binaryNum[32];
    
    int i = 0; 
    while (n > 0) {
        
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    string binaries;   
    
    for (int j = i - 1; j >= 0; j--)
        binaries += to_string(binaryNum[j]);   
        

    return binaries;
}

string getBinaries(string& message)
{
    
    string binaries;
    
    for (string::size_type i = 0; i < message.size(); ++i)
    {
        string bin{ decToBinary((int)message[i]) };

        if (test)
        {
            //cerr << "binary: " << bin.length() << '\n';
            cerr << message[i] << " : " << (int)message[i] << '\n';
        }
            

        if (bin.length() < 7)
            binaries += '0';
        binaries += bin;
    }
        
       
    return binaries;
}

void sliceString(string& binaries, vector_string& slices)
{
    
    int count{ 1 };
    int index{ 0 };
    
    for (string::size_type i = 0; i < binaries.size() - 1; ++i)
    {      
        if (count == 1)
            index = i;
        
        if (binaries[i] == binaries[i + 1])
         {                 
            ++count;

            if(i == binaries.size() - 2)
                slices.push_back(binaries.substr(index, count));
            
        }
        else
        {     
            slices.push_back(binaries.substr(index, count));                           
            
            count = 1;        

            if (i == binaries.size() - 2)
                slices.push_back(binaries.substr(index + 1, count));
            
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
   
    if (testInput)    
        MESSAGE = "Chuck Norris' keyboard has 2 keys: 0 and white space.";
    else
        getline(cin, MESSAGE);

    string binaries{ getBinaries(MESSAGE) };

    if (test)
    {
        //cerr << binaries << '\n';
        //cerr << '\n';
    }
       

    vector_string slices;
    sliceString(binaries, slices);


    if (test)
    {
        //testArray(slices);
        //cerr << '\n';
    }
    

    string results{ pushElements(slices) };

    cout << results;
   
    return 0;
    
}