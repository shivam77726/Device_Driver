struct file_operations fs=
{
	open	:	openDev,
	release	:	releaseDev,
	write	:	writeDev,
	read	:	readDev
};
