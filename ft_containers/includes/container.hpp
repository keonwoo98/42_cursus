#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#ifdef STD_MODE
#include <utility.hpp>
#include <map>
#include <stack>
#include <vector>
#define NAMESPACE std
#define TIME_DIFF "std_time"
#define MODE 1
#define _c c
#else
#include "utility.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#define NAMESPACE ft
#define TIME_DIFF "ft_time"
#define MODE 0
#endif

#include <ctime>
#include <fstream>

int main(int argc, char **argv);

#endif
