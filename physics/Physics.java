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
	 * @param destinations Destinations to check for
	 * @param ball Ball to move
	 * @param time Time that has passed since the last update
	 * @return Whether a collision has occurred
	 */
	public static CollisionState move(List<LevelObject> levelObjects, List<LevelObject> destinations, Ball ball, long time) {
		Vector2D speedVector = ball.getSpeed().add(gravity.multiply(time));

		int a = ball.getMagnetState();
		if (a != 0) {
			Vector2D magnetism = getAccelerationAt(levelObjects, ball.getPosition()).multiply(time);
			if (a < 0) {
				magnetism = magnetism.multiply(-1);
			}
			speedVector = speedVector.add(magnetism);
		}
		ball.setSpeed(speedVector);

		return detectCollisions(levelObjects, destinations, ball, speedVector.multiply(time));

	}

	public static Vector2D getAccelerationAt(List<LevelObject> levelObjects, Vector2D position) {
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
	private static CollisionState detectCollisions(List<LevelObject> levelObjects, List<LevelObject> destinations, MovingObject object, Vector2D direction) {
		int radius = object.getCollisionRadius();

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

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getY() <= ury && tmpCollPoint.getY() >= lly) {
					a = tmpA;
					wall = new Vector2D(0, 1);
				}
			}

			tmpA = (urx - object.getPosition().getX()) / direction.getX();

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getY() <= ury && tmpCollPoint.getY() >= lly) {
					a = tmpA;
					wall = new Vector2D(0, 1);
				}
			}

			tmpA = (lly - object.getPosition().getY()) / direction.getY();

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getX() <= urx && tmpCollPoint.getX() >= llx) {
					a = tmpA;
					wall = new Vector2D(1, 0);
				}
			}

			tmpA = (ury - object.getPosition().getY()) / direction.getY();

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getX() <= urx && tmpCollPoint.getX() >= llx) {
					a = tmpA;
					wall = new Vector2D(1, 0);
				}
			}
		}
		
		for (LevelObject destination : destinations) {

			llx = destination.getLlx() - radius;
			lly = destination.getLly() - radius;
			urx = destination.getUrx() + radius;
			ury = destination.getUry() + radius;

			tmpA = (llx - object.getPosition().getX()) / direction.getX();

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getY() <= ury && tmpCollPoint.getY() >= lly) {
					return CollisionState.COLLISION_WITH_DESTINATION;
				}
			}

			tmpA = (urx - object.getPosition().getX()) / direction.getX();

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getY() <= ury && tmpCollPoint.getY() >= lly) {
					return CollisionState.COLLISION_WITH_DESTINATION;
				}
			}

			tmpA = (lly - object.getPosition().getY()) / direction.getY();

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getX() <= urx && tmpCollPoint.getX() >= llx) {
					return CollisionState.COLLISION_WITH_DESTINATION;
				}
			}

			tmpA = (ury - object.getPosition().getY()) / direction.getY();

			if (tmpA > 0 && tmpA < a) {
				Vector2D tmpCollPoint = object.getPosition().add(direction.multiply(tmpA));
				if (tmpCollPoint.getX() <= urx && tmpCollPoint.getX() >= llx) {
					return CollisionState.COLLISION_WITH_DESTINATION;
				}
			}
		}

		if (wall != null) {
			object.setPosition(object.getPosition().add(direction.multiply(a)));
			detectCollisions(levelObjects, destinations, object, direction.reflectAt(wall).multiply(1.0-a));
			object.setSpeed(object.getSpeed().multiply(0.98));
			
			return CollisionState.COLLISION;
		}

		object.setPosition(object.getPosition().add(direction));
		object.setSpeed((direction.normalize()).multiply(object.getSpeed().norm()));
		return CollisionState.NO_COLLISION;
	}
}