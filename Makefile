cc = g++
sdir = src
libdir = /usr/lib/libVNGin.a
out = bin/test.out

$(out): $(sdir)/*.cpp $(sdir)/*.hpp $(libdir)
	@$(cc) -g -o $(out) $(sdir)/*.cpp -lVNGin -lSDL2_mixer -lSDL2_image -lSDL2 -g

.PHONY: run
run: $(out) 
	@ ./$(out)
