#include "simulation_coreTest.h"

void TestSimulationCore()
{
    TestSimEngine* engine = new TestSimEngine(0);
    engine->SetSettingsFile("settingsfile.csv");
    engine->Start();
}
