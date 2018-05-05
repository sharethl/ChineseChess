#include "PieceView.h"

#include <QPainter>
#include <QTime>

PieceView::PieceView(QWidget *parent, ChessPiece *piece)
    : QWidget(parent)
    , _piece(piece)

{
    _defaultBrush = piece->player() == Player::Black ? QBrush(QColor(192, 190, 192))
                                                     : QBrush(QColor(255, 255, 255));
    _currentBrush = _defaultBrush;
    this->resize(SIZE, SIZE);
}

void PieceView::movePosition(const QPoint &pos)
{
    this->movePosition(pos.x(), pos.y());
    _piece->setPosition(pos);
}

void PieceView::movePosition(int x, int y)
{
    this->move(x * SIZE + SIZE / 2, y * SIZE + SIZE / 2);
}

void PieceView::select()
{
    _currentBrush = QBrush(Qt::blue);
    _isSelected = true;
    repaint();
}

void PieceView::unselect()
{
    _currentBrush = _defaultBrush;
    _isSelected = false;
    repaint();
}

void PieceView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    int borderThickness = 1;
    QPen pen(Qt::black, borderThickness);
    painter.setPen(pen);
    painter.setBrush(_currentBrush);

    painter.drawEllipse(0, 0, SIZE - borderThickness, SIZE - borderThickness);

    painter.setPen( Qt::black );
    auto font = painter.font();
    font.setPixelSize(SIZE/2);
    painter.setFont( font );

    painter.drawText(0, 0, SIZE, SIZE, Qt::AlignCenter,  _piece->letter());
    QWidget::paintEvent(event);
}

void PieceView::mousePressEvent(QMouseEvent *event)
{
    emit selected(this);
}

ChessPiece *PieceView::piece() const
{
    return _piece;
}
