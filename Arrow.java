package dessin;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.geom.*;

import javax.swing.*;
import javax.swing.event.*;

import java.util.*;


// classe de l'ecran de l'application
class Ecran extends JPanel {
	static final int WIDTH  = 600;
	static final int HEIGHT = 400;

	static final Color couleurBord = Color.red;
	static final Color couleurInterieur = Color.blue;
	static final Color couleurFond = Color.black;

	int a, b;
    int xArrow[];
    int yArrow[];
    private Polygon poly;

	Ecran() { 
		xArrow = new int[7];
		yArrow = new int[7];
		poly = new Polygon(xArrow, yArrow, 7);
		setPreferredSize(new Dimension(WIDTH, HEIGHT));
	}

	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;
		super.paintComponent(g2); 
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
		g2.drawPolygon(poly);
	}
	
	public void init_a_b(int a, int b){
		this.a = a;
		this.b = b;
	}
	
	public void dessiner(int x, int y){
		xArrow[0] = (a+x)/2;
		xArrow[1] = a; 
		xArrow[2] = (a+x)/2;
		xArrow[3] = (a+x)/2;
		xArrow[4] = x;
		xArrow[5] = x;
		xArrow[6] =(a+x)/2;

		yArrow[0] = b;
		yArrow[1] = (b+y)/2; 
		yArrow[2] = y;
		yArrow[3] = (b + 3*y)/4;
		yArrow[4] = (b + 3*y)/4;
		yArrow[5] = (y + 3*b)/4;
		yArrow[6] = (y + 3*b)/4;

        poly = new Polygon(xArrow, yArrow, 7);		
	}
}

class Controller extends MouseInputAdapter implements ActionListener {
	static final int ENTREE = 0, REMPL = 1;
	Ecran ecran;
	int x0, y0, xc, yc;    
	int mode;
	Controller(Ecran ecran) {
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

public class Arrow{
	public static void main(String[] args) {
		Ecran ecran = new Ecran();	
		Controller controller = new Controller(ecran);
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
