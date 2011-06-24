/**
 * @author moritz
 */
package world;

/**
 * A rectangular object in a {@link Level}.
 */
public class LevelObject implements Comparable<LevelObject> {
	private static final int DEFAULT_STRENGTH = 0;
	
	private long llx; // lower left corner x coordinate
	private long lly; // lower left corner y coordinate
	private long urx; // upper right corner x coordinate
	private long ury; // upper right corner y coordinate
	private int strength;
	/*
	 * TODO: Find a good way to do subclassing via a getInstance() method instead of storing the type.
	 * Alternative: Read from config file.
	 */
	private Type type; // type determining the physical properties of the object
	
	/**
	 * Constructs a new LevelObject with the given properties.
	 * 
	 * @param llx x coordinate of the lower left corner
	 * @param lly y coordinate of the lower left corner
	 * @param urx x coordinate of the upper right corner
	 * @param ury y coordinate of the upper right corner
	 * @param type {@link Type} of the object (determines physical values)
	 */
	public LevelObject(long llx, long lly, long urx, long ury, Type type) {
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
	 * @param type {@link Type} of the object (determines physical values)
	 */
	public LevelObject(long llx, long lly, long urx, long ury, int strength, Type type) {
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
		return this.urx - this.llx;
	}
	
	/**
	 * @return y size of the block
	 */
	public long getYSize() {
		return this.ury - this.lly;
	}
	
	/**
	 * @return Magnet strength
	 */
	public int getStrength() {
		return this.strength;
	}

	@Override
	public int compareTo(LevelObject object) {
		if (object == null) {
			throw new NullPointerException();
		}
		
		return Long.signum(this.llx - object.llx); // conversion to int might produce overflows (?)
	}
}
