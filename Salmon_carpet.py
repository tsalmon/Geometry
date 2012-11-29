from Tkinter import *

def draw(draw, d, n, i):
	if( i > 0):
		aux = (d+n)/2
		drawing.create_rectangle(d, d, n, n, outline="white", fill="white")
		# top left
		points = [d, d, d, aux, aux, d, aux, aux]
		drawing.create_polygon(points)
		#down right
		points = [aux, aux, aux, n, n, aux, n, n]
		drawing.create_polygon(points)
		#up right 
		points = [aux, d, n, d, aux, aux, n, aux]
		drawing.create_polygon(points)
		#down left 
		points = [d, aux, aux, aux, d, n, aux, n]
		drawing.create_polygon(points)
		draw(drawing, (d+500/2)/2, (500/2+n)/2,i-1) 

if __name__ == '__main__':
	Root = Tk()
	drawing = Canvas(Root, width = 500, height = 500)
	drawing.pack()
	draw(drawing, 0, 500, 5)
	Root.title("Salmon carpet")
	Root.mainloop()

