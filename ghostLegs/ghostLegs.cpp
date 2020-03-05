#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vector_type = vector<string>;

int getData(vector_type& table)
{
    int width;
    int height;    

    cin >> width >> height;
    cin.ignore();

    for (int i = 0; i < height; i++) {

        string line;
        getline(cin, line);
        table.push_back(line);

    }    

    return width;
}

char getChar(int line, int row, vector_type& table)
{
    return table[line][row];
}

void solve(int row, int width, int height, vector_type& table)
{
    
    char start{};
    char end{};
    
    for (int line = 0; line < height - 1; ++line)
    {
        if (line == 0)
            start = getChar(line, row, table);
        else
        {
            if (row == 0)
            {
                if (getChar(line, row + 1, table) == '-')
                    row += 3;
                
            }
            else if (row == width - 1)
            {
                if (getChar(line, row - 1, table) == '-')
                    row -= 3;
            }
            else
            {
                if (getChar(line, row + 1, table) == '-')
                    row += 3;
                else if (getChar(line, row - 1, table) == '-')
                    row -= 3;
            }
        }
    }

    end = getChar(height - 1, row, table);    

    cout << start << end << '\n';    
}

int main()
{
    vector_type table;
    int width{ getData(table) };
    int height{ int(table.size()) };   

    for (int row = 0; row < width; row += 3)    
        solve(row, width, height, table);

    return 0;
     
}