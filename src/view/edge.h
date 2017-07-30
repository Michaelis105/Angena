//==============================
// Name        : edge.h
// Author      : Michael Louie
// Description : Header for edge
//==============================
#ifndef EDGE_H
#define EDGE_H
#include <QGraphicsItem>
#include <math.h>
#include <QPainter>

class PersonNode;

class Edge : public QGraphicsItem
{
    public:
        Edge(PersonNode* src, PersonNode* dest);
        void adjust();
        PersonNode *sourceNode() const;
        PersonNode *destNode() const;

    protected:
        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    private:
        PersonNode *src, *dest;
        QPointF sourcePoint;
        QPointF destPoint;
};

#endif // EDGE_H
