file="./build/osx.bin"

if [ -f "$file" ]; then
    echo "File '$file' exists."
else
    echo "File '$file' does not exist. Creating it..."
    touch "$file"
    echo "File '$file' created."
fi

nasm -f elf32 boot.asm -o boot.o
gcc -m32 -c kernel.c -o kernel.o
gcc -m32 -c main.c -o main.o
ld -m elf_i386 -T link.ld -o ./build/osx.bin boot.o kernel.o main.o
qemu-system-x86_64 -kernel ./build/osx.bin