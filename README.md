# generics_in_c_experiment

## What is going on?

This is just a proof of concept. Basically I wanted to create a type-generic wrapper around some type-agnostic logic. The logic itself works with just raw data and that's okay. But when we want to use such logic, it's type-agnostic API is rather uncomfortable to use. Constantly casting void pointers and other voodoo, you know? So I wanted to test out type-generic wrappers around these functions, implemented using the good ol' trusted C preprocessor.

## How does it work?

In the `storage.c` file, I've typed-out the the type-agnostic logic. It is just allocating memory and moving bytes around, nothing fancy, completely unaware of the meaning and type of the data.

Then, in `storage.h` file, you can find a type-generic wrappers around the type-agnostic functions from `storage.c`. Thanks to C preprocessor being just a "dumb" program copypasting around code with some parameters, when you provide an actual data type to the `define_storage_of_type` macro, it instantiates a full type-specific API for the internal logic. No more manual type-casting and uncomfortable pointer-passing!

## How to build?

Simple

```bash
gcc main.c storage.c -o main
```

## Notes

* As I said, this is just a proof of concept. Feel free to be inspired!
* I've ran the compiled executable through Valgrind and it should be memory safe.
