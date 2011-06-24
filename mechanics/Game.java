/*
 * The Main Class to handle playing any concrete level
 */

package mechanics;

import world.Level;

/**
 *
 * @author S.D.Eagle
 */
public class Game {

    private long oldTime;
    private long difTime;

    private Ball ball;

    private Level level;

    public Game() {
        // load Stuff
    }

    /**
     * Actually running the instance
     */
    private void run() {
        boolean exit = false;
        while (!exit) {
            difTime = System.currentTimeMillis() - oldTime;
            //get input
            //react on input
            move(difTime);
            //draw();

            oldTime += difTime;
        }
    }

    private void move(long time) {
        physics.Physics.move(ball, time);
    }

    public Level getLevel() {
        return level;
    }
}
