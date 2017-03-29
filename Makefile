GCC := gcc

build/vector: lib/vector.c lib/main.c
	mkdir -p $(@D)
	$(GCC) -o $@ $+
