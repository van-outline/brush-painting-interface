#include "brush.h"
#include "settings.h"
#include <cmath>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <algorithm>


void Brush::init() {
    //mask();
}

void Brush::mask() {
    BrushType type = BRUSH_CONSTANT;
    int radius = settings.brushRadius;
    int diameter = 2 * radius + 1;

    brush_mask.assign(diameter * diameter, 0.0f);
    smudge_data.assign(diameter * diameter, RGBA{0, 0, 0, 0});
    switch (settings.brushType) {

        case BRUSH_LINEAR:
            for (int i = 0; i < brush_mask.size(); i++) {
                int dy = abs(i / diameter - radius);
                int dx = abs(i % diameter - radius);

                float distance = sqrt(float(dx * dx + dy * dy));

                brush_mask[i] = std::max(0.0f, 1.0f - (distance / radius));
            }
            break;

        case BRUSH_QUADRATIC:
            for (int i = 0; i < brush_mask.size(); i++) {
                int dy = abs(i / diameter - radius);
                int dx = abs(i % diameter - radius);

                float distance = sqrt(float(dx * dx + dy * dy));

                float falloff = std::max(0.0f, 1.0f - distance / radius);
                brush_mask[i] = falloff * falloff;
            }
            break;

        case BRUSH_SMUDGE:
            for (int i = 0; i < brush_mask.size(); i++) {
                int dy = abs(i / diameter - radius);
                int dx = abs(i % diameter - radius);

                float distance = sqrt(float(dx * dx + dy * dy));

                brush_mask[i] = std::max(0.0f, 1.0f - (distance / radius));
            }
            break;


        default:
            for (int i = 0; i < brush_mask.size(); i++) {
                int dy = abs(i / diameter - radius);
                int dx = abs(i % diameter - radius);

                float distance = sqrt(float(dx * dx + dy * dy));

                if (distance <= radius) {
                    brush_mask[i] = 1.0f;  // avoids dividing by zero
                } else {
                    brush_mask[i] = 0.0f;
                }
            }
            break;
    }
}


int Brush::posToIndex(int x, int y, int width) {
    int index = y * width + x;
    return index;
}

void Brush::draw(int x, int y, int width, int height, std::vector<RGBA> *data){
    int radius = settings.brushRadius;
    RGBA color = settings.brushColor;
    int count = 0;

    for (int r = y - radius; r <= y + radius; r++) {
        for (int c = x - radius; c <= x + radius; c++) {
            bool inBounds = r >= 0 && r < height && c >= 0 && c < width;

            if (inBounds && brush_mask[count] > 0.0f) {
                RGBA &pixel = data->at(posToIndex(c, r, width));
                float opacity = brush_mask[count] * color.a / 255.0f;

                pixel.r = static_cast<std::uint8_t>(color.r * opacity + pixel.r * (1.0f - opacity) + 0.5f);
                pixel.g = static_cast<std::uint8_t>(color.g * opacity + pixel.g * (1.0f - opacity) + 0.5f);
                pixel.b = static_cast<std::uint8_t>(color.b * opacity + pixel.b * (1.0f - opacity) + 0.5f);
            }
            count++;
        }
    }
}

void Brush::smudge(int x, int y, int width, int height, std::vector<RGBA> *data){
    int radius = settings.brushRadius;
    int count = 0;

    for (int r = y - radius; r <= y + radius; r++) {
        for (int c = x - radius; c <= x + radius; c++) {
            bool inBounds = r >= 0 && r < height && c >= 0 && c < width;

            if (inBounds && brush_mask[count] > 0.0f) {
                RGBA &pixel = data->at(posToIndex(c, r, width));
                RGBA src = smudge_data[count];
                float opacity = brush_mask[count] * src.a / 255.0f;

                pixel.r = static_cast<std::uint8_t>(opacity * src.r + (1.0f - opacity) * pixel.r + 0.5f);
                pixel.g = static_cast<std::uint8_t>(opacity * src.g + (1.0f - opacity) * pixel.g + 0.5f);
                pixel.b = static_cast<std::uint8_t>(opacity * src.b + (1.0f - opacity) * pixel.b + 0.5f);
            }
            count++;
        }
    }
    pickup(x, y, width, height, data);
}

void Brush::pickup(int x, int y, int width, int height, std::vector<RGBA> *data){
    int radius = settings.brushRadius;
    int count = 0;

    for (int r = y - radius; r <= y + radius; r++) {
        for (int c = x - radius; c <= x + radius; c++) {
            bool inBounds = r >= 0 && r < height && c >= 0 && c < width;

            if (inBounds) {
                smudge_data[count] = data->at(posToIndex(c, r, width));
            } else {
                smudge_data[count] = RGBA{0, 0, 0, 0};
            }

            count++;
        }
    }
}