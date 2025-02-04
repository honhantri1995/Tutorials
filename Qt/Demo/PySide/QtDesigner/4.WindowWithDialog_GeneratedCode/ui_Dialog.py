# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'DialogxSmgYg.ui'
##
## Created by: Qt User Interface Compiler version 6.8.1
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QAbstractButton, QApplication, QComboBox, QDateEdit,
    QDialog, QDialogButtonBox, QDoubleSpinBox, QFormLayout,
    QLabel, QLineEdit, QSizePolicy, QTextEdit,
    QVBoxLayout, QWidget)

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(624, 449)
        self.verticalLayout = QVBoxLayout(Dialog)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.formLayout = QFormLayout()
        self.formLayout.setObjectName(u"formLayout")
        self.lbl_name = QLabel(Dialog)
        self.lbl_name.setObjectName(u"lbl_name")

        self.formLayout.setWidget(0, QFormLayout.LabelRole, self.lbl_name)

        self.leb_name = QLineEdit(Dialog)
        self.leb_name.setObjectName(u"leb_name")

        self.formLayout.setWidget(0, QFormLayout.FieldRole, self.leb_name)

        self.lbl_date = QLabel(Dialog)
        self.lbl_date.setObjectName(u"lbl_date")

        self.formLayout.setWidget(1, QFormLayout.LabelRole, self.lbl_date)

        self.deb_date = QDateEdit(Dialog)
        self.deb_date.setObjectName(u"deb_date")

        self.formLayout.setWidget(1, QFormLayout.FieldRole, self.deb_date)

        self.lbl_depart = QLabel(Dialog)
        self.lbl_depart.setObjectName(u"lbl_depart")

        self.formLayout.setWidget(2, QFormLayout.LabelRole, self.lbl_depart)

        self.cbb_depart = QComboBox(Dialog)
        self.cbb_depart.setObjectName(u"cbb_depart")

        self.formLayout.setWidget(2, QFormLayout.FieldRole, self.cbb_depart)

        self.lbl_pos = QLabel(Dialog)
        self.lbl_pos.setObjectName(u"lbl_pos")

        self.formLayout.setWidget(3, QFormLayout.LabelRole, self.lbl_pos)

        self.cbb_pos = QComboBox(Dialog)
        self.cbb_pos.setObjectName(u"cbb_pos")

        self.formLayout.setWidget(3, QFormLayout.FieldRole, self.cbb_pos)

        self.lbl_asalary = QLabel(Dialog)
        self.lbl_asalary.setObjectName(u"lbl_asalary")

        self.formLayout.setWidget(4, QFormLayout.LabelRole, self.lbl_asalary)

        self.dsb_asalary = QDoubleSpinBox(Dialog)
        self.dsb_asalary.setObjectName(u"dsb_asalary")

        self.formLayout.setWidget(4, QFormLayout.FieldRole, self.dsb_asalary)

        self.lbl_jobdesc = QLabel(Dialog)
        self.lbl_jobdesc.setObjectName(u"lbl_jobdesc")

        self.formLayout.setWidget(5, QFormLayout.LabelRole, self.lbl_jobdesc)

        self.teb_jobdesc = QTextEdit(Dialog)
        self.teb_jobdesc.setObjectName(u"teb_jobdesc")

        self.formLayout.setWidget(5, QFormLayout.FieldRole, self.teb_jobdesc)


        self.verticalLayout.addLayout(self.formLayout)

        self.buttonBox = QDialogButtonBox(Dialog)
        self.buttonBox.setObjectName(u"buttonBox")
        self.buttonBox.setStandardButtons(QDialogButtonBox.StandardButton.Cancel|QDialogButtonBox.StandardButton.Ok)

        self.verticalLayout.addWidget(self.buttonBox)

#if QT_CONFIG(shortcut)
        self.lbl_name.setBuddy(self.leb_name)
        self.lbl_date.setBuddy(self.deb_date)
        self.lbl_depart.setBuddy(self.cbb_depart)
        self.lbl_pos.setBuddy(self.cbb_pos)
        self.lbl_asalary.setBuddy(self.dsb_asalary)
#endif // QT_CONFIG(shortcut)

        self.retranslateUi(Dialog)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None))
        self.lbl_name.setText(QCoreApplication.translate("Dialog", u"Employee name:", None))
        self.lbl_date.setText(QCoreApplication.translate("Dialog", u"Employee date:", None))
        self.lbl_depart.setText(QCoreApplication.translate("Dialog", u"Department:", None))
        self.lbl_pos.setText(QCoreApplication.translate("Dialog", u"Position:", None))
        self.lbl_asalary.setText(QCoreApplication.translate("Dialog", u"Anual salary:", None))
        self.lbl_jobdesc.setText(QCoreApplication.translate("Dialog", u"Job description:", None))
    # retranslateUi

