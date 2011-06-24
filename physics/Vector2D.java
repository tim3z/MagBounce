/*
 * A Vector to represent movements, positions or directions, just like in school :-D
 */

package physics;

/**
 *
 * @author Eagle
 */
public class Vector2D {

    private double x;
    private double y;

    /**
     * Creating an instance of this class
     * @param x
     * @param y
     */
    public Vector2D(double x, double y) {
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

    public void addToThis(Vector2D other) {
        x += other.x;
        y += other.y;
    }

    /**
     * Return this * factor
     * @param factor
     * @return
     */
    public Vector2D multiply(double factor) {
        return new Vector2D(factor * x, factor * y);
    }


    /**
     * Return this Vector reflected at the wall with the given normal
     * @param wallNormal does not need to be normalized
     * @return
     */
    public Vector2D reflectAtNormal(Vector2D wallNormal) {
        wallNormal = wallNormal.normalize();
        double scale = this.norm();
        Vector2D normalized = multiply(1 / scale);

        return wallNormal.multiply(-2 * normalized.SKP(wallNormal)).add(normalized).multiply(scale);
    }

    /**
     * Return the SkalarProduct of this Vector with the other one
     * @param other
     * @return
     */
    public double SKP(Vector2D other) {
        return this.x * other.x + this.y + other.y;
    }

    /**
     * Return the (2-)Norm of this Vector
     * @return
     */
    public double norm() {
        return Math.sqrt(this.SKP(this));
    }

    /**
     * Return this Vector normalized
     * @return
     */
    public Vector2D normalize() {
        return multiply(1/norm());
    }



    /**
     * @return the x
     */
    public double getX() {
        return x;
    }

    /**
     * @param x the x to set
     */
    public void setX(double x) {
        this.x = x;
    }

    /**
     * @return the y
     */
    public double getY() {
        return y;
    }

    /**
     * @param y the y to set
     */
    public void setY(double y) {
        this.y = y;
    }

}
