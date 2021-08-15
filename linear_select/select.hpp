#ifndef _SELECT_H_
#define _SELECT_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int randomized_select(std::vector<int>&, int, int, int);
int linear_select(std::vector<int>&, int, int, int);
bool check(std::vector<int>&, int, int);
int partition_r(std::vector<int>&, int, int);
int partition_l(std::vector<int>&, int, int, int);
void insertion_sort(std::vector<int>&, int, int);

#endif
