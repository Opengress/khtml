/*
 * This file is part of the WebKit project.
 *
 * Copyright (C) 2007 Eric Seidel <eric@webkit.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef RenderSVGHiddenContainer_h
#define RenderSVGHiddenContainer_h

#if ENABLE(SVG)

#include "RenderSVGContainer.h"

namespace WebCore
{

class SVGStyledElement;

// This class is for containers which are never drawn, but do need to support style
// <defs>, <linearGradient>, <radialGradient> are all good examples
class RenderSVGHiddenContainer : public RenderSVGContainer
{
public:
    RenderSVGHiddenContainer(SVGStyledElement *);
    virtual ~RenderSVGHiddenContainer();

    bool isSVGContainer() const override
    {
        return true;
    }
    bool isSVGHiddenContainer() const override
    {
        return true;
    }

    const char *renderName() const override
    {
        return "RenderSVGHiddenContainer";
    }

    bool requiresLayer() const override;

    short lineHeight(bool b) const override;
    short baselinePosition(bool b) const override;

    void layout() override;
    void paint(PaintInfo &, int parentX, int parentY) override;

    IntRect absoluteClippedOverflowRect() override;
    void absoluteRects(Vector<IntRect> &rects, int tx, int ty, bool topLevel = true) override;

    AffineTransform absoluteTransform() const override;
    AffineTransform localTransform() const override;

    FloatRect relativeBBox(bool includeStroke = true) const override;
    /*virtual bool nodeAtPoint(const HitTestRequest&, HitTestResult&, int x, int y, int tx, int ty, HitTestAction);*/
};
}

#endif // ENABLE(SVG)
#endif // RenderSVGHiddenContainer_h
