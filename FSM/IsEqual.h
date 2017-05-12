#pragma once
#include"BaseType.h"

template<typename T, typename U>
struct IsEqual
{
	using Result = FalseType;
};

template<typename T>
struct IsEqual<T, T>
{
	using Result = TrueType;
};

#define __is_eq(...)   typename IsEqual<__VA_ARGS__>::Result
