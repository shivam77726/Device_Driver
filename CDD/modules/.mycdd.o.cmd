savedcmd_/root/CDD_1/mycdd.o := ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o /root/CDD_1/mycdd.o @/root/CDD_1/mycdd.mod  ; ./tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --ibt --orc --retpoline --rethunk --sls --static-call --uaccess --prefix=16  --link  --module /root/CDD_1/mycdd.o

/root/CDD_1/mycdd.o: $(wildcard ./tools/objtool/objtool)
