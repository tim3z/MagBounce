/*
 * MainThread.h
 *
 *  Created on: 13.02.2012
 *      Author: moritz
 */

#ifndef MAINTHREAD_H_
#define MAINTHREAD_H_

struct ALLEGRO_COND;
struct ALLEGRO_MUTEX;
struct ALLEGRO_THREAD;

/**
 * A permanent thread with an own main loop.
 *
 * This class serves as the base class for all threads continually performing some work in the background until stopped.
 * To create an own main thread, override the main() method.
 *
 * Make sure to call stop() at the beginning of the destructor of a derived class, to make sure destroyed resources are
 * no longer accessed from the thread.
 */
class MainThread {
public:
    /**
     * Create a new thread with an own main loop.
     *
     * @throw std::runtime_error if a fatal error occurs.
     */
    MainThread();
    MainThread(const MainThread&) = delete;
    const MainThread& operator=(const MainThread&) = delete;
    virtual ~MainThread();

    /**
     * Starts the thread.
     *
     * If the thread is already started, this function does not do anything.
     */
    void start();

    /**
     * Pauses the thread after the current iteration of the main loop.
     *
     * This does not cause cleanup() to be called.
     */
    void pause();

    /**
     * Resumes a paused thread.
     *
     * This does not cause init() to be called again.
     */
    void resume();

    /**
     * Waits for the current iteration of the thread's main loop to finish and stops it afterwards.
     */
    void stop();

private:
    ALLEGRO_THREAD* thread;
    ALLEGRO_MUTEX* threadCtrlMutex;
    ALLEGRO_COND* threadRestarted;
    bool paused;

    /**
     * Helper function passed to al_create_thread.
     *
     * Pointers to member functions cannot be used like normal C function pointers, so the function passed to
     * al_create_thread must be static. The MainThread instance is passed as a parameter, so that in the end a member
     * function is called nonetheless.
     *
     * @param thread ALLEGRO_THREAD representing this thread.
     * @param instance MainThread instance.
     */
    static void* threadFunction(ALLEGRO_THREAD* thread, void* instance);

    // private virtual functions (can be overridden, but not called inside subclasses)

    /**
     * Override this function to perform some extra initialization within the new thread when it is actually started.
     */
    virtual void init() {}

    /**
     * This function is repeatedly called inside the thread's main loop until the thread is destroyed. This is where
     * the thread performs its work.
     */
    virtual void main() = 0;

    /**
     * Override this function to perform cleanup work within the thread immediately before it finishes execution
     * (provided that it is stopped normally). Counterpart of init().
     */
    virtual void cleanup() {}
};

#endif /* MAINTHREAD_H_ */
