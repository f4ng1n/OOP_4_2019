/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QLabel *p_lbl_polinome;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *p_lbl_root1;
    QLabel *p_lbl_root2;
    QLabel *label_7;
    QLineEdit *p_led_a;
    QLineEdit *p_led_b;
    QLineEdit *p_led_c;
    QLineEdit *p_led_x;
    QPushButton *p_lbl_calculated_value;

    void setupUi(QWidget *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->resize(469, 293);
        p_lbl_polinome = new QLabel(Interface);
        p_lbl_polinome->setObjectName(QString::fromUtf8("p_lbl_polinome"));
        p_lbl_polinome->setGeometry(QRect(30, 10, 81, 16));
        label_2 = new QLabel(Interface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 30, 47, 13));
        label_3 = new QLabel(Interface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 30, 47, 13));
        label_4 = new QLabel(Interface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 70, 47, 13));
        p_lbl_root1 = new QLabel(Interface);
        p_lbl_root1->setObjectName(QString::fromUtf8("p_lbl_root1"));
        p_lbl_root1->setGeometry(QRect(20, 150, 47, 13));
        p_lbl_root2 = new QLabel(Interface);
        p_lbl_root2->setObjectName(QString::fromUtf8("p_lbl_root2"));
        p_lbl_root2->setGeometry(QRect(20, 170, 47, 13));
        label_7 = new QLabel(Interface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 120, 47, 13));
        p_led_a = new QLineEdit(Interface);
        p_led_a->setObjectName(QString::fromUtf8("p_led_a"));
        p_led_a->setGeometry(QRect(20, 30, 71, 21));
        p_led_b = new QLineEdit(Interface);
        p_led_b->setObjectName(QString::fromUtf8("p_led_b"));
        p_led_b->setGeometry(QRect(150, 30, 71, 21));
        p_led_c = new QLineEdit(Interface);
        p_led_c->setObjectName(QString::fromUtf8("p_led_c"));
        p_led_c->setGeometry(QRect(270, 30, 71, 21));
        p_led_x = new QLineEdit(Interface);
        p_led_x->setObjectName(QString::fromUtf8("p_led_x"));
        p_led_x->setGeometry(QRect(50, 70, 71, 21));
        p_lbl_calculated_value = new QPushButton(Interface);
        p_lbl_calculated_value->setObjectName(QString::fromUtf8("p_lbl_calculated_value"));
        p_lbl_calculated_value->setGeometry(QRect(140, 230, 80, 21));

        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QWidget *Interface)
    {
        Interface->setWindowTitle(QApplication::translate("Interface", "Interface", nullptr));
        p_lbl_polinome->setText(QApplication::translate("Interface", "Polinomial", nullptr));
        label_2->setText(QApplication::translate("Interface", "x^2  + ", nullptr));
        label_3->setText(QApplication::translate("Interface", "x + ", nullptr));
        label_4->setText(QApplication::translate("Interface", "x =", nullptr));
        p_lbl_root1->setText(QApplication::translate("Interface", "Root 1 = ", nullptr));
        p_lbl_root2->setText(QApplication::translate("Interface", "Root 2 = ", nullptr));
        label_7->setText(QApplication::translate("Interface", "P(x) =", nullptr));
        p_lbl_calculated_value->setText(QApplication::translate("Interface", "CALCULATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
