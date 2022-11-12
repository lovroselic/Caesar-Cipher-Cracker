#pragma once
#ifndef LS_LIB
#define LS_LIB

double average(std::vector<int>& vect);
double average(std::vector<double>& vect);
double st_dev(std::vector<int>& vect);
double st_dev(std::vector<int>& vect, double avg);
double to_radians(double deg);
double to_degree(double rad);

#endif // !LS_LIB

