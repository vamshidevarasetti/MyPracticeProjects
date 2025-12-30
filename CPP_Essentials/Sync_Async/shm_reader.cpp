#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(){
	const char* name = "/my_shm";
	int shm_fd = shm_open(name, O_RDONLY, 0666);
	
	int *ptr = static_cast <int*> (mmap(0, sizeof(int), PROT_READ, MAP_SHARED, shm_fd, 0));
	
	std::cout << "Reader: read value = " << *ptr << "\n";
	
	munmap (ptr, sizeof(int));
	close (shm_fd);
	shm_unlink(name);
	return 0;
}
	
