set terminal png
set output "4.4-1.png"

set key right bottom

set xlabel "x"
set ylabel "y"

plot "euler.dat" using 1:3 with line title "y", "euler.dat" using 1:2 with points pt 35 ps 2 title "Euler", "runge.dat" using 1:2 with points pt 32 ps 2 title "Runge", "heun.dat" using 1:2 with points pt 32 ps 2 title "Heun"