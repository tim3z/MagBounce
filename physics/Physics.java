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

        Collision collision = detectCollisions(level, object, direction);
        if (collision != null) {
            collision.move(object);
        } else {
            object.move(direction.multiply(time));
        }

    }

    private static Collision detectCollisions(Level level, MovingObject object, Vector2D direction) {
        List<LevelObject> objects = level.getObjects();
        int radius = object.getCollisionRadius();

        Vector2D collisionPoint;
        Vector2D wall = null;
        double a = 1;
        double tmpA;

        long Llx;
        long Lly;
        long Urx;
        long Ury;

        for (LevelObject levelObject : objects) {

            Llx = levelObject.getLlx() - radius;
            Lly = levelObject.getLly() - radius;
            Urx = levelObject.getUrx() + radius;
            Ury = levelObject.getUry() + radius;

            tmpA = (Llx - object.getPosition().getX()) / direction.getX();

            if (tmpA >= 0 && tmpA < a) {
                Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(a));
                if (tmpCollPoint.getY() <= Ury && tmpCollPoint.getY() >= Lly) {
                    a = tmpA;
                    wall = new Vector2D(0, 1);
                    collisionPoint = tmpCollPoint;
                }
            }

            tmpA = (Urx - object.getPosition().getX()) / direction.getX();

            if (tmpA >= 0 && tmpA < a) {
                Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(a));
                if (tmpCollPoint.getY() <= Ury && tmpCollPoint.getY() >= Lly) {
                    a = tmpA;
                    wall = new Vector2D(0, 1);
                    collisionPoint = tmpCollPoint;
                }
            }

            tmpA = (Lly - object.getPosition().getY()) / direction.getY();

            if (tmpA >= 0 && tmpA < a) {
                Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(a));
                if (tmpCollPoint.getX() <= Urx && tmpCollPoint.getX() >= Llx) {
                    a = tmpA;
                    wall = new Vector2D(1, 0);
                    collisionPoint = tmpCollPoint;
                }
            }

            tmpA = (Ury - object.getPosition().getY()) / direction.getY();

            if (tmpA >= 0 && tmpA < a) {
                Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(a));
                if (tmpCollPoint.getX() <= Urx && tmpCollPoint.getX() >= Llx) {
                    a = tmpA;
                    wall = new Vector2D(1, 0);
                    collisionPoint = tmpCollPoint;
                }
            }

        }

        if (wall != null) {
            return new Collision(wall, object.getPosition().add(direction.multiply(a)), direction, a);
        }
        
        return null;
    }

}
