#ifndef BRUSH_H
#define BRUSH_H
#include "rgba.h"
#include "vector"

class Brush{

public:
    void init();
    void mask();
    void draw(int x, int y, int width, int height, std::vector<RGBA> *data);
    void smudge(int x, int y, int width, int height, std::vector<RGBA> *data);
    void pickup(int x, int y, int width, int height, std::vector<RGBA> *data);

private:
    std::vector<float> brush_mask;
    std::vector<RGBA> smudge_data;
    int posToIndex(int x, int y, int width);
};

#endif // BRUSH_H