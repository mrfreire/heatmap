// Heatmap -- Manuel Freire 2015

#pragma once

#include <stdint.h>
#include <stdio.h>

//
// Public API
//

#define HEATMAP_MAX_POINTS 2048
#define HEATMAP_WARN_LIMITS_STDOUT 1

struct Heatmap
{
#ifndef HEATMAP_DISABLED
    int32_t m_points[HEATMAP_MAX_POINTS][4];
    int32_t m_count;
    int32_t m_capacity;

    Heatmap()
        : m_count(0)
        , m_capacity(HEATMAP_MAX_POINTS)
    {}
#endif
};

namespace HeatmapUtils
{
    void AddPoint(Heatmap* heatmap, int x, int y, int z, int w);
    void Clear(Heatmap* heatmap);
    void PrintStream(FILE* stream, const Heatmap& heatmap);
}

//
// Implementation
//

static inline void HeatmapUtils::AddPoint(Heatmap* heatmap, int x, int y, int z, int w)
{
#ifndef HEATMAP_DISABLED
    if (heatmap->m_count < heatmap->m_capacity)
    {
        const int index = heatmap->m_count++;
        heatmap->m_points[index][0] = x;
        heatmap->m_points[index][1] = y;
        heatmap->m_points[index][2] = z;
        heatmap->m_points[index][3] = w;
    }
    else
    {
#ifdef HEATMAP_WARN_LIMITS_STDOUT
        printf("Heatmap (Warning): Can't add point. Maximum capacity reached\n");
#endif
    }
#endif
}

static inline void HeatmapUtils::Clear(Heatmap* heatmap)
{
#ifndef HEATMAP_DISABLED
    heatmap->m_count = 0;
#endif
}

static inline void HeatmapUtils::PrintStream(FILE* stream, const Heatmap& heatmap)
{
#ifndef HEATMAP_DISABLED
    for (int i = 0; i < heatmap.m_count; ++i)
    {
        fprintf(
            stream,
            "%d %d %d %d\n",
            heatmap.m_points[i][0],
            heatmap.m_points[i][1],
            heatmap.m_points[i][2],
            heatmap.m_points[i][3]);
    }
#endif
}
