/*
	v 0.7
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Console.h"

void printArray(int* data, int length) {
	int* p = data;
	for (int x = 0; x < length; x++) {
		std::cout << p << " --> cell[" << x << "]\t= " << *p << std::endl;
		p++;
	}
	std::cout << std::endl;
}

void printVector(std::vector<int>& vct) {
	for (int v : vct) {
		std::cout << v << std::endl;
	}
}

void printVector(std::vector<double>& vct) {
	for (double v : vct) {
		std::cout << v << std::endl;
	}
}

void printVector(std::vector<std::string>& vct) {
	for (std::string v : vct) {
		std::cout << v << std::endl;
	}
}

void print2DVector(std::vector<std::vector<int>>& vct) {
	for (const auto& row : vct) {
		for (const auto& col : row) {
			std::cout << col << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

void print2DVector(std::vector<std::vector<std::string>>& vct) {
	for (const auto& row : vct) {
		for (const auto& col : row) {
			std::cout << col << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}
void print2DVector(std::vector<std::vector<char>>& vct) {
	for (const auto& row : vct) {
		for (const auto& col : row) {
			std::cout << col << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}
void print2DVector(std::vector<std::vector<bool>>& vct) {
	for (const auto& row : vct) {
		for (const auto& col : row) {
			std::cout << std::boolalpha << col << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}
void print3DVector(std::vector<std::vector<std::vector<std::string>>>& vct) {
	for (const auto& row : vct) {
		for (const auto& col : row) {
			for (const auto& instance : col) {
				std::cout << instance;
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}
void printMap(std::map<std::string, int> map) {
	for (const auto& el : map) {
		std::cout << el.first << "\t-> " << el.second << std::endl;
	}
};
void printMap(std::map<std::string, std::string> map) {
	for (const auto& el : map) {
		std::cout << el.first << "\t-> " << el.second << std::endl;
	}
};