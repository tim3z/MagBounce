/*
 * Handling any Physics appearing in the game
 */

package physics;

import java.util.List;
import mechanics.Ball;
import world.LevelObject;


/**
 * @author Eagle
 */
public final class Physics {

	private static Vector2D gravity = new Vector2D(0, -0.001);
	
	private Physics() { }

	/**
	 * Moves the given {@link Ball} after the given time has passed.
	 * 
	 * @param levelObjects levelObjects to check for collision
	 * @param ball Ball to move
	 * @param time Time that has passed since the last update
	 * @return Whether a collision has occurred
	 */
	public static boolean move(List<LevelObject> levelObjects, Ball ball, long time) {
		Vector2D speedVector = ball.getSpeed().add(gravity.multiply(time));

		int a = ball.getMagnetState();
		if (a != 0) {
			Vector2D magnetism = getAccelerationAt(levelObjects, ball.getPosition()).multiply(time);
			if (a < 0) {
				magnetism = magnetism.multiply(-1);
			}
			speedVector = speedVector.add(magnetism);
		}

		Collision collision = detectCollisions(levelObjects, ball, speedVector.multiply(time));
		if (collision != null) {
			collision.move(ball, time);
			return true;
		} else {
			ball.move(speedVector, time);
			return false;
		}

	}

	private static Vector2D getAccelerationAt(List<LevelObject> levelObjects, Vector2D position) {
		Vector2D force = new Vector2D(0, 0);

		for (LevelObject levelObject : levelObjects) {
			Vector2D connection = levelObject.getMiddle().multiply(-1).add(position);
			force = force.add(connection.normalize().multiply(levelObject.getStrength()).multiply(1.0/(Math.pow(connection.norm(), 2))));
		}

		return force;
	}

	/**
	 * Detects whether the given {@link MovingObject} collides with the given {@LevelObject}s.
	 * 
	 * @param levelObjects Level objects the object might collide with
	 * @param object Moving object
	 * @param direction Direction of the movement
	 * @return Collision or <code>null</code> if none has occurred
	 */
	public static Collision detectCollisions(List<LevelObject> levelObjects, MovingObject object, Vector2D direction) {
		int radius = object.getCollisionRadius();

		//Vector2D collisionPoint;
		Vector2D wall = null;
		double a = 1;
		double tmpA;

		long llx;
		long lly;
		long urx;
		long ury;

		for (LevelObject levelObject : levelObjects) {

			llx = levelObject.getLlx() - radius;
			lly = levelObject.getLly() - radius;
			urx = levelObject.getUrx() + radius;
			ury = levelObject.getUry() + radius;

			tmpA = (llx - object.getPosition().getX()) / direction.getX();

			if (tmpA >= 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getY() <= ury && tmpCollPoint.getY() >= lly) {
					a = tmpA;
					wall = new Vector2D(0, 1);
				}
			}

			tmpA = (urx - object.getPosition().getX()) / direction.getX();

			if (tmpA >= 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getY() <= ury && tmpCollPoint.getY() >= lly) {
					a = tmpA;
					wall = new Vector2D(0, 1);
				}
			}

			tmpA = (lly - object.getPosition().getY()) / direction.getY();

			if (tmpA >= 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getX() <= urx && tmpCollPoint.getX() >= llx) {
					a = tmpA;
					wall = new Vector2D(1, 0);
				}
			}

			tmpA = (ury - object.getPosition().getY()) / direction.getY();

			if (tmpA >= 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getX() <= urx && tmpCollPoint.getX() >= llx) {
					a = tmpA;
					wall = new Vector2D(1, 0);
				}
			}

		}

		if (wall != null) {
			return new Collision(wall, object.getPosition().add(direction.multiply(a)), direction, a);
		}

		return null;
	}
}