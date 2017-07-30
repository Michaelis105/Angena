//============================================================
// Name        : edge.cpp
// Author      : Michael Louie
// Description : Generic line visually connects nodes in scene
//               All logical connections handled in model
//============================================================
#include "edge.h"
#include "../model/personnode.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Edge::Edge(PersonNode* s, PersonNode* d)
{
    src = s;
    dest = d;
    src->addEdge(this);
    dest->addEdge(this);
    adjust();
}

/**
 * @brief Redraws edge typically on node position change.
 */
void Edge::adjust() {
    if (!src || !dest) return;

    QLineF line(mapFromItem(src, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}

PersonNode *Edge::sourceNode() const {
    return src;
}

PersonNode *Edge::destNode() const {
    return dest;
}

QRectF Edge::boundingRect() const {
    if (!src || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    if (!src || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    // Draw the line itself
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);

    // Draw the arrows
    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p1());
    painter->drawPolygon(QPolygonF() << line.p2());
}
