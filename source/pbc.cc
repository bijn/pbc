#include <iostream>

#include <asio.hpp>
#include <CLI/CLI.hpp>

int main(int argc, char **argv)
{
  CLI::App app{"pbc client"};

  CLI11_PARSE(app, argc, argv);

  asio::io_service io;

  return EXIT_SUCCESS;
}
