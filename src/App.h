#ifndef APP_H
#define APP_H

#include "MainThread.h"
#include "Graphics/Display.h"
#include "Utilities/Logger.h"
#include "Utilities/Timer.h"

class AppState;
struct ALLEGRO_EVENT_QUEUE;
struct ALLEGRO_TIMER;
struct Config;
using namespace r2d;

/**
 * class App
 * 
 */
class App {
public:
    App(const Config* const config); // FIXME: pass by value or reference
    App(const App&) = delete;
    const App& operator=(const App&) = delete;
    virtual ~App();

    void run(AppState* firstState);

private:
    AppState* currentState;
    const Config* const config;
    Display* display;
    Logger* logger;

    class GraphicsThread : public MainThread {
    public:
        GraphicsThread(const App& app); // FIXME: only pass the display and manually set the current state?
        GraphicsThread(const GraphicsThread&) = delete;
        const GraphicsThread& operator=(const GraphicsThread&) = delete;
        virtual ~GraphicsThread();

    private:
        const App& app;
        Timer* timer;

        void init();
        void main();
        void cleanup();
    };
};

#endif // APP_H
