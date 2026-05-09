set terminal png
set output "5.2.png"

set xrange [0:100]
set yrange [0:100]
#set zrange [-1:100]

#set logscale y 10
#set format y "10^{%L}"

set key right bottom

set xlabel "x"
set ylabel "y"
set zlabel "V"

splot "5.2.result.tsv" with line title ""