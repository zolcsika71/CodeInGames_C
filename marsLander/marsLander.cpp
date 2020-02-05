#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h> 

//#include "Header.h"

using namespace std;

constexpr double gravity{ 3.711 };
constexpr int vSpeedMax{ 40 };
constexpr int hSpeedMax{ 20 };
constexpr int allowedHSpeedMax{ 30 };
constexpr int goRight{ -22 };
constexpr int goLeft{ 22 };

struct MarsLander
{
    int x;
    int y;
    int hSpeed; // the horizontal speed(in m / s), can be negative.
    int vSpeed; // the vertical speed (in m/s), can be negative.
    int fuel; // the quantity of remaining fuel in liters.
    int rotate; // the rotation angle in degrees (-90 to 90).
    int power; // the thrust power (0 to 4).
};

struct Surface
{
    int x;
    int y;
};

struct LandingZone
{
    int from;
    int to;
    int length;
    int y;
};

void printLandCoords(vector<Surface>& array)
{
    for (int i = 0; i < array.size(); ++i)
        cerr << array[i].x << " " << array[i].y << '\n';
}

LandingZone getLandingZone(vector<Surface>& landCoords)
{        
    LandingZone landingZone;
    
    for (int i = 0; i < landCoords.size() - 1; ++i)
    {
        if (landCoords[i].y == landCoords[static_cast<double>(i) + 1].y)
        {
            landingZone = { landCoords[i].x, landCoords[static_cast<double>(i) + 1].x, landCoords[static_cast<double>(i) + 1].x - landCoords[i].x, landCoords[i].y };
            return landingZone;
        }
            
    }
}

vector<Surface> getLandCoords()
{
    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();

    vector<Surface> landCoords;
    Surface surface;

    for (int i = 0; i < surfaceN; ++i)
    {
        // X coordinate of a surface point. (0 to 6999)
        // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> surface.x >> surface.y; cin.ignore();
        landCoords.push_back(surface);
    }

    return landCoords;
}

int getLandHeight(vector<Surface>& landCoords, int x)
{

}

bool isValidLandingZone(MarsLander& marsLander, LandingZone& landingZone)
{
    return marsLander.x >= landingZone.from && marsLander.x <= landingZone.to;
}




int main()
{
    
    vector<Surface> landCoords{ getLandCoords() };
    LandingZone landingZone{ getLandingZone(landCoords) };

    printLandCoords(landCoords);
    cerr << "from: " << landingZone.from << " to: " << landingZone.to << " y: " << landingZone.y << endl;

    int power{ 0 };
    int rotate{ 0 };
    
    // game loop
    while (true) {

        MarsLander marsLander;

        cin >> marsLander.x >> marsLander.y >> marsLander.hSpeed >> marsLander.vSpeed >> marsLander.fuel >> marsLander.rotate >> marsLander.power; cin.ignore();

        

          
        
      

                
        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        cout << rotate << " " << power << endl;
    }

}

