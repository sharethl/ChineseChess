#include "BoardView.h"
#include "WayPoint.h"

#include <QDebug>
#include <QLabel>
#include <QPainter>

BoardView::BoardView(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(HEIGHT);
    setMinimumWidth(WIDTH);

    auto space = PieceView::SIZE;

    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::black);

    for (int i = 0; i < V_LINE_COUNT; i++) {
        for (int j = 0; j < H_LINE_COUNT; j++) {
            auto wp = new WayPoint(this);
            wp->setPosition(i, j);
            QObject::connect(wp, &WayPoint::clicked, this, &BoardView::onWayPointClicked);
        }
    }

    qDebug() << this->children().count();
    for (int i = 0; i < 5; i++) {
        auto p = new PieceView(this);
        p->movePosition(i, i);
        QObject::connect(p, &PieceView::selected, this, &BoardView::onPieceSelected);
        _pieceViews.append(p);
    }
}

void BoardView::drawBackground(QPainter &painter)
{
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(211, 194, 129)));
    painter.drawRect(0, 0, WIDTH, HEIGHT);
    painter.restore();
}

void BoardView::onPieceSelected(PieceView *pieceView)
{
    foreach (auto pv, _pieceViews) {
        if (pv == pieceView) {
            pv->select();
        }
        else{
            pv->unselect();
        }
    }
}

void BoardView::onWayPointClicked(WayPoint *wayPoint)
{
    PieceView *selectedPv = nullptr;
    foreach (auto pv, _pieceViews) {
        if(pv->isSelected()){
            selectedPv = pv;
            break;
        }
    }
    if(selectedPv != nullptr){
        selectedPv->movePosition(wayPoint->position());
        selectedPv->unselect();
    }
}

void BoardView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    auto space = PieceView::SIZE;

    drawBackground(painter);

    for (int i = 0; i < V_LINE_COUNT; i++) {
        auto x = space * (i + 1);
        painter.drawLine(x, space, x, HEIGHT - space);
    }

    for (int i = 0; i < H_LINE_COUNT; i++) {
        auto y = space * (i + 1);
        painter.drawLine(space, y, WIDTH - space, y);
    }

    QWidget::paintEvent(event);
}
