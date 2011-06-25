/*
 * The Main Class to handle playing any concrete level
 */

package mechanics;

import java.util.ArrayList;
import java.util.List;
import org.lwjgl.input.Keyboard;
import org.newdawn.slick.AppGameContainer;
import org.newdawn.slick.BasicGame;
import org.newdawn.slick.Color;
import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.Image;
import org.newdawn.slick.Input;
import org.newdawn.slick.Music;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.Sound;
import org.newdawn.slick.geom.Ellipse;
import org.newdawn.slick.geom.Rectangle;

import physics.CollisionState;
import physics.Physics;
import physics.Vector2D;

import world.Level;
import world.LevelManager;
import world.LevelObject;

/**
 *
 * @author S.D.Eagle
 * @author Guybrush
 */
public class Game extends BasicGame {

	Music sMusic;
	Sound sDeath;
	Sound sPlong;

	private static final char KEY_POSITIVE = Keyboard.KEY_P;
	private static final char KEY_NEGATIVE = Keyboard.KEY_M;
	private static final char KEY_RESET = Keyboard.KEY_R;

	private Ball            ball;
	private Level           level;
	private LevelManager    levelManager;
	List<LevelObject>		destinations;
	List<LevelObject>       objects;
	private CollisionState	currentState;
	private Vector2D        camera; // Nullpunkt: Halbe Containerhöhe, halbe Containerbreite

	public Game() {
		super("Mosod");
	}

	public Level getLevel() {
		return level;
	}

	/* (non-Javadoc)
	 * @see org.newdawn.slick.BasicGame#init(org.newdawn.slick.GameContainer)
	 */
	@Override
	public void init(GameContainer container) throws SlickException {
		try {
			sMusic = new Music("media/R 22.wav");
			sDeath = new Sound("media/death.wav");
			sPlong = new Sound("media/plong.wav");
		} catch (SlickException e) {
			e.printStackTrace();
		}

		sMusic.loop(1f, 0.25f);
		ball = new Ball(new Vector2D(100.0, 700.0), 25);
		camera = ball.getPosition().deepCopy();
		ball.setSpeed(new Vector2D(0.2, 0.0));
		levelManager = new LevelManager("data");
		level = levelManager.getLevel(0);
		destinations = new ArrayList<LevelObject>();
		destinations.add(level.getDestination());
		objects = level.getObjects();
	}

	/* (non-Javadoc)
	 * @see org.newdawn.slick.BasicGame#update(org.newdawn.slick.GameContainer, int)
	 */
	@Override
	public void update(GameContainer container, int delta) throws SlickException {

		this.handleInput(container.getInput());
		
		currentState = Physics.move(objects, destinations, ball, delta);

		if (currentState == CollisionState.COLLISION) {
			// Play sound on collision
			sPlong.play(1f, 1f);
		} else if (currentState == CollisionState.COLLISION_WITH_DESTINATION) {
			reset();
			return;
		}

		if (ball.getPosition().getX() - camera.getX() > container.getWidth() * 2 / 3) {
			camera.setX(ball.getPosition().getX() - container.getWidth() * 2 / 3);
		} else if (ball.getPosition().getX() - camera.getX() < container.getWidth() / 3) {
			camera.setX(ball.getPosition().getX() - container.getWidth() / 3);
		}
		camera.setY(ball.getPosition().getY() - container.getHeight() / 2);

		if (camera.getX() < 0) {
			camera.setX(0);
		}
		if (camera.getX() > level.getWidth() - container.getWidth()) {
			camera.setX(level.getWidth() - container.getWidth());
		}
		if (camera.getY() < 0) {
			camera.setY(0);
		}
		if (camera.getY() > level.getHeight() - container.getHeight()) {
			camera.setY(level.getHeight() - container.getHeight());
		}
	}

	/* (non-Javadoc)
	 * @see org.newdawn.slick.Game#render(org.newdawn.slick.GameContainer, org.newdawn.slick.Graphics)
	 */
	@Override
	public void render(GameContainer container, Graphics g) throws SlickException {
		Image ballImage = ball.getImage();

		ballImage.draw((float) (ball.getPosition().getX() - camera.getX() - ball.getCollisionRadius()), 
				(float) (container.getHeight() - ball.getPosition().getY() + camera.getY() - ball.getCollisionRadius()));

		if (ball.getMagnetState() > 0) {
			g.setColor(new Color(193, 0, 0, 150));             
		} else if (ball.getMagnetState() < 0) {
			g.setColor(new Color(0, 21, 142, 150));
		} else {
			g.setColor(new Color(0, 0, 0, 0)); 
		}

		Ellipse ballColorOverlay = new Ellipse(
				(float) (ball.getPosition().getX() - camera.getX() - ball.getCollisionRadius()) + (ballImage.getHeight() / 2),
				(float) (container.getHeight() - ball.getPosition().getY() + camera.getY() - ball.getCollisionRadius() + (ballImage.getWidth() / 2)),
				ball.getCollisionRadius(), 
				ball.getCollisionRadius()
		);

		g.fill(ballColorOverlay);

		for (LevelObject object : objects) {
			g.setColor(Color.darkGray);
			if (object.isPositive()) {
				g.setColor(new Color(193, 0, 0, 200));
			} else if (object.isNegative()) {
				g.setColor(new Color(0, 21, 142, 200));
			}
			Rectangle rect = new Rectangle((float) (object.getLlx() - camera.getX()),
					(float) (container.getHeight() - object.getLly() + camera.getY()),
					(float) object.getXSize(),
					-1 * (float) object.getYSize());
			g.fill(rect);
		}
	}

	/*
	 * React to input
	 */
	private void handleInput(Input input) {
		if (input.isKeyDown(KEY_POSITIVE)) {
			if (input.isKeyDown(KEY_NEGATIVE)) {
				ball.setMagnetState(0);
			} else {
				ball.setMagnetState(1);
			}
		} else if (input.isKeyDown(KEY_NEGATIVE)) {
			ball.setMagnetState(-1);
		} else {
			ball.setMagnetState(0);
		}
		
		if (input.isKeyDown(KEY_RESET)) {
			reset();
		}
	}
	
	private void reset() {
		ball.setPosition(new Vector2D(100.0, 700.0));
		ball.setSpeed(new Vector2D(0.2, 0.0));
	}

	public static void main(String[] args) throws SlickException {
		AppGameContainer app = new AppGameContainer(new Game());
		app.setDisplayMode(800, 600, false);
		app.start();
	}
}
