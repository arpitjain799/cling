
#include "Utils.h"

#include "cling/Interpreter/InterOp.h"

#include "gtest/gtest.h"


TEST(VariableReflectionTest, GetDatamembers) {
  std::vector<Decl*> Decls;
  std::string code = R"(
    class C {
    public:
      int a;
      static int b;
    private:
      int c;
      static int d;
    protected:
      int e;
      static int f;
    };
    )";

  GetAllTopLevelDecls(code, Decls);
  auto datamembers = InterOp::GetDatamembers(Decls[0]);

  EXPECT_EQ(InterOp::GetCompleteName(datamembers[0]), "C::a");
  EXPECT_EQ(InterOp::GetCompleteName(datamembers[1]), "C::c");
  EXPECT_EQ(InterOp::GetCompleteName(datamembers[2]), "C::e");
  EXPECT_EQ(datamembers.size(), 3);
}