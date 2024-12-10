#include <iostream>
#include <ctime> // Include ctime for time manipulation

using namespace std; // Bring the entire std namespace into scope

int main() {
    // Get the current time as time_t
    time_t now_c = time(nullptr); // Get current time

    // Use ctime to convert time_t to a string
    cout << "Current time: " << ctime(&now_c);
    return 0;
}