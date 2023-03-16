#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <math.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MyMainWindow; }
QT_END_NAMESPACE

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

    void on_m_pb_MC_clicked();

    void on_m_pb_MR_clicked();

    void on_m_pb_MS_clicked();

    void on_m_pb_Mplus_clicked();

    void on_m_pb_Sqrt_clicked();

    void on_m_pb_div_clicked();

    void on_m_pb_mult_clicked();

    void on_m_pb_plus_clicked();

    void on_m_pb_minus_clicked();

    void on_m_pb_equal_clicked();

    void on_m_pb_sq_clicked();

    void on_m_pb_fraction_clicked();

    void on_m_pb_sign_clicked();

    void on_m_pb_dot_clicked();

private:
    void display_res();
    void display_memory_res();
    void display_operation_res();

private:
    QString m_display;
    QString m_display_memory;
    QString m_display_operation;

    double m_res = 0;
    double m_res_memory;
    int flag_operation = 0; // 0-no operation, 1-plus, 2-minus, 3-mult, 4-div

private:
    Ui::MyMainWindow *ui;
};
#endif // MYMAINWINDOW_H
