/*
 * The Main object scrolling through our world
 */

package mechanics;

import physics.MovingObject;

/**
 *
 * @author S.D.Eagle
 */
public class Ball extends MovingObject {
	private int magnetState = 0;
	
	public void setMagnetState(int state) {
		assert state == 0 || state == 1 || state == -1;
		this.magnetState = state;
	}
	
	public boolean isPositive() {
		return (this.magnetState == 1);
	}
	
	public boolean isNegative() {
		return (this.magnetState == -1);
	}
}
