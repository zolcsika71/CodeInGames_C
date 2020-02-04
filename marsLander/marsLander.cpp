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
constexpr int breakPoint{ 500 };

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
    int y;
};

void printLandingZones(vector<LandingZone>& array)
{
    for (int i = 0; i < array.size(); ++i)
        cerr << array[i].from << " " << array[i].to << '\n';
}

void printLandCoords(vector<Surface>& array)
{
    for (int i = 0; i < array.size(); ++i)
        cerr << array[i].x << " " << array[i].y << '\n';
}

vector<LandingZone> getLandingZones(vector<Surface>& landCoords)
{
    LandingZone landingZone;
    vector<LandingZone> landingZones;

    for (int i = 0; i < landCoords.size() - 1; ++i)
    {
        if (landCoords[i].y == landCoords[i + 1].y) {
            landingZone = { landCoords[i].x, landCoords[i + 1].x, landCoords[i].y };
            landingZones.push_back(landingZone);
        }
    }

    return landingZones;
}

bool isValidLandingZone(MarsLander& marsLander, vector<LandingZone>& landingZones)
{
    for (int i = 0; i < landingZones.size(); ++i)
    {
        if (marsLander.x >= landingZones[i].from && marsLander.x <= landingZones[i].to)
            return true;
    }

    return false;
}

bool isValidLanding(MarsLander& marsLander, vector<LandingZone>& landingZones)
{
    bool landingZone{ isValidLandingZone(marsLander, landingZones) };
    bool angle{ marsLander.rotate == 0 };
    bool speed{ abs(marsLander.vSpeed) <= vSpeedMax && abs(marsLander.hSpeed) <= hSpeedMax };

    //cerr << "landingZone: " << landingZone << " angle: " << angle << " speed: " << speed << endl;

    return landingZone && angle && speed;
}

MarsLander marsLander;

int main()
{


    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();

    vector<Surface> landCoords;
    Surface surface;

    for (int i = 0; i < surfaceN; ++i) {
        // X coordinate of a surface point. (0 to 6999)
        // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> surface.x >> surface.y; cin.ignore();
        landCoords.push_back(surface);
    }

    vector<LandingZone> landingZones{ getLandingZones(landCoords) };

    int power{ 0 };
    int rotate{ 0 };
    int lastPower{ 0 };
    



    // game loop
    while (true) {

        cin >> marsLander.x >> marsLander.y >> marsLander.hSpeed >> marsLander.vSpeed >> marsLander.fuel >> marsLander.rotate >> marsLander.power; cin.ignore();

        cerr << "isValidLanding: " << isValidLanding(marsLander, landingZones) << endl;

        bool landingZone{ isValidLandingZone(marsLander, landingZones) };
        bool angle{ marsLander.rotate == 0 };
        bool vSpeed{ abs(marsLander.vSpeed) < vSpeedMax };
        bool hSpeed{ abs(marsLander.hSpeed) < hSpeedMax };

        //cerr << "landingZone: " << landingZone << " angle: " << angle << " hSpeed: " << hSpeed << " vSpeed: " << vSpeed << endl;

        

        if (vSpeed)
        {
                      
            
            if (marsLander.power == 4)
                --power;
                

        }
        else
        {
            
            if (marsLander.power < 4)
                ++power;
        }


        lastPower = power;



        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        cout << rotate << " " << power << endl;
    }

}

