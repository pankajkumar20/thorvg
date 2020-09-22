/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All rights reserved.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _TVG_GL_RENDERER_H_
#define _TVG_GL_RENDERER_H_

#include "tvgGlCommon.h"
#include "tvgGlProgram.h"
#include "tvgGlRenderTask.h"

class GlRenderer : public RenderMethod
{
public:
    Surface surface = {nullptr, 0, 0, 0};

    void* prepare(const Shape& shape, void* data, const RenderTransform* transform, vector<Composite>& compList, RenderUpdateFlag flags) override;
    bool dispose(const Shape& shape, void *data) override;
    bool preRender() override;
    bool render(const Shape& shape, void *data) override;
    bool postRender() override;
    bool target(uint32_t* buffer, uint32_t stride, uint32_t w, uint32_t h);
    bool flush() override;
    bool clear() override;

    static GlRenderer* gen();
    static int init();
    static int term();

private:
    GlRenderer(){};
    ~GlRenderer();

    void initShaders();
    void drawPrimitive(GlShape& sdata, uint8_t r, uint8_t g, uint8_t b, uint8_t a, uint32_t primitiveIndex, RenderUpdateFlag flag);
    void drawPrimitive(GlShape& sdata, const Fill* fill, uint32_t primitiveIndex, RenderUpdateFlag flag);

    vector<shared_ptr<GlRenderTask>>  mRenderTasks;
};

#endif /* _TVG_GL_RENDERER_H_ */
