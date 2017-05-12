#pragma once

#include "BaseType.h"
#include "IfThenElse.h"
#include "TypeElem.h"

template<typename TL, template<typename T> class Pred> struct Filter;

template<template<typename T> class Pred>
struct Filter<NullType, Pred>
{
	using Result = NullType;
};

template<typename Head, typename Tail, template<typename T> class Pred>
struct Filter<TypeElem<Head, Tail>, Pred>
{
	using Result = typename IfThenElse< typename Pred<Head>::Result,
		TypeElem<Head, typename Filter<Tail, Pred>::Result>,
		typename Filter<Tail, Pred>::Result>::Result;
};

#define __filter(...) typename Filter<__VA_ARGS__>::Result