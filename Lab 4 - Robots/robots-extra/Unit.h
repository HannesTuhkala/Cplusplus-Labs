/**
 * Copyright (C) David Wolfe, 1999.  All rights reserved.
 * Ported to Qt and adapted for TDDD86, 2015.
 *
 * Edited by Hannes Tuhkala and Malcolm Vigren as part of lab 4 in TDDD86
 *
 */

#ifndef UNIT_H
#define UNIT_H

#include "utilities.h"
#include <QGraphicsScene>

/* Root class for all pieces on the board.
 * Subclasses are Robot, Hero and Junk.
 */
class Unit {
public:
    Unit();
    Unit(const Unit* u);
    Unit(const Point& p);
    virtual ~Unit() {}

    /*
    * Return Point representation of Unit
    */
    Point asPoint() const;

	virtual void draw(QGraphicsScene* scene) const = 0;

    /*
    * Take one step closer to u
    */
    virtual void moveTowards(const Point& p);

    /*
    * Teleport. Does not check for collision
    */
    void teleport();

    /*
    * Euclidean distance to u
    */
    double distanceTo(const Unit* u) const;

protected:
    int x;  // x position of this unit
    int y;  // y position of this unit

private:
    // private helpers
    void checkBounds();
};

#endif // UNIT_H
