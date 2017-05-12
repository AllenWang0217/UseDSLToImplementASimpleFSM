#pragma once
#include "BaseType.h"
#include "TypeElem.h"

template<typename Head, typename ...Tails>
struct TypeList
{
	using Result = TypeElem<Head, typename TypeList<Tails...>::Result>;
};

template<typename H>
struct TypeList<H>
{
	using Result = TypeElem<H, NullType>;
};

using EmptyList = NullType;

#define __type_list(...) TypeList<__VA_ARGS__>::Result
#define __empty_list()  EmptyList