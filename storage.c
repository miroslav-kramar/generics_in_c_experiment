#include "storage.h"
#include <stdlib.h>
#include <string.h>

struct internal_storage_t {
	void * storage;
	size_t size;
};

storage_t storage_new(const size_t size) {
	storage_t tmp;
	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL) return NULL;

	tmp->storage = malloc(size);
	if (tmp->storage == NULL) return NULL;
	tmp->size = size;

	return tmp;
}

int storage_insert(const storage_t storage, void * data) {
	if (storage == NULL || data == NULL) return 0;
	memcpy(storage->storage, data, storage->size);
	return 1;
}

void * storage_get(const storage_t storage) {
	if (storage == NULL) return NULL;
	return storage->storage;
}

int storage_destroy(const storage_t storage) {
	if (storage == NULL) return 0;
	if (storage->storage != NULL) free(storage->storage);
	free(storage);
	return 1;
}
