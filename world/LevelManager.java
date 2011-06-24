/**
 * 
 */
package world;

import java.io.File;
import java.io.FileFilter;
import java.util.Arrays;

/**
 * @author moritz
 *
 */
public final class LevelManager {
	
	private static Level[] levels = null;
	
	/**
	 * Loads level data and initializes the levels.
	 * 
	 * @param sourceDir Level data directory
	 */
	public static void loadLevels(String sourceDir) {
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
		levels = new Level[files.length];
		if (levels.length == 0) {
			throw new IllegalStateException("No level files found.");
		}
		Arrays.sort(levels); // get levels in the right order
		
		for (int i = 0; i < files.length; i++) {
			levels[i] = new Level(files[i]);
		}
	}
	
	public static Level getLevel(int id) {
		if (levels == null) {
			throw new IllegalStateException("No levels loaded yet.");
		} else if (id < 0 || id >= levels.length) {
			throw new IllegalArgumentException("Illegal level ID.");
		}
		
		return levels[id];
	}
}
