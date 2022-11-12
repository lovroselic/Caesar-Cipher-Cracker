#pragma once
#ifndef CODEABBEY
#define CODEABBEY

std::vector<std::string> loadData(std::string name);
std::vector<std::string> splitString(std::string str, const std::string separator);
std::vector<std::string> splitString(std::string str);
std::string joinVector(const std::vector<std::string>& data, const std::string separator);
std::string joinVector(const std::vector<int>& data, const std::string separator);
std::string joinVector(const std::vector<long long int>& data, const std::string separator);
std::vector<int> stringVectorToInt(std::vector<std::string>& vct);
std::vector<int> splitToInt(std::string str, const std::string separator);
std::vector<int> splitToInt(std::string str);
std::string Compact(std::string str);
std::string Pack(std::vector<std::string>& cell);
std::string StringToUpper(std::string str);
std::vector<std::string> IntToHex(std::vector<int>& ints);

#endif // !CODEABBEY
