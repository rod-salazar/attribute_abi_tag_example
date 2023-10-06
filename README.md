# attribute_abi_tag_example
An example of attribute(abi_tag(...))

If 2 translation units compile the same inline function, they must contain the same definitions token-for-token to avoid an ODR violation.

If a program is linked together with multiple versions of the same library where ABI breaking changes were made to inline functions between versions, this results in an ODR violation.

For example if there is inconsistent usage of libc++ versions across libraries which are being linked into a single binary.

By attaching an attribute(abi_tag(...)) with an abi version string, the function symbol name is mangled to a symbol name containg the abi_tag. This avoids the ODR violation.

libc++ uses this approach to change inline function definitions without the risk of introducing ODR violations.
See https://github.com/llvm/llvm-project/blob/be382de0596d5d2c7a7ee7363bbb499df731acc6/libcxx/include/__config#L744
