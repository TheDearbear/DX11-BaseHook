#include "pch.h"
#include "base.h"
#include "IUnityInterface.h"
#include <cassert>

DWORD WINAPI MainThread(LPVOID lpThreadParameter)
{
	Base::Data::hModule = (HMODULE)lpThreadParameter;
	Base::Init();
	return TRUE;
}

DWORD WINAPI ExitThread(LPVOID lpThreadParameter)
{
	if (!Base::Data::Detached)
	{
		Base::Data::Detached = true;
		FreeLibraryAndExitThread(Base::Data::hModule, TRUE);
	}
	return TRUE;
}

// Function from https://stackoverflow.com/a/2396380
static HMODULE GetThisDllHandle()
{
	MEMORY_BASIC_INFORMATION info;
	size_t len = VirtualQueryEx(GetCurrentProcess(), (void*)GetThisDllHandle, &info, sizeof(info));
	assert(len == sizeof(info));
	return len ? (HMODULE)info.AllocationBase : NULL;
}


extern "C"
{
	// == Unity Functions ==

	// On Load
	void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginLoad(IUnityInterfaces* interfaces)
	{
		CreateThread(nullptr, 0, MainThread, GetThisDllHandle(), 0, nullptr);
	}

	// On Unload
	void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginUnload()
	{
		if (!Base::Data::Detached)
			CreateThread(nullptr, 0, ExitThread, nullptr, 0, nullptr);
	}

	// == Custom Control Functions ==

	// Show ImGui on screen
	void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API ShowImGui(int boolean)
	{
		Base::Data::ShowMenu = boolean != 0;
	}

	// Set function which will be called on every frame of imgui rendering
	void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API SetFrameCallback(FrameCallback callback)
	{
		if (callback)
			Base::Data::OnFrame = callback;
	}
}