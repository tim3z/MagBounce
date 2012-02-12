#ifndef APP_H
#define APP_H

class AppState;
class Display;
struct ALLEGRO_THREAD;
struct Config;

/**
 * class App
 * 
 */
class App {
public:
    App(const Config* const config);
    virtual ~App();

    void run(AppState* firstState);

private:
    AppState* currentState;
    const Config* const config;
    Display* display;

    class GraphicsThread {
    public:
        GraphicsThread(const App* const app);
        ~GraphicsThread();

    private:
        ALLEGRO_THREAD* thread;

        static void* threadFunction(ALLEGRO_THREAD* thread, void* appInstance);

        /* uncopyable */
        GraphicsThread(const GraphicsThread&);
        const GraphicsThread& operator=(const GraphicsThread&);
    };

    /* uncopyable */
    App(const App&);
    const App& operator=(const App&);
};

#endif // APP_H
