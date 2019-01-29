LLVM_VERSION=
LLVM_INCLUDEDIR = `llvm-config-6.0 --includedir`
test = foobarfoo
LLVM_FLAGS = `llvm-config-6.0 --cxxflags --ldflags --system-libs --libs all`
CXX = clang++-6.0
CXXFLAGS = -g -std=c++11 -O3 -I $(LLVM_INCLUDEDIR) -I $(LLVM_INCLUDEDIR)
Hello.so:
	$(CXX) -fPIC $(CXXFLAGS) HelloWorld.cpp $(LLVM_FLAGS) -shared -o Hello.so
Hello: Hello.so

testfile:
	clang++-6.0 -emit-llvm -c test.cpp -o test.bc

runFunctionPassOnTestFile: Hello testfile
	opt-6.0 -load ./Hello.so -Hello < test.bc > /dev/null

runModulePassOnTestfile: Hello testfile
	opt-6.0 -load ./Hello.so -Hello2 < test.bc > /dev/null

clean:
	rm *.o *.so *.out *~
DBG:
	@echo LLVM INCLUDE DIRS $(LLVM_INCLUDEDIR) $(test)
