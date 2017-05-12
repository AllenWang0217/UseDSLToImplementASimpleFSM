#pragma once

//IntType
template<int V>
struct IntType
{
	enum { Value = V };
	using Result = IntType<V>;
};

template<bool V> struct BoolType;

//BoolType
template<>
struct BoolType<true>
{
	enum { Value = true };
	using Result = BoolType<true>;
};

template<>
struct BoolType<false>
{
	enum { Value = false };
	using Result = BoolType<false>;
};

using TrueType = BoolType<true>;
using FalseType = BoolType<false>;

struct NullType;

struct EmptyType
{
};

#define __int(value) IntType<value>::Result
#define __bool(...) BoolType<__VA_ARGS__>::Result
#define __true() TrueType::Result
#define __false() FalseType::Result
#define __empty() EmptyType

