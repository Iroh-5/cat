#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv)
{
    size_t const buffer_size = 256;
    char buffer[buffer_size];

    if (argc == 1)
    {
	while (fgets(buffer, buffer_size, stdin))
	    fputs(buffer, stdout);
    }
    else
    {
	enum { cntlines, cnteachline, other };

	int mode = other;
	if (strcmp(argv[1], "-n") == 0)
	    mode = cntlines;
	if (strcmp(argv[1], "-ne") == 0)
	    mode = cnteachline;

	size_t linecnt = 1;

	for (size_t i = mode != other ? 2 : 1; i < argc; ++i)
	{
	    if (mode == cnteachline)
		linecnt = 1;

	    FILE* instream = fopen(argv[i], "r");

	    if (instream)
	    {
		while (fgets(buffer, buffer_size, instream))
		{
		    if (mode != other)
			printf("%4zu ", linecnt++);

		    fputs(buffer, stdout);
		}

		fclose(instream);
	    }
	    else
	    {
		fprintf(stderr, "Could not open a file \'%s\': %s\n", argv[i], strerror(errno));
		errno = 0;
	    }
	}
    }

    return EXIT_SUCCESS;
}
