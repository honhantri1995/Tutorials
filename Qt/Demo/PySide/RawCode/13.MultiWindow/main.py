import sys

from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

class SubWindow(QWidget):
    """
        This "window" is a QWidget. If it has no parent, it will appear as a free-floating window as we want.
    """
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout()
        self.label = QLabel("Sub window")
        layout.addWidget(self.label)
        self.setLayout(layout)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        layout = QVBoxLayout()
        button1 = QPushButton("Press me for a new temporary window!")
        button1.clicked.connect(self.on_button1_clicked)
        button2 = QPushButton("Press me for a new permanent window!")
        button2.clicked.connect(self.on_button2_clicked)
        layout.addWidget(button1)
        layout.addWidget(button2)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

        self.temp_subwindow = None
        self.perm_subwindow = SubWindow()

    def on_button1_clicked(self, checked):
        # Following code terminate the new window right after creating it because the window reference was gone
        # subwindow = SubWindow()
        # subwindow.show()

        # Following code keeps the new window opening, however, it also creates many other window each time we click the button
        # self.subwindow = SubWindow()
        # self.subwindow.show()

        # Following code keeps the new window opening, and do not create new window each time
        if self.temp_subwindow is None:
            self.temp_subwindow = SubWindow()
            self.temp_subwindow.show()
        else:
            print('Discard creating new window')

    def on_button2_clicked(self, checked):
        # This is fine
        # self.perm_subwindow.show()

        # But this is better
        if not self.perm_subwindow.isVisible():
            self.perm_subwindow.show()

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()