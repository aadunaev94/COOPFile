
#ifndef X4T3A_FILE_HEADER_GUARD
#	define X4T3A_FILE_HEADER_GUARD

/*================================================================================================*/

#	include <stdio.h>

/*================================================================================================*/

struct __x4t_file;

void   x4t_file_ctor (struct __x4t_file* this, const char* file_path, const char* mode);
size_t x4t_file_write(struct __x4t_file* this, const void* buf, size_t el_sz, size_t buf_sz);
void   x4t_file_dtor (struct __x4t_file* this);

/*================================================================================================*/

enum X4T_FILE_STATUS {
	X4T_FS_OK,
	X4T_FS_OPEN_ERR,
	X4T_FS_ENUM_SIZE
};

typedef struct __x4t_file {
	struct {
		void   (*ctor) (struct __x4t_file* this,
				const char* file_path, const char* mode);
		size_t (*write)(struct __x4t_file* this,
				const void* buf, size_t el_sz, size_t buf_sz);
		void   (*dtor) (struct __x4t_file* this);
	} methods;
	struct {
		FILE* file_handle;
		int status;
	} data;
} X4T_FILE, *X4T_FILE_PTR;

/*================================================================================================*/

#define X4T_INIT(obj_name, ...) X4T_FILE obj_name; x4t_file_ctor(&obj_name, ##__VA_ARGS__)
#define X4T_METH(meth, obj, ...) obj.methods.meth(&obj, ##__VA_ARGS__)

/*================================================================================================*/

#endif


