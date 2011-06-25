/*
 * Handling any Physics appearing in the game
 */

package physics;

import java.util.List;
import mechanics.Ball;
import world.Level;
import world.LevelObject;


/**
 * @author Eagle
 */
public abstract class Physics {

	private static Vector2D gravity = new Vector2D(0, -0.001);

	public static boolean move(Level level, Ball object, long time) {
		Vector2D speedVector = object.getSpeed().add(gravity.multiply(time));

		int a = object.getMagnetState();
		if (a != 0) {
			Vector2D magnetism = getAccelerationAt(level, object.getPosition()).multiply(time);
			if (a < 0) {
				magnetism = magnetism.multiply(-1);
			}
			speedVector = speedVector.add(magnetism);
		}

		Collision collision = detectCollisions(level, object, speedVector.multiply(time));
		if (collision != null) {
			collision.move(object, time);
			return true;
		} else {
			object.move(speedVector, time);
			return false;
		}

	}

	public static Vector2D getAccelerationAt(Level level, Vector2D position) {
		Vector2D force = new Vector2D(0, 0);

		for (LevelObject levelObject : level.getObjects()) {
			Vector2D connection = levelObject.getMiddle().multiply(-1).add(position);
			force = force.add(connection.normalize().multiply(levelObject.getStrength()).multiply(1.0/(Math.pow(connection.norm(), 2))));
		}

		return force;
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
