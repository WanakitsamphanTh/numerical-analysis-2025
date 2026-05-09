set datafile separator whitespace

set terminal png
set output "kosatu.png"

set logscale x 10
set format x "10^{%L}"

set logscale y 10
set format y "10^{%L}"

set xlabel "Number of iteration"
set ylabel "Error |pi - M_PI|"

plot "kosatu.tsv" using 1:3 with line title "Error", "kosatu.tsv" using 1:4 with line title "Error Bound"