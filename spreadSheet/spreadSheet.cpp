#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Line
{
    string operation;
    string arg1;
    string arg2;
};

struct Result
{
    int result;
    bool counted;
};

using vector_line = vector<Line>;
using vector_result = vector<Result>;



int getData(vector_line& lines)
{
    int n{};
    
    
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {

        string operation;
        string arg1;
        string arg2;

        cin >> operation >> arg1 >> arg2;
        cin.ignore();          
            
        Line line{ operation, arg1, arg2 };
        lines.push_back(line);
        
    }

    return n;

}

void printResults(vector_result& results)
{
    for (Result result : results)
        cout << result.result << '\n';
}

void initResults(vector_result& results, int n)
{
    for (int i = 0; i < n; ++i)
    {
        Result result{ 0, false };
        results.push_back(result);
    }
}

int getArg(string arg, vector_result& results)
{
    
    if (arg == "_")
        return 0;
    else if (arg[0] == '$')
        return results[stoi(arg.substr(1))].result;
    else
        return stoi(arg);

}

int countResult(string operation, int arg1, int arg2)
{
    if (operation == "VALUE")
        return arg1;
    else if (operation == "ADD")
        return arg1 + arg2;
    else if (operation == "SUB")
        return arg1 - arg2;
    else if (operation == "MULT")
        return arg1 * arg2;

    return -1;
}

bool allCounted(vector_result& results)
{
    int count{ 0 };
    for (Result result : results)
    {
        if (result.counted)
            ++count;
    }

    return count == results.size();
}

bool pointerCounted(string arg1, string arg2, vector_result& results)
{
    if (arg1[0] == '$' && arg2[0] == '$')
        return results[stoi(arg1.substr(1))].counted && results[stoi(arg2.substr(1))].counted;
    else if (arg1[0] == '$')
        return results[stoi(arg1.substr(1))].counted;
    else if (arg2[0] == '$')
        return results[stoi(arg2.substr(1))].counted;
    else
        return true;
}

void solve(vector_line& lines, vector_result& results, int n)
{
    // count non relative cells
    for (int i = 0; i < n; ++i)
    {
        if (lines[i].arg1[0] != '$' && lines[i].arg2[0] != '$')
        {            
            results[i].result = countResult(lines[i].operation, getArg(lines[i].arg1, results), getArg(lines[i].arg2, results));
            results[i].counted = true;
        }
            
    }
    // count relative cells
    while (!allCounted(results)) {

        for (int i = 0; i < n; ++i)
        {
            if (results[i].counted)
                continue;
            else if (pointerCounted(lines[i].arg1, lines[i].arg2, results))
            {
                results[i].result = countResult(lines[i].operation, getArg(lines[i].arg1, results), getArg(lines[i].arg2, results));
                results[i].counted = true;
            }
            else
                continue;
        }
    }
    
}

int main()
{
    vector_line lines;
    int n{ getData(lines) };
    vector_result results;

    initResults(results, n);

    solve(lines, results, n);

    printResults(results);

}