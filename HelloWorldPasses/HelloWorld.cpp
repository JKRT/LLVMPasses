/*
MIT License

Copyright (c) 2019 John Tinnerholm

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>

namespace {

  struct Hello : public llvm::FunctionPass {
    static char ID;
    Hello() : llvm::FunctionPass{ID} {}
    
    bool runOnFunction(llvm::Function &F) override {
      llvm::errs() << "Hello ";
      llvm::errs().write_escaped(F.getName()) << "\n";
      return false;
    }
  };

  struct Hello2 : public llvm::ModulePass {
    static char ID;

    Hello2() : llvm::ModulePass{ID} {}
    
    bool runOnModule(llvm::Module &M) override {
      llvm::errs() << "Name of the module ", llvm::errs().write_escaped(M.getName()) << "\n";
      for(auto iter = M.getFunctionList().begin(); iter != M.getFunctionList().end(); ++iter) {
	llvm::errs() << "Function name:" << iter->getName() << "\n";
      }
      return false;
    }
  };
}

char Hello::ID = 0;
static llvm::RegisterPass<Hello> X("Hello", 
				   "Hello World Pass",
				   false,	
				   false
				   );

char Hello2::ID = 1;
static llvm::RegisterPass<Hello2> Y("Hello2", 
				    "Hello World2 pass",
				    false,	
				    false
				    );
