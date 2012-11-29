#load "graphics.cma";; (* '#' nécessaire*)
open Graphics;;

let rec boucle e=
  boucle e
;;

let getX t = match t with
  | (x,y) -> x
;;

let getY t = match t with
  | (x, y) -> y
;;

let getCoord u v = 
(
  (
    (
      (getX u) + (getX v)
    )/2
  ),
  (
    (getY u)+(getY v)
  )/2
);;

let triangle p1 p2 p3 = 
  moveto (getX p1) (getY p1);
  lineto (getX p2) (getY p2); lineto  (getX p3) (getY p3); lineto (getX p1) (getY p1)
;;

let rec dessiner p1 p2 p3 i=
  triangle p1 p2 p3;
  if (i > 0) then
    dessiner p1 (getCoord p1 p2) (getCoord p3 p1) (i-1);
  if (i > 0) then
    dessiner (getCoord p1 p2) p2 (getCoord p2 p3) (i-1);
  if ( i > 0) then
    dessiner (getCoord p3 p1) (getCoord p2 p3) p3 (i-1)
;;

let a = ( 0, 0);;
let b = ( 250, 500);;
let c = ( 500, 0);;
open_graph " 500x500";;
dessiner (0,0) (250,500) (500,0) 8;;
boucle 0;;
