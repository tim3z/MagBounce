/*
 * Handling any Physics appearing in the game
 */

package physics;

import java.util.List;
import world.Level;
import world.LevelObject;


/**
 * @author Eagle
 */
public abstract class Physics {

    private static Vector2D gravity = new Vector2D(0, -10);

    public static void move(Level level, MovingObject object, long time) {
        Vector2D direction = object.getSpeed();
        direction.addToThis(gravity.multiply(time));
        //direction.addToThis(World.getAccelerationAt(object.getPosition()).multiply(time));

        detectCollisions(level, object, direction);

        object.move(direction.multiply(time));
    }

    private static Vector2D detectCollisions(Level level, MovingObject object, Vector2D direction) {
        List<LevelObject> objects = level.getObjects();
        Vector2D wall;

        for (LevelObject levelObject : objects) {
            if () {

            }
        }

        return wall;
    }

}
