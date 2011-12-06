#ifndef APP_H
#define APP_H

class AppState;
class Display;
struct ALLEGRO_DISPLAY;

/**
 * class App
 * 
 */
class App {
public:
    App();
    virtual ~App();

    void fire();
    void setExit(const bool flag) {
        exit = flag;
    }

private:
    Display* display;
    AppState* currentState;
    bool exit;

    inline void processInput();
    inline void update(int dt);
    inline void render();

    /* uncopyable */
    App(const App&);
    const App& operator=(const App&);
};

#endif // APP_H
