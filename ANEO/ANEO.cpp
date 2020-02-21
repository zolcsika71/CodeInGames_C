#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TrafficLight
{
    int distance;
    int duration;
};

using vector_type = vector<TrafficLight>;

struct GameData
{
    int maxSpeed;
    int lightCount;
};

GameData getData()
{
    GameData gameData;

    cin >> gameData.maxSpeed;
    cin.ignore();

    cin >> gameData.lightCount;
    cin.ignore();

    return gameData;

}

void testData(GameData gameData, vector_type& trafficLights)
{
    cerr << "Max speed: " << gameData.maxSpeed << '\n';
    cerr << "LightCount: " << gameData.lightCount << '\n';

    for (auto trafficLight : trafficLights)
        cerr << "distance: " << trafficLight.distance << ' ' << "duration: " << trafficLight.duration << "\n";

}

void fillTrafficLights(vector_type& trafficLights, int lightCount)
{
    for (int i = 0; i < lightCount; ++i) {

        int distance;
        int duration;

        cin >> distance >> duration;
        cin.ignore();

        TrafficLight trafficLight{ distance, duration };
        trafficLights.push_back(trafficLight);
    }
}

int main()
{
    GameData gameData{ getData() };

    int maxSpeed{ gameData.maxSpeed };
    int lightCount{ gameData.lightCount };

    vector_type trafficLights{};

    fillTrafficLights(trafficLights, lightCount);

    testData(gameData, trafficLights);







    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << maxSpeed << endl;
}
