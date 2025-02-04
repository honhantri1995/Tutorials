from PySide6.QtGui import QIcon, QAction
from PySide6.QtWidgets import QApplication, QColorDialog, QSystemTrayIcon, QMenu

app = QApplication([])
app.setQuitOnLastWindowClosed(False)

# Create the icon
icon = QIcon("color.png")

clipboard = QApplication.clipboard()
dialog = QColorDialog()

def copy_color_hex():
    if dialog.exec():
        color = dialog.currentColor()
        clipboard.setText(color.name())

def copy_color_rgb():
    if dialog.exec():
        color = dialog.currentColor()
        clipboard.setText("rgb(%d, %d, %d)" % (
            color.red(), color.green(), color.blue()
        ))

def copy_color_hsv():
    if dialog.exec():
        color = dialog.currentColor()
        clipboard.setText("hsv(%d, %d, %d)" % (
            color.hue(), color.saturation(), color.value()
        ))

# Create the tray
tray = QSystemTrayIcon()
tray.setIcon(icon)
tray.setVisible(True)

# Create the menu
menu = QMenu()
action_hex = QAction("Hex")
action_hex.triggered.connect(copy_color_hex)
menu.addAction(action_hex)

action_rgb = QAction("RGB")
action_rgb.triggered.connect(copy_color_rgb)
menu.addAction(action_rgb)

action_hsv = QAction("HSV")
action_hsv.triggered.connect(copy_color_hsv)
menu.addAction(action_hsv)

quit = QAction("Quit")
quit.triggered.connect(app.quit)
menu.addAction(quit)

# Add the menu to the tray
tray.setContextMenu(menu)

app.exec()


# The default behaviour in Qt is to close an application once all the active windows have closed. 
# This won't affect this toy example, but will be an issue in application where you do create windows and then close them. 
# Setting `app.setQuitOnLastWindowClosed(False)` stops this and will ensure your application keeps running.