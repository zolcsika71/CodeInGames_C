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

struct Valid
{
    bool landingZone;
    bool angle;
    bool vSpeed;
    bool hSpeed;
};

void printLandCoords(vector<Surface>& array)
{
    for (int i = 0; i < array.size(); ++i)
        cerr << array[i].x << " " << array[i].y << '\n';
}

LandingZone getLandingZone()
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

    printLandCoords(landCoords);
    
    LandingZone landingZone;
    
    for (int i = 0; i < landCoords.size() - 1; ++i)
    {
        if (landCoords[i].y == landCoords[i + 1].y)
        {
            landingZone = { landCoords[i].x, landCoords[i + 1].x, landCoords[i + 1].x - landCoords[i].x, landCoords[i].y };
            return landingZone;
        }
            
    }
}

bool isValidLandingZone(MarsLander& marsLander, LandingZone& landingZone)
{
    return marsLander.x >= landingZone.from && marsLander.x <= landingZone.to;
}




int main()
{
    
    LandingZone landingZone{ getLandingZone() };
    

    cerr << "from: " << landingZone.from << " to: " << landingZone.to << " y: " << landingZone.y << endl;

    int power{ 0 };
    int rotate{ 0 };
    
    // game loop
    while (true) {

        MarsLander marsLander;

        cin >> marsLander.x >> marsLander.y >> marsLander.hSpeed >> marsLander.vSpeed >> marsLander.fuel >> marsLander.rotate >> marsLander.power; cin.ignore();

        Valid land{ isValidLandingZone(marsLander, landingZone),  marsLander.rotate == 0, abs(marsLander.vSpeed) < vSpeedMax, abs(marsLander.hSpeed) < hSpeedMax };

        cerr << "landingZone: " << land.landingZone << " angle: " << land.angle << " hSpeed: " << land.hSpeed << " vSpeed: " << land.vSpeed << endl;

          
        
        if (marsLander.x < landingZone.from && abs(marsLander.hSpeed) < allowedHSpeedMax) // marsLander is on the left at low speed
        {
            cerr << "marsLander is on the left" << endl;
            rotate = goRight;
        }
        else if (marsLander.x > landingZone.to && abs(marsLander.hSpeed) < allowedHSpeedMax) // marsLander is on the right at low speed
        {
            cerr << "marsLander is on the right" << endl;
            rotate = goLeft;
        } 
        else if (marsLander.x < landingZone.from || marsLander.x > landingZone.to)
        {
            rotate = 0;
        }
        else
        {
            if (abs(marsLander.hSpeed) <= 5)
            {
                rotate = 0;
            }
            else if (abs(marsLander.hSpeed) > hSpeedMax && marsLander.hSpeed > 0 && marsLander.hSpeed > -allowedHSpeedMax) // drifting right -> hSpeed > 20 && hSpeed > -30
            {
                cerr << "marsLander is drifting right" << endl;
                rotate = goLeft;
            }
            else if (abs(marsLander.hSpeed) > hSpeedMax && marsLander.hSpeed < 0 && marsLander.hSpeed < allowedHSpeedMax) // drifting left -> hSpeed < -20 && hSpeed < 30
            {
                cerr << "marsLander is drifting left" << endl;
                rotate = goRight;
            }
        }
        
        if (land.vSpeed && land.landingZone)
        {
            if (marsLander.power > 0)
                --power;
        }
        else if (land.landingZone)
        {
            if (marsLander.power < 4)
                ++power;
        }

                
        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        cout << rotate << " " << power << endl;
    }

}

