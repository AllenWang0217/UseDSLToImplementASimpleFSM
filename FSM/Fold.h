#pragma once

#include "BaseType.h"
#include "TypeElem.h"

template<typename TL, typename T, template<typename Acc, typename U> class Func> struct Fold;

template<typename T, template<typename Acc, typename U> class Func>
struct Fold<NullType, T, Func>
{
	using Result = T;
};

template<typename Head, typename Tail, typename T, template<typename Acc, typename U> class Func>
struct Fold<TypeElem<Head, Tail>, T, Func>
{
	using Result = typename Func<typename Fold<Tail, T, Func>::Result, Head>::Result;
};

#define __fold(...) typename Fold<__VA_ARGS__>::Result