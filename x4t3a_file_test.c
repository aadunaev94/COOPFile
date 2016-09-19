
#include "x4t3a_file.h"

/*================================================================================================*/

int
main()
{
	const char msg[] = "hey!";
	X4T_INIT(file, "file.txt", "w");
	X4T_METH(write, file, msg, sizeof(*msg), sizeof(msg));
	X4T_METH(dtor, file);
	return 0;
}

/*================================================================================================*/


