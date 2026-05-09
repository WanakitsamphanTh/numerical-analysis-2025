set terminal png
set output "4.4-1-error.png"
set yrange [1e-7:1]

set logscale y 10
set format y "10^{%L}"

set key right bottom

set xlabel "x"
set ylabel "Error"

plot "euler.dat" using 1:4 with line title "Euler error", "runge.dat" using 1:4 with line title "Runge error", "heun.dat" using 1:4 with line title "Heun error"