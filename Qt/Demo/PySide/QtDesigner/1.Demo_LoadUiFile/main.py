import sys
from PySide6 import QtWidgets
from PySide6.QtUiTools import QUiLoader

loader = QUiLoader()

def mainwindow_setup(w):
    '''
        The PySide6 loader does not allow you to apply a UI layout to an existing widget.
        This prevents you adding custom code for the initialization of the widget in a class __init__ block.
        However, you can work around this with a separate init function.
    '''
    w.setWindowTitle("MainWindow Title")

app = QtWidgets.QApplication(sys.argv)
window = loader.load("window.ui", None)
mainwindow_setup(window)
window.show()
app.exec()
