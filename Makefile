loadsave_pgm: loadsave_pgm_main.o loadsave_pgm_f.o
	cc -o loadsave_pgm loadsave_pgm_main.o loadsave_pgm_f.o

.c.o:
	cc -c $<

loadsave_pgm_main.o: loadsave_pgm.h

run_ascii: loadsave_pgm
	./loadsave_pgm checker4x4_ascii.pgm

run_binary: loadsave_pgm
	./loadsave_pgm checker4x4_binary.pgm

clean:
	rm -f *.o
