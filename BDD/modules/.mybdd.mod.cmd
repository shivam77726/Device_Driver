savedcmd_/root/BDD/mybdd.mod := printf '%s\n'   initDev.o cleanup.o | awk '!x[$$0]++ { print("/root/BDD/"$$0) }' > /root/BDD/mybdd.mod
