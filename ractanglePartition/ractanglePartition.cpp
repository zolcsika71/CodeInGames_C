#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using vector_int = vector<int>;

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


// TODO use map()
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

void getSections(vector_int& xMeasurements, vector_int& yMeasurements, vector_int& xSections, vector_int& ySections, GameData data)
{
    
    vector_int xPoints;
    getPoints(xPoints, xMeasurements, data.countX, data.width);

    vector_int yPoints; 
    getPoints(yPoints, yMeasurements, data.countY, data.height);      
    
    fillSections(xPoints, xSections);   
    fillSections(yPoints, ySections);    
    
}

void solve(vector_int& xSections, vector_int& ySections)
{
    int counter{ 0 };
    
    for (int xSection : xSections)
    {
        for (int ySection : ySections)
            if (xSection == ySection)
                ++counter;

    }

    cout << counter;
}


int main()
{
    vector_int xMeasurements;
    vector_int yMeasurements;

    GameData data{ getData(xMeasurements, yMeasurements) };   
    
    vector_int xSections;
    vector_int ySections;

    getSections(xMeasurements, yMeasurements, xSections, ySections, data);

    solve(xSections, ySections); 
    
    return 0;    
}