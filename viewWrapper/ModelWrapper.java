/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package viewWrapper;

import org.newdawn.slick.Graphics;
import org.newdawn.slick.Image;
import org.newdawn.slick.SlickException;
import world.LevelObject;

/**
 *
 * @author Jonathan
 */
public class ModelWrapper {
    
    private LevelObject object;
    
    public ModelWrapper (LevelObject object) {
        this.object = object;
    }
    
    public void display() throws SlickException {
        Image texture = null;
        
        switch (this.object.getObjectAppearance()) {
            case STANDARD_BLOCK: 
                texture = new Image("medien/thing1.png");
                break;
            case BALL: 
                texture = new Image("medien/ball3.png");
                break;
        }
        
        texture.draw((float) this.object.getUpperLeft().getX(), (float) this.object.getUpperLeft().getY());
    }
}
