/*
 * The Main Class to handle playing any concrete level
 */

package mechanics;

import java.util.List;
import org.lwjgl.input.Keyboard;
import org.newdawn.slick.AppGameContainer;
import org.newdawn.slick.BasicGame;
import org.newdawn.slick.Color;
import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.Input;
import org.newdawn.slick.Music;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.Sound;
import org.newdawn.slick.geom.Rectangle;

import physics.Vector2D;

import world.Level;
import world.LevelManager;
import world.LevelObject;

/**
 *
 * @author S.D.Eagle
 */
public class Game extends BasicGame {

    Music sMusicHigh;
    Music sMusicLow;
    Music sMusicNormal;
    Sound sDeath;
    Sound sPlong;
    
    private static final char CHANGE_POSITIVE = Keyboard.KEY_P;
    private static final char CHANGE_NEGATIVE = Keyboard.KEY_M;
    
    private Ball            ball;
    private Level           level;
    private LevelManager    levelManager;
    List<LevelObject>       objects;
    private Vector2D        camera;
   
    public Game() {
        super("Mosod");
        
        try {
            Music sMusic = new Music("media/R 22.wav");
            sMusicHigh = sMusic;
            sMusicLow = sMusic;
            sMusicNormal = sMusic;
            sDeath = new Sound("media/death.wav");
            sPlong = new Sound("media/plong.wav");
        } catch (SlickException e) {
            e.printStackTrace();
        }
        
    }

    public Level getLevel() {
        return level;
    }

	@Override
	public void init(GameContainer container) throws SlickException {
            
            sMusicHigh.loop(1.2f, 1f);
            sMusicLow.loop(0.8f, 1f);
            sMusicNormal.loop(1f, 1f);
            ball = new Ball(new Vector2D(100.0, 200.0), 30);
            camera = ball.getPosition().multiply(1); // deep copy :-D
            ball.setSpeed(new Vector2D(0.2, 0.0));
            levelManager = new LevelManager("data");
            level = levelManager.getLevel(5);
            objects = level.getObjects();
	}

	@Override
	public void update(GameContainer container, int delta) throws SlickException {
        
            this.handleInput(container.getInput());
		
            physics.Physics.move(level, ball, delta); // returns boolean for collision sound
            
            camera.setX(ball.getPosition().getX() - container.getWidth()/2);
            camera.setY(ball.getPosition().getY() - container.getHeight()/2);

            if (camera.getX() < 0) {
                camera.setX(0);
            }
            if (camera.getX() > level.getXSize() - container.getWidth()) {
                camera.setX(level.getXSize() - container.getWidth());
            }
            if (camera.getY() < 0) {
                camera.setY(0);
            }
            if (camera.getY() > level.getYSize() - container.getHeight()) {
                camera.setY(level.getYSize() - container.getHeight());
            }
            
            if (ball.getMagnetState() > 0) {
                sMusicHigh.setVolume(0f);
                sMusicLow.setVolume(1f);
                sMusicNormal.setVolume(0f);                
            } else if (ball.getMagnetState() < 0) {
                sMusicHigh.setVolume(1f);
                sMusicLow.setVolume(0f);
                sMusicNormal.setVolume(0f);                
            } else {
                sMusicHigh.setVolume(0f);
                sMusicLow.setVolume(0f);
                sMusicNormal.setVolume(1f);
            }
	}

	@Override
	public void render(GameContainer container, Graphics g) throws SlickException {

		if (this.ball.isPositive()) {
                    g.setBackground(Color.red);
		} else if (this.ball.isNegative()) {
                    g.setBackground(Color.blue);
		} else {
                    g.setBackground(Color.gray);
                }

                ball.getImage().draw((float) (ball.getPosition().getX() - camera.getX() - ball.getCollisionRadius()),
                                     (float) (container.getHeight() - ball.getPosition().getY() + camera.getY() - ball.getCollisionRadius()));

                for (LevelObject object : objects) {
                    g.setColor(Color.darkGray);
                    if (object.isPositive()) {
                        g.setColor(Color.red);
                    } else if (object.isNegative()) {
                        g.setColor(Color.blue);
                    }
                    Rectangle rect = new Rectangle((float) (object.getLlx() - camera.getX()),
                                                   (float) (container.getHeight() - object.getLly() + camera.getY()),
                                                   (float) object.getXSize(),
                                                   -1 * (float) object.getYSize());
                    g.fill(rect);
                }
	}
	
	private void handleInput(Input input) {
		if (input.isKeyDown(CHANGE_POSITIVE)) {
			if (input.isKeyDown(CHANGE_NEGATIVE)) {
				ball.setMagnetState(0);
			} else {
				ball.setMagnetState(1);
			}
		} else if (input.isKeyDown(CHANGE_NEGATIVE)) {
			ball.setMagnetState(-1);
		} else {
			ball.setMagnetState(0);
		}
	}
	
	public static void main(String[] args) throws SlickException {
		AppGameContainer app = new AppGameContainer(new Game());
		app.setDisplayMode(800, 600, false);
		app.start();
	}
}
