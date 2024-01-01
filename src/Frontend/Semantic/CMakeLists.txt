include_directories(${COBALT_INCLUDE_DIR}/cobalt/Frontend/Semantic)

set(COBALT_SEMANTIC_SOURCE
        AST/ExprNode.cpp AST/TypeNode.cpp AST/StmtNode.cpp
        Resolver/Scope.cpp Resolver/Resolver.cpp
    )

add_library(CobaltSemantic ${COBALT_SEMANTIC_SOURCE})