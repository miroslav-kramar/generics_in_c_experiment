# generics_in_c_experiment

## What is going on?

This is just a proof of concept. Feel free to be inspired!

Creating a type-agnostic logic in C is usually no big deal and the standard library and the language itself both provide solid tools like void pointers and functions like `memcpy` and so on.

But to use such type-agnostic logic, we unfortunately have to deal with its type-agnostic API, which is usually rather uncomfortable to use. Just to pass a value to such functions is virtually impossible without first creating some storage object and then passing its pointer to said functions.

But there is a solution! Maybe C doesn't have type-genericity and templates out of the box, but that is not stopping us from simulating them. And how else but with the good ol' trusty C preprocessor!

## How does it work?

The type-agnostic logic written in the `storage.c` file is super simple in this case. We have a struct which holds a void pointer to dynamically allocated memory and it's size in bytes. And a set of functions to create, write, read and destroy said memory. And since the whole thing is type-agnostic, so are the functions and their arguments.

But here comes the C preprocessor.

As you may see in the `storage.h` file, we first specify the function primitives of the type-agnostic functions mentioned above in order to be able to use them. And then comes the preprocessor magic. You can see there is a macro `define_storage_of_type(type)`. Inside the macro there are the type-generic wrappers. 

The macro first specifies a typedef of the base `storage_t` by prepending the type to it using `##`, which is the way how text is appended, prepended or otherwise joined with other text in the preprocessor.

Then there are the wrappers. Their names are created in the same way as the storage type. But more interesting is what the `type` thingy allows us to do. We can create a generic storage object, a function argument in this case and take it's size and pointer and pass it to the type-agnostic functions! And that's about it.

Okay, but how does this actually work?

The C preprocessor, from the whole suite of tools involved in the process of converting C code into an executable program, is perhaps the simplest. It doesn't know anything about keywords, data types and their sizes or variables and pointers to them. It just copies and pastes the text you provide it with. But it can also take in some parameters and paste them inside the prepared template. And that's how we create the type-specific wrappers around our type-agnostic functions. The preprocessor first takes the type provided and replaces every `type` word it can find inside the macro with it. And then it instantiates the whole thing inside the `main.c` file. And voila, we have successfully created very comfortable and easy to use type-specific API. And we can do this for every type we want. You may see I've already done it for `int` and `float` in the `main.c` file.

As a fun exercise, you may try to run this thing whole thing just through the preprocessor itself to see the macro unwrapped.

## What is it good for?

Great question! And the answer is just about any type-agnostic logic you may want, like `array list`, `linked list`, `hash map` and every other data structure and algorithm working with just the raw memory that would really benefit from having type-generic API.

## How to build?

Simple

```bash
gcc main.c storage.c
```

## Notes

* I've ran the compiled executable through Valgrind and it should be memory safe.
