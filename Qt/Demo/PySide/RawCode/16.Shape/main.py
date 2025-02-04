import sys
from random import randint, choice
from PySide6 import QtCore, QtGui, QtWidgets
from PySide6.QtCore import Qt


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()

        self.label = QtWidgets.QLabel() # Why do we use QLabel to draw on? The QLabel widget can also be used to show images, and it's the simplest widget available for displaying a QPixmap.
        canvas = QtGui.QPixmap(400, 300)
        canvas.fill(Qt.white)
        self.label.setPixmap(canvas)
        self.setCentralWidget(self.label)

        # self.draw_line()
        # self.draw_point()
        # self.draw_random_dots()
        self.draw_random_dots_with_colors()
        # self.draw_rect()
        # self.draw_text()

    def draw_line(self):
        canvas = self.label.pixmap()    # retrieve the pixmap, so later we can modify it, and then re-apply it to the label
        painter = QtGui.QPainter(canvas)

        painter.drawLine(10, 10, 300, 200)

        painter.end()       # close the painter and apply the changes.
        self.label.setPixmap(canvas)

    def draw_point(self):
        canvas = self.label.pixmap()    # retrieve the pixmap, so later we can modify it, and then re-apply it to the label
        painter = QtGui.QPainter(canvas)

        # draw a point
        pen = QtGui.QPen()
        pen.setWidth(40)
        pen.setColor(QtGui.QColor('red'))
        painter.setPen(pen)
        painter.drawPoint(300, 150)

        painter.end()       # close the painter and apply the changes.
        self.label.setPixmap(canvas)

    def draw_random_dots(self):
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(3)
        painter.setPen(pen)
        for _ in range(10000):
            painter.drawPoint(
                200+randint(-100, 100),  # x
                150+randint(-100, 100)   # y
                )
        painter.end()
        self.label.setPixmap(canvas)

    def draw_random_dots_with_colors(self):
        colors = ['#FFD141', '#376F9F', '#0D1F2D', '#E9EBEF', '#EB5160']
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(3)
        painter.setPen(pen)

        for _ in range(10000):
            # pen = painter.pen() you could get the active pen here
            pen.setColor(QtGui.QColor(choice(colors)))
            painter.setPen(pen)
            painter.drawPoint(
                200+randint(-100, 100),  # x
                150+randint(-100, 100)   # y
                )
        painter.end()
        self.label.setPixmap(canvas)

    def draw_rect(self):
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(3)
        pen.setColor(QtGui.QColor("#376F9F"))
        painter.setPen(pen)

        brush = QtGui.QBrush()
        brush.setColor(QtGui.QColor("#FFD141"))
        brush.setStyle(Qt.Dense1Pattern)
        painter.setBrush(brush)

        painter.drawRects([
            QtCore.QRect(50, 50, 100, 100),
            QtCore.QRect(60, 60, 150, 100),
            QtCore.QRect(70, 70, 100, 150),
            QtCore.QRect(80, 80, 150, 100),
            QtCore.QRect(90, 90, 100, 150),
        ])
        painter.end()
        self.label.setPixmap(canvas)

    def draw_text(self):
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(1)
        pen.setColor(QtGui.QColor('green'))
        painter.setPen(pen)

        font = QtGui.QFont()
        font.setFamily('Times')
        font.setBold(True)
        font.setPointSize(40)
        painter.setFont(font)

        painter.drawText(100, 100, 'Hello, world!')
        painter.end()
        self.label.setPixmap(canvas)


app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()