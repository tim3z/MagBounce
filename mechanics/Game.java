/*
 * The Main Class to handle playing any concrete level
 */

package mechanics;

import org.lwjgl.input.Keyboard;
import org.newdawn.slick.AppGameContainer;
import org.newdawn.slick.BasicGame;
import org.newdawn.slick.Color;
import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.Input;
import org.newdawn.slick.SlickException;

import physics.Vector2D;

import world.Level;

/**
 *
 * @author S.D.Eagle
 */
public class Game extends BasicGame {

    private long oldTime;

    private Ball ball;
    
    private static final char CHANGE_POSITIVE = Keyboard.KEY_P;
    private static final char CHANGE_NEGATIVE = Keyboard.KEY_M;

    private Level level;

    public Game() {
        super("Mobos");
    }

    public Level getLevel() {
        return level;
    }

	@Override
	public void init(GameContainer container) throws SlickException {
		ball = new Ball();
		ball.setSpeed(new Vector2D(0.0, 0.0));
	}

	@Override
	public void update(GameContainer container, int delta) throws SlickException {
		long diffTime = System.currentTimeMillis() - oldTime;
        
		this.handleInput(container.getInput());
		
		//physics.Physics.move(this.getLevel(), ball, diffTime);

        oldTime += diffTime;
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
