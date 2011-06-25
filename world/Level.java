/**
 * @author moritz
 */
package world;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * A game level containing several {@link LevelObject}s.
 */
public class Level {
	private List<LevelObject> levelObjects;
	
	private long xSize;
	private long ySize;
	private LevelObject destination;
	
	public Level(File levelFile) {
		if (levelFile == null) {
			throw new NullPointerException();
		}
		
		BufferedReader fileReader;
		String line;
		String[] levelSizeInfo;
		String[] destinationInfo;
		String[] objectInfo;
		
		try {
			fileReader =  new BufferedReader(new FileReader(levelFile));
		} catch (FileNotFoundException e) {
			throw new IllegalArgumentException("File does not exist.");
		}
		
		this.levelObjects = new ArrayList<LevelObject>();
		
		try {
			// lines beginning with '#' are ignored
			
			// first non-comment line contains size information (width,height)
			line = fileReader.readLine();
			while (line.charAt(0) == '#') {
				line = fileReader.readLine();
			}
			levelSizeInfo = line.split(",");
			this.xSize = Long.parseLong(levelSizeInfo[0]);
			this.ySize = Long.parseLong(levelSizeInfo[1]);
			
			// second non-comment line contains the destination (llx,lly,urx,ury)
			line = fileReader.readLine();
			while (line.charAt(0) == '#') {
				line = fileReader.readLine();
			}
			destinationInfo = line.split(",");
			this.destination = new LevelObject(
					Long.parseLong(destinationInfo[0]),
					Long.parseLong(destinationInfo[1]),
					Long.parseLong(destinationInfo[2]),
					Long.parseLong(destinationInfo[3])
					// destination is non-magnetic
				);
			
			line = fileReader.readLine();
			while (line != null) {
				if (line.charAt(0) == '#') {
					line = fileReader.readLine();
					continue;
				}
				
				// subsequent lines contain object info (llx,lly,urx,ury[,magnetism])
				objectInfo = line.split(",");
				if (objectInfo.length == 4) {
					this.levelObjects.add(new LevelObject(
							Long.parseLong(objectInfo[0]),
							Long.parseLong(objectInfo[1]),
							Long.parseLong(objectInfo[2]),
							Long.parseLong(objectInfo[3])
						));
				} else if (objectInfo.length == 5) {
					this.levelObjects.add(new LevelObject(
							Long.parseLong(objectInfo[0]),
							Long.parseLong(objectInfo[1]),
							Long.parseLong(objectInfo[2]),
							Long.parseLong(objectInfo[3]),
							Integer.parseInt(objectInfo[4])
						));
				} else {
					throw new Exception("Invalid number of object properties.");
				}	
				
				line = fileReader.readLine();
			}
		} catch (Exception e) { // Catch them all!
			throw new IllegalArgumentException("The given file " + levelFile.getName() + " is no valid level file.", e);
		}
		
		// Sorting by position might help in-game performance
		Collections.sort(this.levelObjects);
	}
	
	/**
	 * @return Width of the level
	 */
	public long getWidth() {
		return this.xSize;
	}
	
	/**
	 * @return Height of the level
	 */
	public long getHeight() {
		return this.ySize;
	}
	
	/**
	 * @return The destination object
	 */
	public LevelObject getDestination() {
		return this.destination;
	}
	
	/**
	 * @return List of all objects in this level, sorted by occurrence.
	 */
	public List<LevelObject> getObjects() {
		return this.levelObjects;
	}
}
