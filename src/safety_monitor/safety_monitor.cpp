// safety_monitor.cpp
// Stub for SafetyMonitor (watchdog)

#include <thread>
#include <atomic>
#include <iostream>

class SafetyMonitor {
public:
    SafetyMonitor() : running(true) {
        watchdogThread = std::thread(&SafetyMonitor::watchdogLoop, this);
    }
    ~SafetyMonitor() {
        running = false;
        if (watchdogThread.joinable()) watchdogThread.join();
    }

    void heartbeat() {
        lastBeat = std::chrono::steady_clock::now();
    }

private:
    std::atomic<bool> running;
    std::chrono::steady_clock::time_point lastBeat;
    std::thread watchdogThread;

    void watchdogLoop() {
        using namespace std::chrono;
        lastBeat = steady_clock::now();
        while (running) {
            auto now = steady_clock::now();
            if (duration_cast<milliseconds>(now - lastBeat).count() > 50) {
                std::cerr << "Watchdog timeout: resetting module\n";
                // TODO: trigger safe reset
            }
            std::this_thread::sleep_for(milliseconds(10));
        }
    }
};
