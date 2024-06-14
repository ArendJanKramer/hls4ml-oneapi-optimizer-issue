# Disabled optimizer gives wrong model output

## Issue description
When debug mode is enabled in cmake, few build parameters are appended, as can be seen here:
https://github.com/oneapi-src/oneDNN/blob/501c471aa5337bf521266d4fe1ac3514ab2d5b83/cmake/platform.cmake#L173

This appends the following to the CXX compiler flags:
`-g -Rno-debug-disables-optimization`.

If debug mode is not set, `-g -O3` is used instead. 

Compiling with -O3, or other optimizers, work properly. 
Compiling without an optimizer and using `-Rno-debug-disables-optimization` to suppress the remark,
the binary produced does not correctly compute the model output; therefore producing a wrong model score.


## Compile instructions:
```bash
make build
cd build
cmake ..
build fpga_emu
```

In the adjusted CMakeLists.txt a few options can be tried out.

```cmake
#set(CMAKE_CXX_FLAGS "-g -Rno-debug-disables-optimization") # Gives other (wrong) score output
#set(CMAKE_CXX_FLAGS "-g -Og") # Works properly
#set(CMAKE_CXX_FLAGS "-g -O2") # Works properly
```

## Expected scores with sample data
```text
0.784 using O3/O2/Og
0.206 using Rno-debug-disables-optimization
```