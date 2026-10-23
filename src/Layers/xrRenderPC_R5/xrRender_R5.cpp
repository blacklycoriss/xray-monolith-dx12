// Build-only R5 integration seam. This file deliberately provides no GPU backend.
// A false capability probe prevents EngineAPI from treating R5 as runtime-capable.
#include "../../xrEngine/stdafx.h"
#include "../xrRender/dxRenderFactory.h"

// xrAPI has a concrete factory symbol baked into its current ABI. The methods below
// satisfy that ABI for the build only; every creation path is intentionally unsupported.
dxRenderFactory RenderFactoryImpl;

#define R5_BUILD_ONLY_FACTORY_IMPLEMENT(Class) \
    I##Class* dxRenderFactory::Create##Class() { return nullptr; } \
    void dxRenderFactory::Destroy##Class(I##Class*) {}

#ifndef _EDITOR
R5_BUILD_ONLY_FACTORY_IMPLEMENT(UISequenceVideoItem)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(UIShader)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(StatGraphRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(ConsoleRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(RenderDeviceRender)
#ifdef DEBUG
R5_BUILD_ONLY_FACTORY_IMPLEMENT(ObjectSpaceRender)
#endif
R5_BUILD_ONLY_FACTORY_IMPLEMENT(ApplicationRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(WallMarkArray)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(StatsRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(FlareRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(ThunderboltRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(ThunderboltDescRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(RainRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(LensFlareRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(ImGuiRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(EnvironmentRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(EnvDescriptorMixerRender)
R5_BUILD_ONLY_FACTORY_IMPLEMENT(EnvDescriptorRender)
#endif
R5_BUILD_ONLY_FACTORY_IMPLEMENT(FontRender)

#undef R5_BUILD_ONLY_FACTORY_IMPLEMENT

// EngineAPI invokes this static-library entry point directly. It must not claim that
// this build-only compatibility library is a usable renderer.
BOOL DllMainXrRenderR5(HANDLE, DWORD, LPVOID)
{
    return TRUE;
}

extern "C" bool SupportsDX12Rendering()
{
    return false;
}
