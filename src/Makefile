# Makefile
CXX=i386-elf-g++
LD=i386-elf-ld
AS=nasm

CXXFLAGS=-ffreestanding -O2 -Wall -Wextra
LDFLAGS=-T linker.ld -nostdlib

all: os-image.bin

boot.o: boot.asm
    $(AS) -f bin $< -o $@

kernel.o: kernel.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

shell.o: shell.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

login.o: login.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clock.o: clock.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

bouncingball.o: bouncingball.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

gui.o: gui.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

cursor.o: cursor.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

cursorsprite.o: cursorsprite.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

minesweeper.o: minesweeper.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

filesystem.o: filesystem.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

sheepsay.o: sheepsay.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

kernel.bin: kernel.o shell.o login.o clock.o bouncingball.o gui.o cursor.o cursorsprite.o minesweeper.o filesystem.o sheepsay.o
    $(LD) $(LDFLAGS) $^ -o $@

os-image.bin: boot.o kernel.bin
    cat $^ > $@

clean:
    rm -f *.o *.bin
