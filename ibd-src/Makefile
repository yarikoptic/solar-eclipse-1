EXECS = domcibd ibdprep ibdmat ibdmc allfreq relate getmeans multipnt mrgibd makeped unknown genfreq #dommsibs mkibdf

all: $(EXECS)

# Mac
# Note: -finit-local-zero not available
FC=gfortran
CC=gcc
CFLAGS = -static -O2 -I../lib
FFLAGS = -O2
LDFLAGS = -static -s -O2
NOVECTOR = 
SUNMATH =
INSTALLER = cp
INSTALLER2 = ../bin

ibdprep: ibdprep.o
	$(CC) $(LDFLAGS) -o ibdprep ibdprep.o -L../lib -lsafe -lm

ibdmat: ibdmat.o
	$(CC) $(LDFLAGS) -o ibdmat ibdmat.o

ibdmc: ibdmc.o
	$(FC) $(LDFLAGS) -o ibdmc ibdmc.o

allfreq: allfreq.o fallfrq.f
	$(FC) $(LDFLAGS)  $(NOVECTOR) -o allfreq allfreq.o fallfrq.f

genfreq: allfreq.o fgenfrq.f
	$(FC) $(LDFLAGS) $(NOVECTOR) -o genfreq allfreq.o fgenfrq.f

relate: relate.o
	$(CC) $(LDFLAGS) -o relate relate.o

getmeans: getmeans.o
	$(CC) $(LDFLAGS) -o getmeans getmeans.o -L../lib -lsafe -lm

multipnt: dgedifa.o multipnt.o
	$(CC) $(LDFLAGS) -o multipnt multipnt.o dgedifa.o -L../lib -lsafe $(SUNMATH) -lm

mrgibd: mrgibd.o
	$(CC) $(LDFLAGS) -o mrgibd mrgibd.o -L../lib -lsafe

mkibdf: mkibdf.o
	$(CC) $(LDFLAGS) -o mkibdf mkibdf.o -L../lib -lsafe

makeped: makeped.c
	$(CC) -o makeped makeped.c

unknown: unknown.o
	$(CC) $(LDFLAGS) -o unknown unknown.o

install:
	for i in $(EXECS) ; do ( $(INSTALLER) $$i $(INSTALLER2) ) ; done

test:
	for i in $(EXECS) ; do ( /usr/sbin/install -f ../newbin -o $$i ) ; done

clean:
	rm -f $(EXECS) *.o
