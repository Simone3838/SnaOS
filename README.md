# SnaOS
An OS made in c

# features
Grub bootloader
login
basic shell
clock

# How to compile it
make sure you have:
nasm

i386-elf-g++

i386-elf-ld

grub-mkrescure

then clone the resp
```
git clone https://github.com/Simone3838/SnaOS.git
```
then after doing that, run
```
make
```

then do this commands:
```
mkdir -p isodir/boot/grub
cp kernel.bin isodir/boot/kernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o snaos.iso isodir
```

after doing that, run:
```
qemu-system-i386 -cdrom snaos.iso
```

Please give me a star
