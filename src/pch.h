#pragma once
#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_D3D9_IMPLEMENTATION
#define NK_PRIVATE
#define STBRP_STATIC
#define STBTT_STATIC

#include <iostream>
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <libmem++/libmem.hpp>
#include <nuklear/nuklear.h>
#include <nuklear/nuklear_d3d9.h>

#endif