/*
 * A Class to handle Collisions and the Following Reflections
 */

package physics;

/**
 *
 * @author S.D.Eagle
 */
public final class Collision {

    private Vector2D wall;
    private Vector2D collisionPoint;
    private Vector2D direction;

    private double a;

    public Collision(Vector2D wall, Vector2D collisionPoint, Vector2D direction, double a) {
        setWall(wall);
        setCollisionPoint(collisionPoint);
        setDirection(direction);
        setA(a);
    }

    public void move(MovingObject object, long time) {
        Vector2D newDirection = direction.reflectAt(wall);
        object.setPosition(collisionPoint.add(newDirection.multiply(1-a)));
        object.setSpeed(newDirection.multiply(1/time));
    }


    /**
     * @return the wall
     */
    public Vector2D getWall() {
        return wall;
    }

    /**
     * @param wall the wall to set
     */
    public void setWall(Vector2D wall) {
        this.wall = wall;
    }

    /**
     * @return the collisionPoint
     */
    public Vector2D getCollisionPoint() {
        return collisionPoint;
    }

    /**
     * @param collisionPoint the collisionPoint to set
     */
    public void setCollisionPoint(Vector2D collisionPoint) {
        this.collisionPoint = collisionPoint;
    }

    /**
     * @return the direction
     */
    public Vector2D getDirection() {
        return direction;
    }

    /**
     * @param direction the direction to set
     */
    public void setDirection(Vector2D direction) {
        this.direction = direction;
    }

    /**
     * @return the a
     */
    public double getA() {
        return a;
    }

    /**
     * @param a the a to set
     */
    public void setA(double a) {
        this.a = a;
    }

    

}
