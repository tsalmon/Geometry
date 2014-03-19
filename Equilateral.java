
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.geom.*;

import javax.swing.*;
import javax.swing.event.*;

import java.util.*;


// classe de l'ecran de l'application
class EcranEquilateral extends JPanel {
	static final int WIDTH  = 600;
	static final int HEIGHT = 400;

	static final Color couleurBord = Color.red;
	static final Color couleurInterieur = Color.blue;
	static final Color couleurFond = Color.black;

	int a, b;
    int xEquilateral[];
    int yEquilateral[];
    private Polygon poly;


	EcranEquilateral() { 
		xEquilateral = new int[3];
		yEquilateral = new int[3];
		poly = new Polygon(xEquilateral, yEquilateral, 3);
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
		double angle = Math.toRadians(60);

		xEquilateral[0] = a;
		xEquilateral[1] = x;
		xEquilateral[2] = (int)((Math.cos(angle) * ((a-x)) - Math.sin(angle) * ((b-y))) + x);

		yEquilateral[0] = b;
		yEquilateral[1] = y;
		yEquilateral[2] = (int)((Math.sin(angle) * ((a-x)) + Math.cos(angle) * ((b-y))) + y);
			
        poly = new Polygon(xEquilateral, yEquilateral, 3);
	}
}

class ControllerEquilateral extends MouseInputAdapter implements ActionListener {
	static final int ENTREE = 0, REMPL = 1;
	EcranEquilateral ecran;
	int x0, y0, xc, yc;    
	int mode;
	ControllerEquilateral(EcranEquilateral ecran) {
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

public class Equilateral{
	public static void main(String[] args) {
		EcranEquilateral ecran = new EcranEquilateral();	
		ControllerEquilateral controller = new ControllerEquilateral(ecran);
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
