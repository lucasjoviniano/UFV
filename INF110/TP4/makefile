CC=g++
ARGS=-lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec
OS := $(shell uname)

ifeq ($(OS), Windows_NT)
pac-man: pac-man.cpp
	$(CC) pac-man.cpp $(ARGS) -o pacman.exe
else
pac-man: pac-man.cpp
	$(CC) pac-man.cpp $(ARGS) -o pacman.out
endif
