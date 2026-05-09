set xrange [0:9]
set yrange [0:20]

set terminal png
set output "3.2.png"

set key right bottom
plot "3.2.dat" using 1:2 with points pt 35 title "data", "3.2.dat" using 1:3 with line title "Least Squeared Method"