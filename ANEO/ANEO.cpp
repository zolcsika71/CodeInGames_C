#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct TrafficLight
{
    int distance;
    int duration;
};

using vector_type = vector<TrafficLight>;

void fillTrafficLights(vector_type& trafficLights, int lightCount)
{
    for (int i = 0; i < lightCount; ++i) {

        int distance{};
        int duration{};
       
        cin >> distance >> duration;
        cin.ignore();      
        
        TrafficLight trafficLight{ distance, duration };
        trafficLights.push_back(trafficLight);
    }
}

int getData(vector_type& trafficLights)
{       
    int maxSpeed;
    int lightCount;
   
    cin >> maxSpeed >> lightCount;
    cin.ignore();

    fillTrafficLights(trafficLights, lightCount);

    return maxSpeed;

}

bool passTrafficLight(TrafficLight trafficLight, int speed)
{
    double timeToReach{ (36 * trafficLight.distance) / (10 * speed) };
    bool returnValue{ int(timeToReach) % (2 * trafficLight.duration) < trafficLight.duration };        
   
    return returnValue;
}

int solve(vector_type& trafficLights, int maxSpeed)
{
    for (int speed = maxSpeed; speed >= 1; --speed)
    {       
        
        
        int count{ 0 };
               
        for (TrafficLight trafficLight : trafficLights)
        {
            bool pass{ passTrafficLight(trafficLight, speed) };
            if (pass)
                ++count;
            else
                break;
        }
               

        if (count == trafficLights.size())
            return speed;

    }
}

int main()
{   
       
    vector_type trafficLights{};
    int maxSpeed{ getData(trafficLights) };   
    
    cout << solve(trafficLights, maxSpeed) << endl;

    return 0;
}
