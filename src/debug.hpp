#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <ctime>
#include <string>

using namespace std;

inline string formatTimestamp(double timestamp) {
    int64_t seconds = static_cast<int64_t>(timestamp);
    int64_t millis = static_cast<int64_t>((timestamp - seconds) * 1e3);
    int64_t micros = static_cast<int64_t>((timestamp - seconds) * 1e6) % 1000;
    int64_t nanos  = static_cast<int64_t>((timestamp - seconds) * 1e9) % 1000;

    time_t raw_time = static_cast<time_t>(seconds);
    struct tm buf;
    gmtime_r(&raw_time, &buf); // UTC 기준

    stringstream ss;
    ss << put_time(&buf, "%Y-%m-%d %H:%M:%S") 
       << "." << setfill('0') << setw(3) << millis 
       << setfill('0') << setw(3) << micros 
       << setfill('0') << setw(3) << nanos;
    
    return ss.str();
}
