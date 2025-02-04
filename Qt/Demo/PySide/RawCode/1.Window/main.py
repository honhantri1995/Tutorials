import sys

from PySide6.QtWidgets import QApplication, QMainWindow, QWidget, QPushButton


# You need one (and only one) QApplication instance per application.

# Pass in sys.argv to allow command line arguments for your app.
# If you know you won't use command line arguments QApplication([]) works too.
app = QApplication(sys.argv)

# In Qt, any widgets can be windows. You can write: window = QWidget() to create a Qt widget, which will be our window.
# But Qt has a better solution - QMainWindow - which offers a lot of standard window features (toolbars, menu, etc.)
window = QMainWindow()

# Windows are hidden by default, so let's show it
window.show()

# Start the event loop.
app.exec()

# Your application won't reach here until you exit and the event loop has stopped.
