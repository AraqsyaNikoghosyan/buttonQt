#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

void handleClick(QLabel *l, int *pc)
{
    (*pc)++;
    l->setText("clicked: " + QString::number(*pc));
    return;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int counter = 0;
    int *pc = &counter;
    QWidget *mainWindow = new QWidget();
    mainWindow->setGeometry(200, 200, 200, 100);
    mainWindow->setWindowTitle("Click Counter App");

    QVBoxLayout *mainLayout = new QVBoxLayout();

    QPushButton *btn = new QPushButton("Click Me!");

    QLabel *label = new QLabel("clicked: " +  QString::number(counter));
    label->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(label);
    mainLayout->addWidget(btn);

    mainWindow->setLayout(mainLayout);


    QObject::connect(btn, &QPushButton::clicked, [=](){ handleClick(label, pc); });

    mainWindow->show();

    return a.exec();
}





