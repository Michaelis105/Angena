//=========================================================================
// Name        : familytreegraphicsview.cpp
// Author      : Michael Louie
// Description : Model for family tree graphics view to render person nodes
//=========================================================================
#include "familytreegraphicsview.h"
#include "../model/personnode.h"

FamilyTreeGraphicsView::FamilyTreeGraphicsView()
{
    scene = new QGraphicsScene(this);
    setScene(scene);

    // Example code, remove!
    QGraphicsEllipseItem *e;
    QGraphicsRectItem *r;
    QGraphicsTextItem *t;

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    r = scene->addRect(0, 0, 30, 30, outlinePen, blueBrush);
    e = scene->addEllipse(0, 0, 30, 30, outlinePen, greenBrush);
    t = scene->addText("John Smith", QFont("Arial", 11) );
    r->setFlag(QGraphicsItem::ItemIsMovable);
    e->setFlag(QGraphicsItem::ItemIsMovable);
    t->setFlag(QGraphicsItem::ItemIsMovable);
    //! Example code, remove!
}

/**
 * @brief Renders new person node in scene view.
 * @pre PersonNode already created by model, valid reference passed here.
 * @param p PersonNode
 */
void FamilyTreeGraphicsView::addPerson(PersonNode* p) {
    if (p == nullptr) {
        throw logic_error("FamilyTreeGraphicsView::addPerson(): Cannot add a null person node to view!");
    }
    scene->addItem(p);
}

/**
 * @brief Derenders person node in scene.
 * @pre PersonNode exists by model, valid reference passed here.
 * @param p PersonNode
 */
void FamilyTreeGraphicsView::removePerson(PersonNode* p) {
    if (p == nullptr) {
        throw logic_error("FamilyTreeGraphicsView::removePerson(): Cannot remove a null person node!");
    }
    scene->removeItem(p);
    qDeleteAll(p->edgeList);
    p->edgeList.clear();
}


/**
 * @brief Shrinks view scope of graphics view.
 */
void FamilyTreeGraphicsView::zoomIn() {
    scaleView(qreal(1.2));
}

/**
 * @brief Enlarges view scope of graphics view.
 */
void FamilyTreeGraphicsView::zoomOut() {
    scaleView(1/qreal(1.2));
}

/**
 * @brief Pans graphics view in arrow direction.
 * @param Up, down, left, right keys
 */
void FamilyTreeGraphicsView::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Up:
        break;
    case Qt::Key_Down:
        break;
    case Qt::Key_Left:
        break;
    case Qt::Key_Right:
        break;
    case Qt::Key_Plus:
        break;
    case Qt::Key_Minus:
        break;
    case Qt::Key_Space:
        break;
    case Qt::Key_Enter:
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

#ifndef QT_NO_WHEELEVENT
/**
 * @brief Zooms in/out of graphics view
 * @param Mouse scroll
 */
void FamilyTreeGraphicsView::wheelEvent(QWheelEvent *event) {
    scaleView(pow((double)2, -event->delta() / 240.0));
}
#endif

/**
 * @brief Paints background
 * @param painter low-level paint
 * @param rect boundaries
 */
void FamilyTreeGraphicsView::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Click and drag the nodes around, and zoom with the mouse "
                       "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}

/**
 * @brief FamilyTreeGraphicsView::scaleView
 * @param scaleFactor
 */
void FamilyTreeGraphicsView::scaleView(qreal scaleFactor) {
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
