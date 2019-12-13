# add the library that runs
add_library(MathFunctions MathFunctions.cc)

# stat that anybody linking to us needs to include the current source dir
# to find MathFunction.h while we don't.
target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
if(USE_MATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # first we add the executable that generates the table
  add_executable(MakeTable MakeTable.cc)

  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.hh
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.hh
    DEPENDS MakeTable
    )

  # library that just does sqrt
  add_library(SqrtLibrary STATIC
              mysqrt.cc
              ${CMAKE_CURRENT_BINARY_DIR}/Table.hh
              )

  # state that we depend on our binary dir to find Table.h
  target_include_directories(SqrtLibrary PRIVATE
                             ${CMAKE_CURRENT_BINARY_DIR}
                             )

  set_target_properties(SqrtLibrary PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                        )

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(MathFunctions PRIVATE "EXPORTING_MYMATH")

# install rules
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.hh DESTINATION include)
