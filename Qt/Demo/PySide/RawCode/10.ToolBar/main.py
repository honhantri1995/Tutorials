import sys

from PySide6.QtCore import QSize, Qt
from PySide6.QtGui import QAction, QIcon
from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QLabel,
    QMainWindow,
    QStatusBar,
    QToolBar,
)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My App")

        toolbar = QToolBar("My main toolbar")
        toolbar.setIconSize(QSize(16, 16))
        self.addToolBar(toolbar)

        # Notice the "&" used in QAction. It helps underline the letter following by the & when pressing Alt
        home_action = QAction(QIcon(r"../Icons/figure-icon-3.5.6/icons/home.png"), "&Home", self)
        home_action.setStatusTip("back to the Homepage")
        home_action.triggered.connect(self.onMyToolBarButtonClick)
        home_action.setCheckable(True)
        toolbar.addAction(home_action)

        toolbar.addSeparator()

        search_action = QAction(QIcon(r"../Icons/figure-icon-3.5.6/icons/magnifier.png"), "&Magnifier", self)
        search_action.setStatusTip("Search anything")
        search_action.triggered.connect(self.onMyToolBarButtonClick)
        toolbar.addAction(search_action)

        toolbar.addSeparator()

        toolbar.addWidget(QLabel("Ticked "))
        toolbar.addWidget(QCheckBox())

        self.setStatusBar(QStatusBar(self))

    def onMyToolBarButtonClick(self, s):
        print("Click", s)

app = QApplication(sys.argv)

window = MainWindow()
window.show()

app.exec()