//====================================================================
// Name        : personNode.cpp
// Author      : Michael Louie
// Description : Node containing a person and relationships with other
//               people.
//====================================================================
#include "personnode.h"

PersonNode::PersonNode(string newId)
{
    id = newId;
    p = new Person();
    father = nullptr;
    mother = nullptr;
}

// TODO: Handle what to do with other people attributes.
PersonNode::PersonNode(string newId, PersonNode * f, PersonNode * m)
{
    id = newId;
    p = new Person();
    father = f;
    mother = m;
}

PersonNode::~PersonNode() {
    delete p;
}

void PersonNode::setConfigurations() {
   setFlag(ItemIsMovable);
}

///////////////
//
// View-related
//
///////////////

void PersonNode::addEdge(Edge *edge) {
    if (edge == nullptr) {
        throw invalid_argument( "PersonNode::addEdge(): Cannot add null edge!" );
    }
    edgeList << edge;
    edge->adjust();
}

void PersonNode::removeEdge(Edge *edge) {
    if (edge == nullptr) {
        throw invalid_argument( "PersonNode::removeEdge(): Cannot re,pve null edge!" );
    }
    for (int i = 0; i < edgeList.size()-1; i++) {
        Edge *e = edgeList.at(i);
        if (e == edge) {
            edgeList.removeAt(i);
            delete e;
            return;
        }
    }
    throw logic_error( "PersonNode::removeEdge(): Cannot remove null edge!" );
}

/**
 * @brief Sets rectangular bounds of node.
 * @return rectangular bounds of node
 */
QRectF PersonNode::boundingRect() const
{
    return QRectF(0,0,100,100);
}

/**
 * @brief Draws node on to scene.
 * @param painter
 * @param option
 * @param widget
 */
void PersonNode::paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    } else {
        gradient.setColorAt(0, Qt::yellow);
        gradient.setColorAt(1, Qt::darkYellow);
    }
    painter->setBrush(gradient);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(0, 0, 20, 20);
}

QVariant PersonNode::itemChange(GraphicsItemChange change, const QVariant &value) {
    switch(change) {
        case ItemPositionHasChanged:
            break;
        default:
            break;
    }
    return QGraphicsItem::itemChange(change, value);
}

void PersonNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    update();
    QGraphicsItem::mousePressEvent(event);
}

void PersonNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

////////////////
//
// Model-related
//
////////////////

// NOTE: See personnode.h for template method declarations and body.

/**
 * @brief Set person node's father.
 * @param f father node.
 */
void PersonNode::setFather(PersonNode * f) {
    father = f;
}

/**
 * @brief Set person node's mother.
 * @param m mother node
 */
void PersonNode::setMother(PersonNode * m) {
    mother = m;
}

/**
 * @brief Gets person node's father.
 * @return PersonNode if set, null if no known father
 */
PersonNode* PersonNode::getFather() {
    return father;
}

/**
 * @brief Gets person node's mother.
 * @return PersonNode if set, null if no known father
 */
PersonNode* PersonNode::getMother() {
    return mother;
}

/**
 * @brief Connects person (parent) and offspring.
 * @param os offspring to connect
 */
void PersonNode::addOffspring(PersonNode * os) {
    if (os != nullptr) {
        offspring.push_back(os);
    } else {
        throw invalid_argument( "PersonNode::addOffspring(): Offspring was null." );
    }
}

/**
 * @brief Disconnects person and offspring.
 * @param os offspring to disconnect
 */
void PersonNode::removeOffspring(PersonNode * os) {
    if (os != nullptr) {
        if (!offspring.empty()) {
            for (int i = 0; i < offspring.size()-1; i++) {
                if (os == (offspring.at(i))) {
                    offspring.erase(offspring.begin()+i);
                    return;
                }
            }
            throw logic_error( "PersonNode::removeOffspring(): Failed to find offspring to remove." );
        } else {
            throw invalid_argument( "PersonNode::removeOffspring(): Attempt remove offspring when empty." );
        }
    } else {
        throw invalid_argument( "PersonNode::removeOffspring(): Offspring was null." );
    }
}
