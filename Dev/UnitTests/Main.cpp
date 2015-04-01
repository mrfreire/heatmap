#include "../../Heatmap.h"

#include <assert.h>

int main()
{
    Heatmap heatmap;

    static_assert(sizeof(Heatmap) == 32768 + 4 + 4, "Unexpected heatmap size");

    for (int i = 0; i < HEATMAP_MAX_POINTS; ++i)
    {
        HeatmapUtils::AddPoint(&heatmap, i, i, i, 0);
    }

    assert(heatmap.m_count == HEATMAP_MAX_POINTS);
    HeatmapUtils::AddPoint(&heatmap, 0, 0, 0, 0);
    assert(heatmap.m_count == HEATMAP_MAX_POINTS);
    
    HeatmapUtils::PrintStream(stdout, heatmap);

    HeatmapUtils::Clear(&heatmap);
    assert(heatmap.m_count == 0);

    printf("OK\n");

    return 0;
}
