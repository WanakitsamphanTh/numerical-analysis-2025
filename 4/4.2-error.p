set terminal png
set output "4.2-error.png"
set yrange [1e-7:1]

set logscale y 10
set format y "10^{%L}"

set encoding utf8

set xlabel "x"
set ylabel "Error"

set key right bottom

plot "euler.dat" using 1:4 with line title "Euler error", "runge.dat" using 1:4 with line title "Runge error"