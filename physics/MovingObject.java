/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package physics;

/**
 *
 * @author Eagle
 */
public class MovingObject {

    private Vector2D position;
    private Vector2D speed; // which this object had moving into the position it now has
    private int collisionRadius;

    public MovingObject() {
        this(new Vector2D(0, 0), 1);
        //throw new Error("DO FUCKING NOT USE THIS");
    }

    /**
     * Create an instance
     * @param position
     */
    public MovingObject(Vector2D position, int radius) {
        this.position = position;
        this.collisionRadius = radius;
    }

    /**
     * Move this Object into the given direction
     * @param speedVector
     */
    public void move(Vector2D speedVector, long time) {
        setPosition(getPosition().add(speedVector.multiply(time)));
        setSpeed(speedVector);
    }

    /**
     * @return the position
     */
    public Vector2D getPosition() {
        return position;
    }

    /**
     * @param position the position to set
     */
    public void setPosition(Vector2D position) {
        this.position = position;
    }

    /**
     * @return the speed
     */
    public Vector2D getSpeed() {
        return speed;
    }

    /**
     * @param speed the speed to set
     */
    public void setSpeed(Vector2D speed) {
        this.speed = speed;
    }

    /**
     * @return the collisionRadius
     */
    public int getCollisionRadius() {
        return collisionRadius;
    }

}
