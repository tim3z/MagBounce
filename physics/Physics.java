/*
 * Handling any Physics appering in the game
 */

package physics;

/**
 * @author Eagle
 */
public abstract class Physics {

    private static Vector2D gravity = new Vector2D(0, -10);

    public static void move(MovingObject object, long time) {
        Vector2D direction = object.getSpeed();
        direction.addToThis(gravity);
        direction.addToThis(World.getAccelerationAt(object.getPosition()));
        object.move(direction);
    }

}
