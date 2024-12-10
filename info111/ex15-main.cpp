// g++ ex15-main.cpp tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp -o ex15-main -I/usr/include/python3.12 -I/usr/lib/python3/dist-packages/numpy/core/include -lpython3.12
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
    vector<vector<string>> t = litTableauCSV("donnees/BTC_USD_4h_binancedata.csv");
    vector<double> time;
    vector<double> price;

    for (vector<string> ligne: t) {
        tm tm = {};

        istringstream ss(ligne[0]);
        ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");

        time_t time_point = mktime(&tm);
        auto timestamp = static_cast<double>(time_point);


        // 2 tableaux x (temps), y (prix)
        time.push_back(timestamp);
        price.push_back(stod(ligne[1]));

        // for(auto val: time) cerr << val << endl;

        // lib compte depuis 1900
        // cerr << tm.tm_year + 1900 << " " << tm.tm_mon + 1 << " " << tm.tm_mday << " - "
        //      << tm.tm_hour << " " << tm.tm_min << endl;        
    }

    // similaire à python en cours intro info
    plt::plot(time, price);
    plt::title("BTC/USD");
    plt::xlabel("Temps");
    plt::ylabel("Prix $");
    plt::show();

    return 0;
}