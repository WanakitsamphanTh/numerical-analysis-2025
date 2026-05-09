set datafile separator whitespace

set terminal png
set output "5.1.png"

set logscale x 10
set format x "10^{%L}"

set logscale y 10
set format y "10^{%L}"

set xlabel "Number of iteration"
set ylabel "Error |pi - M_PI|"

plot "5.1.tsv" using 1:3 with points pt 7 title ""