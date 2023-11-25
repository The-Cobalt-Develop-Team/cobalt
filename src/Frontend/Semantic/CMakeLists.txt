include_directories(${COBALT_INCLUDE_DIR}/cobalt/Frontend/Semantic)

add_library(CobaltSemantic AST/ExprNode.cpp AST/TypeNode.cpp)