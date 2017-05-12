#pragma once
#include "BaseType.h"

template<typename Condition, typename Then, typename Else> struct IfThenElse;

template<typename Then, typename Else>
struct IfThenElse<TrueType, Then, Else>
{
	using Result = Then;
};

template<typename Then, typename Else>
struct IfThenElse<FalseType, Then, Else>
{
	using Result = Else;
};

#define __if(...) typename IfThenElse<__VA_ARGS__>::Result