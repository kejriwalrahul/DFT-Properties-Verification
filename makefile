all: 

1a:
	reset
	gcc code/gen.c -o bin/gen.o -lm
	bin/gen.o 

1b: plot
	bin/ComputeFFT data/sig1.dat 10 1024 data/spec1.dat
	bin/ComputeFFT data/sig2.dat 10 1024 data/spec2.dat
	bin/plotter.o data/spec1.dat 1 data/Spectrum-1 4000
	bin/plotter.o data/spec2.dat 1 data/Spectrum-2 4000

2a: plot
	gcc code/add.c -o bin/add.o
	bin/add.o data/sig1.dat data/sig2.dat data/add.dat
	bin/ComputeFFT data/add.dat 10 1024 data/spec_add.dat
	bin/plotter.o data/spec_add.dat 1 Spectrum_added
	bin/plotter.o data/add.dat 1 added

2b: plot
	gcc code/convolve.c -o bin/convolve.o
	bin/convolve.o data/sig1.dat data/sig2.dat data/convolved.dat
	bin/ComputeFFT data/convolved.dat 11 2048 data/convolved_spec.dat
	bin/plotter.o data/convolved_spec.dat 1 Spectrum_Convolved
	bin/plotter.o data/convolved.dat 1 Convolved

2d: plot
	gcc code/props.c -o bin/props.o
	bin/props.o data/sig1.dat data/spec1.dat data/sig_shift.dat
	bin/ComputeFFT data/sig_shift.dat 10 1024 data/spec_shift.dat
	bin/plotter.o data/spec1.dat 1 Spectrum-1
	bin/plotter.o data/spec_shift.dat 1 Spectrum-Shift

pad:
	gcc code/padding.c -o bin/padding.o
	bin/padding.o data/sig1.dat data/sig2.dat

plot: plot 
	reset
	gcc -g code/plotter.c -o bin/plotter.o
	
plt: plot
	./plotter.o $(file) 1 Plot

gen.o:	
	gcc -g gen.c -o gen.o -lm	

del:
	rm *.dat