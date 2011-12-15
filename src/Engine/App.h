#ifndef APP_H
#define APP_H

class AppState;
class Display;

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

    /* uncopyable */
    App(const App&);
    const App& operator=(const App&);
};

#endif // APP_H
