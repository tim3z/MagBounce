/*
 * A Vector to represant movements, positions or lirections, just like in school :-D
 */

package physics;

/**
 *
 * @author Eagle
 */
public class Vector2D {

    private long x;
    private long y;

    /**
     * Creating an instance of this class
     * @param x
     * @param y
     */
    public Vector2D(long x, long y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Return this + other
     * @param other
     * @return
     */
    public Vector2D add(Vector2D other) {
        return new Vector2D(x + other.x, y + other.y);
    }

    /**
     * Return this * factor
     * @param factor
     * @return
     */
    public Vector2D multiply(long factor) {
        return new Vector2D(factor * x, factor * y);
    }



    /**
     * @return the x
     */
    public long getX() {
        return x;
    }

    /**
     * @param x the x to set
     */
    public void setX(long x) {
        this.x = x;
    }

    /**
     * @return the y
     */
    public long getY() {
        return y;
    }

    /**
     * @param y the y to set
     */
    public void setY(long y) {
        this.y = y;
    }

}
