savedcmd_/root/CDD_1/mycdd.mod := printf '%s\n'   initDev.o cleanup.o openDev.o releaseDev.o trimDev.o writeDev.o readDev.o | awk '!x[$$0]++ { print("/root/CDD_1/"$$0) }' > /root/CDD_1/mycdd.mod
