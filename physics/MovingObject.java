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

    /**
     * Create an instance
     * @param position
     */
    public MovingObject(Vector2D position) {
        this.position = position;
    }

    /**
     * Move this Object into the given direction
     * @param direction
     */
    public void move(Vector2D direction) {
        setPosition(getPosition().add(direction));
        setSpeed(direction);
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

}
