/**
 * Copyright (C) David Wolfe, 1999.  All rights reserved.
 * Ported to Qt and adapted for TDDD86, 2015.
 *
 * Edited by Hannes Tuhkala and Malcolm Vigren as part of lab 4 in TDDD86
 *
 */

#include "Junk.h"
#include "constants.h"

Junk::Junk() : Robot() {}
Junk::Junk(Unit* c) : Robot(c) {}

void Junk::draw(QGraphicsScene *scene) const {
    Point corner = asPoint();
    scene->addEllipse(QRectF(corner.x * UNIT_WIDTH, corner.y * UNIT_HEIGHT,
                             JUNK_RADIUS, JUNK_RADIUS), QPen(), QBrush(JUNK_COLOR));
}

void Junk::moveTowards(const Point& p) {}

bool Junk::isJunk() const {
	return true;
}
