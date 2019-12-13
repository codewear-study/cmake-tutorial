add_library(MathFunctions mysqrt.cc)

target_include_directories(MathFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_BINARY_DIR}
    )

include(CheckCXXSourceRuns)
check_cxx_source_runs(
  "
  #include <cmath>
  
  auto main(int argc, char **argv) -> int
  {
    double test = static_cast<double>(100.0);
    test = std::log(test);
    
    return 0;
  }
  "
  HAVE_CXX_STD_LOG
)
check_cxx_source_runs(
  "
  #include <cmath>
  
  auto main(int argc, char **argv) -> int
  {
    double test = static_cast<double>(100.0);
    test = std::exp(test);
    
    return 0;
  }
  "
  HAVE_CXX_STD_EXP
)

if(HAVE_CXX_STD_LOG AND HAVE_CXX_STD_EXP)
  target_compile_definitions(MathFunctions
                             PRIVATE HAVE_CXX_STD_LOG HAVE_CXX_STD_EXP)
endif()

install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.hh DESTINATION include)