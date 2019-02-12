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
