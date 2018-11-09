all: signal.c
  gcc signal.c
run:
  ./a.out
clean:
  rm *.o
