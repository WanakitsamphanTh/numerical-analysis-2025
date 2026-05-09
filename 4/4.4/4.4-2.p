set terminal png
set output "4.4-2.png"

set logscale xy 10
set format x "10^{%L}"
set format y "10^{%L}"

set xlabel "h"
set ylabel "Error"

set key right bottom

plot "euler-error.dat" using 1:4 with line title "Euler error", "runge-error.dat" using 1:4 with line title "Runge error", "heun-error.dat" using 1:4 with line title "Heun error"