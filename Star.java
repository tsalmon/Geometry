import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.geom.*;

import javax.swing.*;
import javax.swing.event.*;

import java.util.*;


// classe de l'ecran de l'application
class EcranStar extends JPanel {
	static final int WIDTH  = 600;
	static final int HEIGHT = 400;

	static final Color couleurBord = Color.red;
	static final Color couleurInterieur = Color.blue;
	static final Color couleurFond = Color.black;

	int a, b;
    int xStar[];
    int yStar[];
    private Polygon poly;


	EcranStar() { 
		xStar = new int[12];
		yStar = new int[12];
		poly = new Polygon(xStar, yStar, 12);
		setPreferredSize(new Dimension(WIDTH, HEIGHT));
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g); 
        g.drawPolygon(poly);
	}
	
	public void init_a_b(int a, int b){
		this.a = a;
		this.b = b;
	}
	
	public void dessiner(int x, int y){
		xStar[0] = (a+x)/2;
		yStar[0] = b;

		xStar[10] = x;
		yStar[10] = (3*b+y)/4;
	
		xStar[2] = a;
		yStar[2] = (3*b+y)/4;
		
		xStar[1] = ((xStar[10] + xStar[2])*2)/3;
		yStar[1] = (3*b+y)/4; 
		
		xStar[3] = (xStar[1]+xStar[2])/2;
		yStar[3] = (b + y)/2;

		xStar[4] = a;
		yStar[4] = (b + 3*y)/4;

		
		xStar[6] = (a+x)/2;
		yStar[6] = y;
		
		xStar[5] = ((xStar[10] + xStar[2])*2)/3;
		yStar[5] = (b + 3*y)/4;
		

		xStar[8] = x;
		yStar[8] = (b+3*y)/4;
		
		xStar[7] = (xStar[10] + xStar[2])/3;
		yStar[7] = (b+3*y)/4; 
		
		xStar[9] = (xStar[7]+xStar[8])/2;
		yStar[9] = (b+y)/2;

		xStar[11] = (xStar[10] + xStar[2])/3;
		yStar[11] = (y+3*b)/4; 
		
        poly = new Polygon(xStar, yStar, 12);
	}
}

class ControllerStar extends MouseInputAdapter implements ActionListener {
	static final int ENTREE = 0, REMPL = 1;
	EcranStar ecran;
	int x0, y0, xc, yc;    
	int mode;
	ControllerStar(EcranStar ecran) {
		this.ecran = ecran;
	}
	public void actionPerformed(ActionEvent e) {}
	public void mousePressed(MouseEvent e) {
		ecran.init_a_b(e.getX(), e.getY());
	}
	public void mouseReleased(MouseEvent e) {
		System.out.println("Released");
	}
	public void mouseDragged (MouseEvent e) {		
		ecran.dessiner(e.getX(), e.getY());
		ecran.repaint();
	}
}

public class Star{
	public static void main(String[] args) {
		EcranStar ecran = new EcranStar();	
		ControllerStar controller = new ControllerStar(ecran);
		ecran.addMouseListener(controller);
		ecran.addMouseMotionListener(controller);
		Box box = new Box(BoxLayout.Y_AXIS);
		JFrame mainFrame = new JFrame();
		box = new Box(BoxLayout.X_AXIS);
		box.add(ecran);
		mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
		mainFrame.getContentPane().add(box);
		mainFrame.pack();
		mainFrame.setVisible(true);
	}
}
