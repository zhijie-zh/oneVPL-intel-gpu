// Copyright (c) 2021 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#include "mfx_common.h"
#include "mfx_task.h"

#ifndef _MFX_VPP_HELPER_H_
#define _MFX_VPP_HELPER_H_
#define MFX_ENABLE_VPP_HELPER

#if defined (MFX_ENABLE_VPP_HELPER)

class VideoVPPMain;

class MfxVppHelper
{
public:
    MfxVppHelper(VideoCORE* core, mfxStatus* mfxRes);

    virtual ~MfxVppHelper() { Close(); }

    virtual mfxStatus Init(mfxVideoParam* param);

    virtual mfxStatus Reset(mfxVideoParam* param);

    virtual mfxStatus Close();

    virtual mfxStatus Submit(mfxFrameSurface1* input, mfxFrameSurface1* output = nullptr);

    virtual mfxFrameSurface1* GetOutptSurface();

protected:
    mfxStatus CreateVpp(mfxVideoParam* param);
    void DestroyVpp();

protected:
    bool                   m_bInitialized = false;
    bool                   m_taskSubmitted= false;
    VideoCORE*             m_core         = nullptr;


    //mfxExtBuffer*          m_extBuffer = nullptr;
    //mfxExtVPPScaling       m_scalingConfig = {};

    MFX_ENTRY_POINT        m_entryPoint[2]   = {};
    VideoVPPMain*          m_pVpp            = nullptr;
    mfxFrameAllocResponse  m_dsResponse      = {};
    mfxFrameSurface1       m_dsSurface       = {};

    mfxU16                 m_dstWidth    = 128; // target down scaled size
    mfxU16                 m_dstHeight   = 64;
};

#endif

#endif // !_MFX_VPP_HELPER_H_
