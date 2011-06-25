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
import org.newdawn.slick.Image;
import org.newdawn.slick.Input;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.geom.Rectangle;
import physics.MovingObject;

import physics.Vector2D;
import sun.java2d.loops.FillRect;

import world.Level;
import world.LevelManager;
import world.LevelObject;

/**
 *
 * @author S.D.Eagle
 */
public class Game extends BasicGame {

    private static final char CHANGE_POSITIVE = Keyboard.KEY_P;
    private static final char CHANGE_NEGATIVE = Keyboard.KEY_M;

    private long            oldTime;
    
    private Ball            ball;
    private Level           level;
    private LevelManager    levelManager;
    List<LevelObject>       objects;
    private LevelObject     testObject;
   
    public Game() {
        super("Mobos");
    }

    public Level getLevel() {
        return level;
    }

	@Override
	public void init(GameContainer container) throws SlickException {
		ball = new Ball(new Vector2D(0.0, 200.0), 30);
		ball.setSpeed(new Vector2D(0.1, 0.0));
                levelManager = new LevelManager("data");
                level = levelManager.getLevel(1);
                objects = level.getObjects();
	}

	@Override
	public void update(GameContainer container, int delta) throws SlickException {
        
            this.handleInput(container.getInput());
		
            physics.Physics.move(level, ball, delta);
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

                ball.getImage().draw((float) ball.getPosition().getX(), 600f - (float) ball.getPosition().getY());

                for (LevelObject object : objects) {
                    g.setColor(Color.darkGray);
                    if (object.isPositive()) {
                        g.setColor(Color.blue);
                    } else if (object.isNegative()) {
                        g.setColor(Color.red);
                    }
                    g.fill(new Rectangle((float) object.getLlx(), (float) (600 - object.getLly()), (float) object.getXSize(), (float) object.getYSize()));
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
