
#include "x4t3a_file.h"

/*================================================================================================*/

void
x4t_file_ctor(X4T_FILE_PTR this, const char* file_name, const char* mode)
{
	if (this) {
		this->methods.ctor  = x4t_file_ctor;
		this->methods.write = x4t_file_write;
		this->methods.dtor  = x4t_file_dtor;
		this->data.file_handle = (file_name && mode)
						? fopen(file_name, mode)
						: NULL;
		this->data.status = (this->data.file_handle != NULL)
					? X4T_FS_OK
					: X4T_FS_OPEN_ERR;
	}
}

/*================================================================================================*/

void
x4t_file_dtor(X4T_FILE_PTR this)
{
	if (this && this->data.file_handle) {
		fclose(this->data.file_handle);
		this->data.file_handle = NULL;
	}
}

/*================================================================================================*/

size_t
x4t_file_write(X4T_FILE_PTR this, const void* buf, size_t el_sz, size_t buf_sz)
{
	return (this && this->data.file_handle)
		? fwrite(buf, el_sz, buf_sz, this->data.file_handle)
		: 0;
}

/*================================================================================================*/


