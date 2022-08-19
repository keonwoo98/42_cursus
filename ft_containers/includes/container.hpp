#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

#ifdef STD_MODE
#include <utility.hpp>
#include <map>
#include <stack>
#include <vector>
#define TESTED_NAMESPACE std
#define MODE 1
#else
#include "utility.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#define TESTED_NAMESPACE ft
#define MODE 0
#endif

#include <ctime>

int main(int argc, char **argv);

#endif
