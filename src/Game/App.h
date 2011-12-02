#ifndef APP_H
#define APP_H

class AppState;
class EventHandler;
class Game;
class Graphics;

/**
 * class App
 * 
 */

class App {

private:
    EventHandler *eventHandler;
    Game *game;
    AppState *currentState;
    bool exit;

    App(const App&);
    const App& operator=(const App&);

public:

    /**
     * Empty Constructor
     */
    App();

    void fire();

    void setExit(bool flag) {
        exit = flag;
    }

    /**
     * Empty Destructor
     */
    virtual ~App();

};

#endif // APP_H
