#include "mainwindow.h"

#include <QMap>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    playerPositions["A"] = QPointF(1.0, 2.0);
    playerPositions["B"] = QPointF(3.0, 4.0);

    write();

    playerPositions.clear();


    read();

    qDebug() << playerPositions;
}

MainWindow::~MainWindow() { }

void MainWindow::write() {
    QString fName = QFileDialog::getSaveFileName(nullptr, "Please enter filename");
    if (!fName.isEmpty()) {
        QFile fOut(fName);
        if (fOut.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            QDataStream out(&fOut);
            out << playerPositions;
            fOut.close();
            QMessageBox::information(nullptr, "Yes", "Write succeeded");
        }
    }

}

void MainWindow::read() {
    QString fName = QFileDialog::getOpenFileName(nullptr, "Please enter filename");
    if (!fName.isEmpty()) {
        QFile fIn(fName);
        if (fIn.open(QIODevice::ReadOnly)) {
            QDataStream in(&fIn);
            in >> playerPositions;
            fIn.close();

            QString message;
            QTextStream msgOut(&message);
            msgOut << "Read successful:\n\n";
            for (auto it = playerPositions.begin(); it != playerPositions.end(); ++it)
                msgOut << it.key() << " --> (" << it.value().x() << "," << it.value().y() << ")\n";
            QMessageBox::information(nullptr, "Yes", message);
        }
    }


}
