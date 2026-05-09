
set terminal png
set output "5.2.shusoku.png"

set logscale x 10
set format x "10^{%L}"

#set logscale y 10
#set format y "10^{%L}"

set xlabel "Number of iteration"
set ylabel "V[V]"

plot "5.2.shusoku.tsv" with line title ""