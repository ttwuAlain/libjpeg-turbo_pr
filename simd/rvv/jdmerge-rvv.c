/*
 * Risc-V vector extension optimizations for libjpeg-turbo
 *
 * Copyright (C) 2014, D. R. Commander.  All Rights Reserved.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

/* These routines combine simple (non-fancy, i.e. non-smooth) h2v1 or h2v2
 * chroma upsampling and YCbCr -> RGB color conversion into a single function.
 */
#include "jsimd_rvv.h"

/* YCbCr --> RGB conversion constants */
#define F_0_344  22554              /* FIX(0.34414) */
#define F_0_714  46802              /* FIX(0.71414) */
#define F_0_772  50594              /* FIX(0.77200) */
#define F_0_402  26345              /* FIX(0.40200) */


#include "jdmrgext-rvv.c"
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#define RGB_RED  EXT_RGB_RED
#define RGB_GREEN  EXT_RGB_GREEN
#define RGB_BLUE  EXT_RGB_BLUE
#define RGB_PIXELSIZE  EXT_RGB_PIXELSIZE
#define jsimd_h2v1_merged_upsample_rvv  jsimd_h2v1_extrgb_merged_upsample_rvv
#define jsimd_h2v2_merged_upsample_rvv  jsimd_h2v2_extrgb_merged_upsample_rvv
#include "jdmrgext-rvv.c"
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE
#undef jsimd_h2v1_merged_upsample_rvv
#undef jsimd_h2v2_merged_upsample_rvv

#define RGB_RED  EXT_RGBX_RED
#define RGB_GREEN  EXT_RGBX_GREEN
#define RGB_BLUE  EXT_RGBX_BLUE
#define RGB_ALPHA 3
#define RGB_PIXELSIZE  EXT_RGBX_PIXELSIZE
#define jsimd_h2v1_merged_upsample_rvv  jsimd_h2v1_extrgbx_merged_upsample_rvv
#define jsimd_h2v2_merged_upsample_rvv  jsimd_h2v2_extrgbx_merged_upsample_rvv
#include "jdmrgext-rvv.c"
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_ALPHA
#undef RGB_PIXELSIZE
#undef jsimd_h2v1_merged_upsample_rvv
#undef jsimd_h2v2_merged_upsample_rvv

#define RGB_RED  EXT_BGR_RED
#define RGB_GREEN  EXT_BGR_GREEN
#define RGB_BLUE  EXT_BGR_BLUE
#define RGB_PIXELSIZE  EXT_BGR_PIXELSIZE
#define jsimd_h2v1_merged_upsample_rvv  jsimd_h2v1_extbgr_merged_upsample_rvv
#define jsimd_h2v2_merged_upsample_rvv  jsimd_h2v2_extbgr_merged_upsample_rvv
#include "jdmrgext-rvv.c"
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE
#undef jsimd_h2v1_merged_upsample_rvv
#undef jsimd_h2v2_merged_upsample_rvv

#define RGB_RED  EXT_BGRX_RED
#define RGB_GREEN  EXT_BGRX_GREEN
#define RGB_BLUE  EXT_BGRX_BLUE
#define RGB_ALPHA 3
#define RGB_PIXELSIZE  EXT_BGRX_PIXELSIZE
#define jsimd_h2v1_merged_upsample_rvv  jsimd_h2v1_extbgrx_merged_upsample_rvv
#define jsimd_h2v2_merged_upsample_rvv  jsimd_h2v2_extbgrx_merged_upsample_rvv
#include "jdmrgext-rvv.c"
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_ALPHA
#undef RGB_PIXELSIZE
#undef jsimd_h2v1_merged_upsample_rvv
#undef jsimd_h2v2_merged_upsample_rvv

#define RGB_RED  EXT_XBGR_RED
#define RGB_GREEN  EXT_XBGR_GREEN
#define RGB_BLUE  EXT_XBGR_BLUE
#define RGB_ALPHA 0
#define RGB_PIXELSIZE  EXT_XBGR_PIXELSIZE
#define jsimd_h2v1_merged_upsample_rvv  jsimd_h2v1_extxbgr_merged_upsample_rvv
#define jsimd_h2v2_merged_upsample_rvv  jsimd_h2v2_extxbgr_merged_upsample_rvv
#include "jdmrgext-rvv.c"
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_ALPHA
#undef RGB_PIXELSIZE
#undef jsimd_h2v1_merged_upsample_rvv
#undef jsimd_h2v2_merged_upsample_rvv

#define RGB_RED  EXT_XRGB_RED
#define RGB_GREEN  EXT_XRGB_GREEN
#define RGB_BLUE  EXT_XRGB_BLUE
#define RGB_ALPHA 0
#define RGB_PIXELSIZE  EXT_XRGB_PIXELSIZE
#define jsimd_h2v1_merged_upsample_rvv  jsimd_h2v1_extxrgb_merged_upsample_rvv
#define jsimd_h2v2_merged_upsample_rvv  jsimd_h2v2_extxrgb_merged_upsample_rvv
#include "jdmrgext-rvv.c"
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_ALPHA
#undef RGB_PIXELSIZE
#undef jsimd_h2v1_merged_upsample_rvv
#undef jsimd_h2v2_merged_upsample_rvv
