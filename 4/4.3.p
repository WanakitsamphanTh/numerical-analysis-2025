set terminal png
set output "4.3.png"

set logscale xy 10
set format x "10^{%L}"
set format y "10^{%L}"

set key right bottom

set xlabel "h"
set ylabel "Error"

plot "4.3.euler.dat" using 1:4 with line title "Euler error", "4.3.runge.dat" using 1:4 with line title "Runge error"