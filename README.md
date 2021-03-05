# LLVMPasses
Simple trivial example on how to run an LLVM module and LLVM function pass using LLVM 6.

Run by executing 

make runFunctionPassOnTestFile

Or 

make runModulePassOnTestfile

LLVM 6.0 and it's dependencies are needed for this to work.

# Note
If you get the following error
```
opt: CommandLine Error: Option 'debug-pass' registered more than once!
LLVM ERROR: inconsistency in registered CommandLine options
make: *** [Makefile:19: runFunctionPassOnTestFile] Error 1
```
This is most likley due to llvm reporting the following when issuing the following command:
```
./bin/llvm-config --shared-mode
static
```
If this is the case, modify the makefile as follows 
```
LLVM_INCLUDEDIR = `llvm-config --includedir`
LLVM_FLAGS = `llvm-config --cxxflags`
```
