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
        position = position.add(direction);
        speed = direction;
    }

}
