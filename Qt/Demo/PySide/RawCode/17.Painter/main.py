import sys
from PySide6 import QtCore, QtGui, QtWidgets
from PySide6.QtCore import Qt

class QPaletteButton(QtWidgets.QPushButton):
    def __init__(self, color):
        super().__init__()
        self.setFixedSize(QtCore.QSize(24,24))
        self.color = color
        self.setStyleSheet("background-color: %s;" % color)

class Canvas(QtWidgets.QLabel):
    def __init__(self):
        super().__init__()
        pixmap = QtGui.QPixmap(600, 300)
        pixmap.fill(Qt.white)
        self.setPixmap(pixmap)

        self.last_x, self.last_y = None, None
        self.pen_color = QtGui.QColor('#000000')

    def set_pen_color(self, c):
        self.pen_color = QtGui.QColor(c)

    def mouseMoveEvent(self, e):
        if self.last_x is None:     # First event
            self.last_x = e.x()
            self.last_y = e.y()
            return                  # Ignore the first time

        canvas = self.pixmap()
        painter = QtGui.QPainter(canvas)
        p = painter.pen()
        p.setWidth(4)
        p.setColor(self.pen_color)
        painter.setPen(p)
        painter.drawLine(self.last_x, self.last_y, e.x(), e.y())
        painter.end()
        self.setPixmap(canvas)

        # Update the origin for next time
        self.last_x = e.x()
        self.last_y = e.y()

    def mouseReleaseEvent(self, e):
        self.last_x = None
        self.last_y = None

class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()

        self.canvas = Canvas()

        widget = QtWidgets.QWidget()
        main_layout = QtWidgets.QVBoxLayout()
        widget.setLayout(main_layout)
        main_layout.addWidget(self.canvas)

        palette_layout = QtWidgets.QHBoxLayout()
        self.add_palette_buttons(palette_layout)
        main_layout.addLayout(palette_layout)

        self.setCentralWidget(widget)

    def add_palette_buttons(self, layout):
        COLORS = [
            # 17 undertones https://lospec.com/palette-list/17undertones
            '#000000', '#141923', '#414168', '#3a7fa7', '#35e3e3', '#8fd970', '#5ebb49',
            '#458352', '#dcd37b', '#fffee5', '#ffd035', '#cc9245', '#a15c3e', '#a42f3b',
            '#f45b7a', '#c24998', '#81588d', '#bcb0c2', '#ffffff',
        ]

        for color in COLORS:
            pbutton = QPaletteButton(color)
            pbutton.pressed.connect(lambda c=color: self.canvas.set_pen_color(c))
            layout.addWidget(pbutton)


app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()