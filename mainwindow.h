#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMap>
#include <QString>
#include <QPointF>

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

    QMap<QString, QPointF> playerPositions;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void write();
    void read();
};
#endif // MAINWINDOW_H
