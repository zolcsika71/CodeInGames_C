#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

constexpr bool test{ false };

using vector_int = vector<int>;
using map_int = map<int, int>;

struct GameData
{
    int width;
    int height;
    int countX;
    int countY;
};

GameData getData(vector_int& xMeasurement, vector_int& yMeasurement)
{
    GameData data;

    
    cin >> data.width >> data.height >> data.countX >> data.countY;
    cin.ignore();

    for (int i = 0; i < data.countX; i++) {
        int x;
        cin >> x;
        cin.ignore();
        xMeasurement.push_back(x);
    }

    for (int i = 0; i < data.countY; i++) {
        int y;
        cin >> y;
        cin.ignore();
        yMeasurement.push_back(y);
    }   

    return data;
}

void getPoints(vector_int& points, vector_int& measurements, int count, int size)
{
    points.push_back(0);

    for (int i = 0; i < count; ++i)
        points.push_back(measurements[i]);

    points.push_back(size);

}

void fillSections(vector_int& points, vector_int& sections)
{
    for (int i = 1; i < points.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int result{ points[i] - points[j] };
            sections.push_back(result);
        }          
    } 
}

void getSections(vector_int& measurements, vector_int& sections, int count, int size)
{
    vector_int points;

    getPoints(points, measurements, count, size);

    fillSections(points, sections);    

}

void getCounter(vector_int& section, map_int& counter)
{
    
    int count{ 1 };
    int size{ section.size() - 1 };

    std::sort(section.begin(), section.end());
    
    for (int i = 0; i < size; ++i)
    {     
        if (section[i] == section[i + 1])        
            ++count;        
        else
        {
            counter.insert(pair<int, int>(section[i], count));
            count = 1;

            if (i == size - 1)
                counter.insert(pair<int, int>(section[i + 1], 1));

        }
    }
}

void testArray(vector_int& testArray)
{
    for (int section : testArray)
        cerr << section << ' ';
}

void testMap(map_int& testMap)
{    
    map_int::iterator it;
    
    for (it = testMap.begin(); it != testMap.end(); ++it)
        cerr << it->first << ": " << it->second << '\n';
}

void solve(vector_int& sections, map_int& counter)
{
    int count{ 0 };

    for (int i = 0; i < sections.size(); ++i)
        count += counter[sections[i]]; 

    cout << count;
}

int main()
{
    vector_int xMeasurements;
    vector_int yMeasurements;

    GameData data{ getData(xMeasurements, yMeasurements) };   
    
    vector_int xSections;
    vector_int ySections;  
    
    getSections(xMeasurements, xSections, data.countX, data.width);

    map_int counter;

    getCounter(xSections, counter);      
        
    getSections(yMeasurements, ySections, data.countY, data.height);    

    
    
    if (test)
    {                 
        cerr << "x: " << '\n';

        testArray(xSections);

        cerr << '\n';
        cerr << '\n';

        cerr << "y: " << '\n';

        testArray(ySections);

        cerr << '\n';
        cerr << '\n';


        testMap(counter);

        cerr << '\n';
        cerr << '\n';
    } 
    

    solve(ySections, counter); 
    
    return 0;    
}