#ifndef STORAGE_H
#define STORAGE_H

#include <stddef.h>

typedef struct internal_storage_t * storage_t;
storage_t storage_new(const size_t size);
int storage_insert(storage_t storage, void * data);
void * storage_get(storage_t storage);
int storage_destroy(storage_t storage);

#define use_storage_of_type(type) \
	typedef struct type##_storage_t { storage_t s; } type##_storage_t; \
	\
	type##_storage_t type##_storage_new() { \
		return (type##_storage_t){storage_new(sizeof(type))}; \
	} \
	\
	int type##_storage_insert(type##_storage_t storage, type data) { \
		return storage_insert(storage.s, (void *)&data); \
	} \
	\
	type type##_storage_get(type##_storage_t storage) { \
		return *(type *)storage_get(storage.s); \
	} \
	\
	int type##_storage_destroy(type##_storage_t storage) { \
		return storage_destroy(storage.s); \
	}

#endif // STORAGE_H
