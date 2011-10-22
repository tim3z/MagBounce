/*
 * The Main object scrolling through our world
 */

package mechanics;

import physics.MovingObject;
import physics.Vector2D;

/**
 *
 * @author S.D.Eagle
 */
public class Ball extends MovingObject {
	private int magnetState = 0;

	public Ball(Vector2D pos, int radius) {
		super(pos, radius);
	}

	public void setMagnetState(int state) {
		assert state == 0 || state == 1 || state == -1;
		this.magnetState = state;
	}

	public int getMagnetState() {
		return magnetState;
	}

	public boolean isPositive() {
		return (this.magnetState >= 1);
	}

	public boolean isNegative() {
		return (this.magnetState <= -1);
	}
}
