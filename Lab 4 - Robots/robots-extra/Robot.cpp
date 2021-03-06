/**
 * Copyright (C) David Wolfe, 1999.  All rights reserved.
 * Ported to Qt and adapted for TDDD86, 2015.
 *
 * Edited by Hannes Tuhkala and Malcolm Vigren as part of lab 4 in TDDD86
 *
 */

#include "Robot.h"
#include "constants.h"
#include <iostream>

Robot::Robot() : Unit() {}
Robot::Robot(Unit* c) : Unit(c) {}

void Robot::draw(QGraphicsScene *scene) const {
    Point corner = asPoint();
    scene->addEllipse(QRectF(corner.x * UNIT_WIDTH, corner.y * UNIT_HEIGHT,
                             JUNK_RADIUS, JUNK_RADIUS), QPen(), QBrush(ROBOT_COLOR));
}

bool Robot::isJunk() const {
	return false;
}

bool Robot::attacks(const Unit& u) const {
    Point p = u.asPoint();
    return (abs(x - p.x) <= 1 &&
            abs(y - p.y) <= 1);
}

bool Robot::at(const Unit& u) const {
    Point p = u.asPoint();
    return (x == p.x && y == p.y);
}
