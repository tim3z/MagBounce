/**
 * 
 */
package world;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

/**
 * @author moritz
 *
 */
public class Level {
	private List<LevelObject> levelObjects;
	
	private long xSize;
	private long ySize;
	
	public Level(File levelFile) {
		if (levelFile == null) {
			throw new NullPointerException();
		}
		
		BufferedReader fileReader;
		String line;
		String[] levelSizeInfo;
		String[] objectInfo;
		
		try {
			fileReader =  new BufferedReader(new FileReader(levelFile));
		} catch (FileNotFoundException e) {
			throw new IllegalArgumentException("File does not exist.");
		}
		
		this.levelObjects = new ArrayList<LevelObject>();
		
		try {
			// first line contains size information
			line = fileReader.readLine();
			levelSizeInfo = line.split(",");
			this.xSize = Long.parseLong(levelSizeInfo[0]);
			this.ySize = Long.parseLong(levelSizeInfo[1]);
			
			line = fileReader.readLine();
			while (line != null) {
				objectInfo = line.split(",");
				this.levelObjects.add(new LevelObject(
						Long.parseLong(objectInfo[0]),
						Long.parseLong(objectInfo[1]),
						Long.parseLong(objectInfo[2]),
						Long.parseLong(objectInfo[3]),
						Type.valueOf(objectInfo[4])
					));
				
				line = fileReader.readLine();
			}
		} catch (Exception e) { // Catch them all!
			throw new IllegalArgumentException("The given file is no valid level file.", e);
		}
	}
}
