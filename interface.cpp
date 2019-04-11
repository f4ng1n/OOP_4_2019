#include "interface.h"
#include <QRegExpValidator>
#include "complex.h"
#include "number.h"
#include "polinom.h"
#include <sstream>


TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(tr("Polinom calculator"));
    this->setMinimumSize(300, 300);

    p_lbl_polinome = new QLabel("a*x<sup>2</sup>+b*x+c", this);
    QValidator *double_filter = new QRegExpValidator(QRegExp("[+-]?\\d*\\.?\\d+"), this);
    QPushButton* p_calculate_button = new QPushButton("Calculate");

    QLabel* p_lbl_a = new QLabel("a ", this); p_led_a = new  QLineEdit("0.0");
          QLabel* p_lbl_i1 = new QLabel("+  i");
             p_led_ai= new QLineEdit("0.0");p_led_ai = new  QLineEdit("0.0");
             p_led_a->setValidator(double_filter);

    QLabel* p_lbl_b = new QLabel("b "); p_led_b = new  QLineEdit("0.0");
        QLabel* p_lbl_i2 = new QLabel("+  i");
            p_led_bi= new QLineEdit("0.0");p_led_bi = new  QLineEdit("0.0");
            p_led_b->setValidator(double_filter);

    QLabel* p_lbl_c = new QLabel("c "); p_led_c = new  QLineEdit("0.0");
          QLabel* p_lbl_i3 = new QLabel("+  i");
            p_led_ci= new QLineEdit("0.0");p_led_ci = new  QLineEdit("0.0");
            p_led_c->setValidator(double_filter);

    QLabel* p_lbl_x = new QLabel("x "); p_led_x = new  QLineEdit("0.0");
            QLabel* p_lbl_i = new QLabel("+  i");
                p_led_xi= new QLineEdit("0.0");p_led_xi = new  QLineEdit("0.0");
                p_led_x->setValidator(double_filter);


    p_lbl_calculated_value = new QLabel("p(x) = ");
    p_lbl_root1 = new QLabel("x<sub>1</sub> = nan");
    p_lbl_root2 = new QLabel("x<sub>2</sub> = nan");

    QGridLayout* p_glayout = new QGridLayout;
    p_glayout->addWidget(p_lbl_polinome, 0, 0, 1, 3);
    p_glayout->addWidget(p_lbl_a, 1, 0); p_glayout->addWidget(p_led_a, 1, 1);
       p_glayout->addWidget(p_lbl_i1, 1, 2); p_glayout->addWidget(p_led_ai, 1, 3);
    p_glayout->addWidget(p_lbl_b, 2, 0); p_glayout->addWidget(p_led_b, 2, 1);
        p_glayout->addWidget(p_lbl_i2, 2, 2); p_glayout->addWidget(p_led_bi, 2, 3);
    p_glayout->addWidget(p_lbl_c, 3, 0); p_glayout->addWidget(p_led_c, 3, 1);
        p_glayout->addWidget(p_lbl_i3, 3, 2); p_glayout->addWidget(p_led_ci, 3, 3);
    p_glayout->addWidget(p_lbl_x, 4, 0); p_glayout->addWidget(p_led_x, 4, 1);
        p_glayout->addWidget(p_lbl_i, 4, 2); p_glayout->addWidget(p_led_xi, 4, 3);
    p_glayout->addWidget(p_lbl_calculated_value, 5, 1);
    p_glayout->addWidget(p_lbl_root1, 6, 1); p_glayout->addWidget(p_lbl_root2, 6, 2);
    p_glayout->addWidget(p_calculate_button, 7, 2);
    this->setLayout(p_glayout);

    connect(p_calculate_button, SIGNAL(clicked()),
            this, SLOT(calculate_button_pressed()));
    connect(p_led_a, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
    connect(p_led_ai, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
    connect(p_led_b, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
    connect(p_led_bi, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
    connect(p_led_c, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
    connect(p_led_ci, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));

}


void TInterface::calculate_button_pressed()
{
    number *rs = new number[2];
   int n = polinom.roots(rs);
    stringstream ss;
    ss<<"x<sub>1</sub> = "<<rs[0];
    stringstream ss2;
    ss2<<"x<sub>2</sub> = "<<rs[1];
   p_lbl_root1->setText(QString::fromStdString( ss.str()));
   p_lbl_root2->setText(QString::fromStdString( ss2.str()));

   stringstream ss3;
   ss3<<"P("<<p_led_x->text().toStdString()+"+"+p_led_xi->text().toStdString()+"i)"<<") = "<<polinom.value(p_led_x->text().toDouble());
p_lbl_calculated_value->setText(QString::fromStdString(ss3.str()));
}
void TInterface::update_polinom()
{
    p_lbl_polinome->setText(tr("%1*x<sup>2</sup>+%2*x+%3").arg(
                                QString::fromStdString("("+p_led_a->text().toStdString()+"+"+p_led_ai->text().toStdString()+"i)"),
                                QString::fromStdString("("+p_led_b->text().toStdString()+"+"+p_led_bi->text().toStdString()+"i)"),
                                QString::fromStdString("("+p_led_c->text().toStdString()+"+"+p_led_ci->text().toStdString()+"i)")));
    polinom.a = TComplex(p_led_a->text().toDouble(),p_led_ai->text().toDouble());
    polinom.b = TComplex(p_led_b->text().toDouble(),p_led_bi->text().toDouble());
    polinom.c = TComplex(p_led_c->text().toDouble(),p_led_ci->text().toDouble());


}
