#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MyMainWindow; }
QT_END_NAMESPACE

enum Operations {plus, minus, mult, divide};

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

private slots:
    void on_m_pb_0_clicked();

    void on_m_pb_1_clicked();

    void on_m_pb_2_clicked();

    void on_m_pb_3_clicked();

    void on_m_pb_4_clicked();

    void on_m_pb_5_clicked();

    void on_m_pb_6_clicked();

    void on_m_pb_7_clicked();

    void on_m_pb_8_clicked();

    void on_m_pb_9_clicked();


    void on_m_pb_Backspace_clicked();

    void on_m_pb_Clear_clicked();

    void on_m_pb_Clear_All_clicked();

private:
    void display_res();

private:
    QString m_display;
    QString m_display_memory;

    double m_res = 0;

private:
    Ui::MyMainWindow *ui;
};
#endif // MYMAINWINDOW_H
