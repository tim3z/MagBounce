/**
 * 
 */
package world;

import java.lang.reflect.Constructor;

/**
 * @author moritz
 *
 */
public class LevelObject implements Comparable<LevelObject> {
	private long llx; // lower left corner x coordinate
	private long lly; // lower left corner y coordinate
	private long urx; // upper right corner x coordinate
	private long ury; // upper right corner y coordinate
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

	@Override
	public int compareTo(LevelObject object) {
		if (object == null) {
			throw new NullPointerException();
		}
		
		return (int) (this.llx - object.llx);
	}
}
