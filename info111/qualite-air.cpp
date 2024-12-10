// g++ qualite-air.cpp tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp -o qualite-air -I/usr/include/python3.12 -I/usr/lib/python3/dist-packages/numpy/core/include -lpython3.12
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "tableau-lecture-csv.hpp"
#include "lib/matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;

int main() {
    vector<vector<string>> t = litTableauCSV("donnees/qualite-de-lair-mesuree-dans-la-station-chatelet-2021-maintenant.csv");
    vector<double> time;
    vector<double> co2;

    for (vector<string> ligne: t) {
        tm tm = {};

        istringstream ss(ligne[0]);
        ss >> get_time(&tm, "%Y-%m-%dT%H:%M:%S");

        time_t time_point = mktime(&tm);
        auto timestamp = static_cast<double>(time_point);


        // 2 tableaux x (temps), y (co2)
        time.push_back(timestamp);
        // cerr << ligne[4] << endl;
        if(ligne[4] != "ND") {
            co2.push_back(stoi(ligne[4]));
        } else co2.push_back(0);

        // for(auto val: time) cerr << val << endl;

        // lib compte depuis 1900
        // cerr << tm.tm_year + 1900 << " " << tm.tm_mon + 1 << " " << tm.tm_mday << " - "
        //      << tm.tm_hour << " " << tm.tm_min << endl;        
    }

    // similaire à python en cours intro info
    plt::plot(time, co2);
    plt::title("Qualité d'air");
    plt::xlabel("Temps");
    plt::ylabel("CO2");
    plt::show();

    return 0;
}