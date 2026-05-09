set terminal png
set output "4.2-function.png"

set key right bottom


set xlabel "x"
set ylabel "y"

plot "euler.dat" using 1:3 with line title "y", "euler.dat" using 1:2 with points pt 35 ps 2 title "euler", "runge.dat" using 1:2 with points pt 32 ps 2 title "Runge"