#pragma once

template<typename H, typename T>
struct TypeElem
{
	using Head = H;
	using Tail = T;
};

#define __type_elem(...)  TypeElem<__VA_ARGS__>