#ifndef APP_H
#define APP_H

class AppState;
class Display;
struct ALLEGRO_THREAD;

/**
 * class App
 * 
 */
class App {
public:
    App(); // TODO: pass flags (DEBUG etc.)
    virtual ~App();

    void run();

private:
    AppState* currentState;
    Display* display;

    ALLEGRO_THREAD* graphicsThread;
    ALLEGRO_THREAD* inputThread;
    ALLEGRO_THREAD* loggingThread;
    ALLEGRO_THREAD* soundThread;

    /*
     * Member function pointers cannot be used like C function pointers, so these functions must be static.
     * In case the app instance has to be accessed, it is passed via arg.
     */
    static void* graphicsThreadFunction(ALLEGRO_THREAD* thread, void* arg);
    static void* inputThreadFunction(ALLEGRO_THREAD* thread, void* arg);
    static void* loggingThreadFunction(ALLEGRO_THREAD* thread, void* arg);
    static void* soundThreadFunction(ALLEGRO_THREAD* thread, void* arg);

    /* uncopyable */
    App(const App&);
    const App& operator=(const App&);
};

#endif // APP_H
