#include <chrono>

using namespace std::chrono;

class TrackingTimer
{
public:
    void start(void) { start_ = steady_clock::now(); };
    void stop(void) { end_ = steady_clock::now(); };
    double GetElapsedTime(void);

private:
    steady_clock::time_point start_;
    steady_clock::time_point end_;
    double elapsedTime_;
};