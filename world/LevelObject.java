/**
 * @author moritz
 */
package world;

import physics.Vector2D;

/**
 * A rectangular object in a {@link Level}.
 */
public class LevelObject implements Comparable<LevelObject> {
	private static final int DEFAULT_STRENGTH = 0;
	
	private long llx; // lower left corner x coordinate
	private long lly; // lower left corner y coordinate
	private long urx; // upper right corner x coordinate
	private long ury; // upper right corner y coordinate
	private int strength; // magnet strength (see physics)
	private ObjectAppearance type; // type determining the appearance of the object
	
	/**
	 * Constructs a new LevelObject with the given properties.
	 * 
	 * @param llx x coordinate of the lower left corner
	 * @param lly y coordinate of the lower left corner
	 * @param urx x coordinate of the upper right corner
	 * @param ury y coordinate of the upper right corner
	 * @param type {@link ObjectAppearance} of the object (determines looks)
	 */
	public LevelObject(long llx, long lly, long urx, long ury, ObjectAppearance type) {
		if (llx >= urx || lly >= ury) {
			throw new IllegalArgumentException("Upper right corner is not above and right of lower left corner.");
		}
		
		this.llx = llx;
		this.lly = lly;
		this.urx = urx;
		this.ury = ury;
		this.strength = DEFAULT_STRENGTH;
		this.type =  type;
	}
	
	/**
	 * Constructs a new LevelObject with the given properties.
	 * 
	 * @param llx x coordinate of the lower left corner
	 * @param lly y coordinate of the lower left corner
	 * @param urx x coordinate of the upper right corner
	 * @param ury y coordinate of the upper right corner
	 * @param strength Magnet strength
	 * @param type {@link ObjectAppearance} of the object (determines looks)
	 */
	public LevelObject(long llx, long lly, long urx, long ury, int strength, ObjectAppearance type) {
		if (llx >= urx || lly >= ury) {
			throw new IllegalArgumentException("Upper right corner is not above and right of lower left corner.");
		}
		
		this.llx = llx;
		this.lly = lly;
		this.urx = urx;
		this.ury = ury;
		this.strength = strength;
		this.type =  type;
	}
	
	/**
	 * @return x size of the block
	 */
	public long getXSize() {
		return this.getUrx() - this.getLlx();
	}
	
	/**
	 * @return y size of the block
	 */
	public long getYSize() {
		return this.getUry() - this.getLly();
	}
	
	/**
	 * @return Upper left corner vector
	 */
	public Vector2D getUpperLeft() {
		return new Vector2D(this.llx, this.ury);
	}
	
	/**
	 * @return Lower left corner vector
	 */
	public Vector2D getLowerLeft() {
		return new Vector2D(this.llx, this.lly);
	}
	
	/**
	 * @return Middle vector
	 */
	public Vector2D getMiddle() {
		return new Vector2D((this.urx - this.llx) / 2 + this.llx, (this.ury - this.lly) / 2 + this.lly);
	}
	
	/**
	 * @return Upper right corner vector
	 */
	public Vector2D getUpperRight() {
		return new Vector2D(this.urx, this.ury);
	}
	
	/**
	 * @return Lower right corner vector
	 */
	public Vector2D getLowerRight() {
		return new Vector2D(this.urx, this.lly);
	}
	
	/**
	 * @return Magnet strength
	 */
	public int getStrength() {
		return this.strength;
	}
	
	/**
	 * @return Whether this object is a positive magnet
	 */
	public boolean isPositive() {
		return this.strength > 0;
	}
	
	/**
	 * @return Whether this object is not magnetic
	 */
	public boolean isNeutral() {
		return this.strength == 0;
	}
	
	/**
	 * @return Whether this object is a negative magnet
	 */
	public boolean isNegative() {
		return this.strength < 0;
	}

	@Override
	public int compareTo(LevelObject object) {
		if (object == null) {
			throw new NullPointerException();
		}
		
		return Long.signum(this.getLlx() - object.getLlx()); // conversion to int might produce overflows (?)
	}

    /**
     * @return the llx
     */
    public long getLlx() {
        return llx;
    }

    /**
     * @return the lly
     */
    public long getLly() {
        return lly;
    }

    /**
     * @return the urx
     */
    public long getUrx() {
        return urx;
    }

    /**
     * @return the ury
     */
    public long getUry() {
        return ury;
    }
}
