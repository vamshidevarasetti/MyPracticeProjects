#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;

int main(){
	const char* name = "/my_shm";
	int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, sizeof(int));
	
	int *ptr = static_cast <int*> (mmap(0, sizeof(int), PROT_WRITE, MAP_SHARED, shm_fd, 0));
	*ptr = 42;
	
	std::cout << "Writer: wrote 42 to shared memory\n" <<std::endl;
	
	munmap (ptr, sizeof(int));
	close (shm_fd);
	return 0;
}
	
