from Tkinter import *

def dessiner(dessin, d, n, i):
	if( i > 0):
		aux = (d+n)/2
		dessin.create_rectangle(d, d, n, n, outline="white", fill="white")
		# Haut gauche
		points = [d, d, d, aux, aux, d, aux, aux]
		dessin.create_polygon(points)
		#Bas droite
		points = [aux, aux, aux, n, n, aux, n, n]
		dessin.create_polygon(points,fill="cyan")
		#Haut droite 
		points = [aux, d, n, d, aux, aux, n, aux]
		dessin.create_polygon(points,fill="blue")
		#Bas gauche 
		points = [d, aux, aux, aux, d, n, aux, n]
		dessin.create_polygon(points,fil="red")
		print("d: "+str(d)+", "+"n: "+str(n))
		print((d+n)/4,(d+n)/4+(d+n)/2)
		dessiner(dessin,(d+n/2)/2,(d+n/2)/2+n/2,i-1) 

if __name__ == '__main__':
	Fenetre = Tk()
	dessin = Canvas(Fenetre, width = 500, height = 500)
	dessin.create_line(0,250,500,250)
	dessin.create_line(250,0,250,500)
	dessin.pack()
	dessiner(dessin, 0, 500, 5)
	Fenetre.title("Salmon carpet")
	Fenetre.mainloop()

