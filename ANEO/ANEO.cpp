#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cmath>
//#include "plog\log.h"



using namespace std;

constexpr bool test{ false };


// test data
constexpr int maxSpeedTest{ 90 };
constexpr int lightCountTest{ 3 };

vector<int> distanceTest{ 300, 1500, 3000 };
vector<int> durationTest{ 10, 10,10 };


struct TrafficLight
{
    double distance;
    double duration;
};

using vector_type = vector<TrafficLight>;

struct GameData
{
    int maxSpeed;
    int lightCount;
};

void fillTrafficLights(vector_type& trafficLights, int lightCount, bool test)
{
    for (int i = 0; i < lightCount; ++i) {

        int distance{};
        int duration{};

        if (test)
        {
            distance = distanceTest[i];
            duration = durationTest[i];
        }
        else
        {
            cin >> distance >> duration;
            cin.ignore();
        }


        TrafficLight trafficLight{ double(distance) / 1000, double(duration) / 3600 };
        trafficLights.push_back(trafficLight);
    }
}

GameData getData(vector_type& trafficLights, bool test)
{   
    
    
    GameData gameData{};

    if (test)
    {
        gameData.maxSpeed = maxSpeedTest;
        gameData.lightCount = lightCountTest;
    }
    else
    {
        cin >> gameData.maxSpeed;
        cin.ignore();

        cin >> gameData.lightCount;
        cin.ignore();
    }
   

    fillTrafficLights(trafficLights, gameData.lightCount, test);

    return gameData;

}

void testData(GameData gameData, vector_type& trafficLights)
{
    cerr << "Max speed: " << gameData.maxSpeed << '\n';
    cerr << "LightCount: " << gameData.lightCount << '\n';

    for (auto trafficLight : trafficLights)
        cerr << "distance: " << trafficLight.distance << ' ' << "duration: " << trafficLight.duration << "\n";

}

bool passTrafficLight(TrafficLight trafficLight, int speed, bool test)
{
    double hoursToLight{ trafficLight.distance / speed };
    double period{ hoursToLight / trafficLight.duration };
    bool returnValue{ fmod(period, 2) == 0 || period <= 1 };

    /*
    if (test)
    {
        PLOGD << "speed: " << speed << " distance: " << trafficLight.distance << " duration: " << trafficLight.duration;
        PLOGD << "hourToLight " << hoursToLight << " period: " << period;
        PLOGD << "fmod: " << fmod(period, 2.0);
        PLOGD << "returnValue: " << returnValue;
    }
    */
    
    
    
    
    return returnValue;
}

int solve(vector_type& trafficLights, int maxSpeed, bool test)
{
    for (int speed = maxSpeed; speed >= 1; --speed)
    {
        
        int count{ 0 };
               
        for (TrafficLight trafficLight : trafficLights)
        {
            bool pass{ passTrafficLight(trafficLight, speed, test) };
            if (pass)
                ++count;
        }
               

        if (count == trafficLights.size())
            return speed;

    }
}



int main()
{
    
    
    //plog::init(plog::debug, "Logfile.txt");
    
    vector_type trafficLights{};
    GameData gameData{ getData(trafficLights, test) };
     
    int maxSpeed{ gameData.maxSpeed };
    int lightCount{ gameData.lightCount };

    if(test)
        testData(gameData, trafficLights);
       
    cout << solve(trafficLights, maxSpeed, test) << endl;

    return 0;
}
