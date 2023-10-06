//
// Created by Rodrigo Salazar on 10/6/23.
//

#ifndef ATTRIBUTE_ABI_TAG_EXAMPLE_H
#define ATTRIBUTE_ABI_TAG_EXAMPLE_H

struct Widget {
    int w;
#ifdef NEW_ABI
    int x;
#endif
};

// __attribute__((abi_tag(...)) will mangle the symbol name to include the tag.
// If 2 different TUs are compiled, one with the new abi and one with old, and are subsequently linked
// into the same binary, we will not have an ODR violation. Of course due to the ABI difference these 2 libraries
// will not be able to interop using the type, but they can use the library in isolation.

#ifdef NEW_ABI
__attribute__((abi_tag("new_abi")))
inline Widget create_widget() {
  return Widget();
}
#else
__attribute__((abi_tag("old_abi")))
inline Widget create_widget() {
  return Widget();
}
#endif

#endif //ATTRIBUTE_ABI_TAG_EXAMPLE_H
