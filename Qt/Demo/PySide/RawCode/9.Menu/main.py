import sys

from PySide6.QtGui import QAction, QKeySequence, QIcon
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QStatusBar
)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My App")

        newfile_action = QAction(QIcon(r"../Icons/figure-icon-3.5.6/icons/new.png"), "New File", self)
        newfile_action.setStatusTip("Create a new file")
        newfile_action.triggered.connect(self.onMyToolBarButtonClick)
        newfile_action.setShortcut(QKeySequence("Ctrl+N"))  # Not "Ctrl + N"

        # Notice the "&" used in QAction and addMenu. It helps underline the letter following by the & when pressing Alt
        openrecent_action = QAction("Open &Most Recent", self)
        openrecent_action.setStatusTip("Open most recently opened file")
        openrecent_action.triggered.connect(self.onMyToolBarButtonClick)

        menu = self.menuBar()
        file_menu = menu.addMenu("&File")
        file_menu.addAction(newfile_action)
        file_menu.addSeparator()

        file_submenu = file_menu.addMenu("&Open Recent")
        file_submenu.addAction(openrecent_action)

        self.setStatusBar(QStatusBar(self))

    def onMyToolBarButtonClick(self, s):
        print("Click", s)

app = QApplication(sys.argv)

window = MainWindow()
window.show()

app.exec()