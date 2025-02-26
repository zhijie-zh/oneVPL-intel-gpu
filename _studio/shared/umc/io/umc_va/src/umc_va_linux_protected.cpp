// Copyright (c) 2016-2019 Intel Corporation
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

#include "umc_va_base.h"

#ifdef UMC_VA_LINUX

#include "umc_va_linux_protected.h"
#include "umc_va_linux.h"

#include "mfx_utils.h"

using namespace UMC;

/////////////////////////////////////////////////
ProtectedVA::ProtectedVA(mfxU16 p)
    : m_protected(p)
{
    memset(&m_bs, 0, sizeof(mfxBitstream));
}

mfxU16 ProtectedVA::GetProtected() const
{
    return m_protected;
}


void ProtectedVA::SetBitstream(mfxBitstream *bs)
{
    if (!bs)
        return;

}

mfxBitstream * ProtectedVA::GetBitstream()
{
    return &m_bs;
}


#endif // UMC_VA_LINUX
