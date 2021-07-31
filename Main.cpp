#include <iostream>
#include <fstream>
#include <urlmon.h>
#include <cstdio>
#include <nlohmann\json.hpp>


#pragma comment (lib, "urlmon.lib")

DWORD dwLocalPlayer;

using json = nlohmann::json;
using namespace std;


int main()
{
    remove("offsets.json");

    URLDownloadToFile(NULL, "https://raw.githubusercontent.com/frk1/hazedumper/master/csgo.json", "offsets.json", 0, 0);

    ifstream files{ "offsets.json" };
    json offset = json::parse(files);
    files.close();

    dwLocalPlayer = offset["signatures"]["dwLocalPlayer"];

    remove("offsets.json");

    cout << dwLocalPlayer << endl;

    system("PAUSE");
}