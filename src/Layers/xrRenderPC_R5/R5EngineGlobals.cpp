// Build-only compatibility globals owned by the R5 project.
// They exist because engine/game headers reference renderer-owned console state.
// R5 is intentionally not runtime-capable yet; SupportsDX12Rendering() reports false.
#include "../../xrEngine/stdafx.h"

Fvector4 ps_ssfx_grass_interactive = { 0.f, 0.f, 2000.f, 1.f };
Fvector4 ps_ssfx_wind_trees = { 11.f, 0.15f, 0.5f, 0.15f };
Flags32 psDeviceFlags2 = { 0 };

// Compatibility-only copies of engine-visible renderer console state. Their defaults
// match the legacy renderer declarations; no R4 source or implementation is linked.
BOOL r_optimize_calculate_bones = TRUE;
float wallmark_range_static = 100.f;
float wallmark_range_skeleton = 50.f;

float sil_glow_max_temp = 0.15f;
float sil_glow_shot_temp = 0.004f;
float sil_glow_cool_temp_rate = 0.01f;
float hud_fov_aim_factor = 0.f;

int ps_r2_heatvision = 0;
int heat_vision_cooldown = 1;
float heat_vision_cooldown_time = 20000.f;
int heat_vision_zombie_cold = 0;

int ps_r4_hdr10_pda = 0;
Fvector4 ps_ssfx_int_grass_params_1 = { 1.f, 1.f, 1.f, 25.f };
Fvector4 ps_ssfx_int_grass_params_2 = { 1.f, 5.f, 1.f, 1.f };
Flags32 ps_actor_shadow_flags = { 0 };
