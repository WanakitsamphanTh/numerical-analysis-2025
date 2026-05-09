set xrange [-5:5]
set yrange [-0.2:0.5]

set terminal png
set output "jiyu.png"


set key right bottom
#plot "jiyu.dat" using 1:2 with line title "f(x)", "jiyu.dat" using 1:3 with line title "Spline", "jiyu.dat" using 1:4 with line title "Lagrange"
plot "ref-data.dat" using 1:2 pt 31 ps 1 title "Normal Distribution", "saveed-data.dat" using 1:3 with line title "Spline", "saveed-data.dat" using 1:4 with line title "Lagrange"