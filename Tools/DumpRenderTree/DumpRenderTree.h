/*
 * Copyright (C) 2006, 2007 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer. 
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution. 
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DumpRenderTree_h
#define DumpRenderTree_h

// FIXME: Remove this when all platforms are using config.h
#ifndef Config_H
#include <wtf/Platform.h>
#endif

#if PLATFORM(MAC)
#include "DumpRenderTreeMac.h"
#elif PLATFORM(WIN)
#include "DumpRenderTreeWin.h"
#elif PLATFORM(GTK)
#include "DumpRenderTreeGtk.h"
#elif PLATFORM(WX)
#include "DumpRenderTreeWx.h"
#elif PLATFORM(EFL)
#include "DumpRenderTreeEfl.h"
#elif PLATFORM(BLACKBERRY)
#include "DumpRenderTreeBlackBerry.h"
#endif

#include <string>
#include <wtf/RefPtr.h>

#if !OS(OPENBSD)
std::wstring urlSuitableForTestResult(const std::wstring& url);
#endif

class TestRunner;

extern volatile bool done;

// FIXME: This is a bad abstraction.  We should insted pass this to other controller objects which need access to it.
extern RefPtr<TestRunner> gTestRunner;

void dump();
void displayWebView();

struct TestCommand {
    TestCommand() : shouldDumpPixels(false) { }

    std::string pathOrURL;
    bool shouldDumpPixels;
    std::string expectedPixelHash;
};

TestCommand parseInputLine(const std::string&);

#endif // DumpRenderTree_h
