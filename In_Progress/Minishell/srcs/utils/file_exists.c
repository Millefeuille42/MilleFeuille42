#include <sys/stat.h>

char	file_exists(const char *file)
{
	struct stat	buffer;

	return ((char)(stat(file, &buffer) == 0));
}
