#pragma once
#ifndef PCH_H
#define PCH_H

#define CIMGUI_USE_DX11
#define CIMGUI_USE_WIN32

#include <iostream>
#include <Windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <libmem++/libmem.hpp>
#include "cimgui/cimgui.h"
#include "cimgui/cimgui_impl.h"

typedef void (*FrameCallback)();

#endif