//===================================================
// Name        : familytreegraphicsview.h
// Author      : Michael Louie
// Description : Header for family tree graphics view
//===================================================
#ifndef FAMILYTREEGRAPHICSVIEW_H
#define FAMILYTREEGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QKeyEvent>
#include <QtAlgorithms>
#include <stdexcept>

class PersonNode;

class FamilyTreeGraphicsView : public QGraphicsView
{
    Q_OBJECT

    public:
        FamilyTreeGraphicsView();
        void addPerson(PersonNode* p);
        void removePerson(PersonNode* p);

    public slots:
        void zoomIn();
        void zoomOut();

    protected:
        void keyPressEvent(QKeyEvent *event) override;
    #ifndef QT_NO_WHEELEVENT
        void wheelEvent(QWheelEvent *event) override;
    #endif
        void drawBackground(QPainter *painter, const QRectF &rect) override;

        void scaleView(qreal scaleFactor);

    private:
        QGraphicsScene * scene;
};

#endif // FAMILYTREEGRAPHICSVIEW_H
