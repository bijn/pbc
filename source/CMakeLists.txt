# pbc
# CMakeLists.txt

# Client target --------------------------------------------------------

add_executable(pbc pbc.cc)

set(PBC_CLIENT_LIBS CLI11)
if(NOT WIN32)
  set(PBC_CLIENT_LIBS ${PBC_CLIENT_LIBS} pthread)
endif()
target_link_libraries(pbc ${PBC_CLIENT_LIBS})
