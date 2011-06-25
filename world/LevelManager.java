/**
 * @author moritz
 */
package world;

import java.io.File;
import java.io.FileFilter;
import java.util.Arrays;

/**
 * Reads the level data and creates {@link Level}s
 */
public final class LevelManager {
	
	private Level[] levels = null;
	
	/**
	 * Loads level data and initializes the levels.
	 * 
	 * @param sourceDir Level data directory
	 */
	public LevelManager(String sourceDir) {
		// Scans SOURCE_DIR for files ending with ".level"
		File directory = new File(sourceDir);
		if (!directory.isDirectory()) {
			System.err.println(directory.getAbsolutePath());
			throw new IllegalArgumentException("The given source directory does not exist.");
		}
		
		FileFilter filter = new FileFilter() {
			@Override
			public boolean accept(File f) {
				return f.getName().endsWith(".level");
			}
		};
		
		File[] files = directory.listFiles(filter);
		this.levels = new Level[files.length];
		if (this.levels.length == 0) {
			throw new IllegalStateException("No level files found.");
		}
		Arrays.sort(this.levels); // get levels in the right order
		
		for (int i = 0; i < files.length; i++) {
			this.levels[i] = new Level(files[i]);
		}
	}
	
	/**
	 * @param id Level number
	 * @return The level with the specified number
	 */
	public Level getLevel(int id) {
		if (this.levels == null) {
			throw new IllegalStateException("No levels loaded yet.");
		} else if (id < 0 || id >= this.levels.length) {
			throw new IllegalArgumentException("Illegal level ID.");
		}
		
		return this.levels[id];
	}
	
	/**
	 * @return Number of Levels
	 */
	public int levelCount() {
		if (this.levels == null) {
			throw new IllegalStateException("No levels loaded yet.");
		}
		
		return this.levels.length;
	}
}
