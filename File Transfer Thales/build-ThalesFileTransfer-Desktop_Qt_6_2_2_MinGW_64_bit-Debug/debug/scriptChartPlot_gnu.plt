set boxwidth 0.5
set style fill solid
plot "FileTransferChartData.txt" using 1:3:xtic(2) with boxes
 