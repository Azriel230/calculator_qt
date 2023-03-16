#include "mymainwindow.h"
#include "ui_mymainwindow.h"

#include <math.h>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::display_res()
{
    ui->m_lcd_result->display(m_display);
}

void MyMainWindow::display_memory_res()
{
    ui->m_label_memory_res->setText("Memory: " + m_display_memory);
}

void MyMainWindow::display_operation_res()
{
    ui->m_label_ar_op->setText(m_display_operation);
}

void MyMainWindow::on_m_pb_0_clicked()
{
    m_display += '0';
    display_res();
}


void MyMainWindow::on_m_pb_1_clicked()
{
    m_display += '1';
    display_res();
}


void MyMainWindow::on_m_pb_2_clicked()
{
    m_display += '2';
    display_res();
}

void MyMainWindow::on_m_pb_3_clicked()
{
    m_display += '3';
    display_res();
}

void MyMainWindow::on_m_pb_4_clicked()
{
    m_display += '4';
    display_res();
}

void MyMainWindow::on_m_pb_5_clicked()
{
    m_display += '5';
    display_res();
}

void MyMainWindow::on_m_pb_6_clicked()
{
    m_display += '6';
    display_res();
}

void MyMainWindow::on_m_pb_7_clicked()
{
    m_display += '7';
    display_res();
}

void MyMainWindow::on_m_pb_8_clicked()
{
    m_display += '8';
    display_res();
}

void MyMainWindow::on_m_pb_9_clicked()
{
    m_display += '9';
    display_res();
}

void MyMainWindow::on_m_pb_Backspace_clicked()
{
    m_display.chop(1);
    display_res();
}


void MyMainWindow::on_m_pb_Clear_clicked()
{
    m_display.clear();
    display_res();
}


void MyMainWindow::on_m_pb_Clear_All_clicked()
{
    m_display.clear();
    m_res = 0;
    display_res();
}

void MyMainWindow::on_m_pb_MC_clicked()
{
    m_res_memory = 0;
    m_display_memory.clear();
    display_memory_res();
}


void MyMainWindow::on_m_pb_MR_clicked()
{
    m_display = m_display.number(m_res_memory);
    display_res();
}


void MyMainWindow::on_m_pb_MS_clicked()
{
    m_res_memory = m_display.toDouble();
    m_display_memory = m_display_memory.number(m_res_memory);
    display_memory_res();
}


void MyMainWindow::on_m_pb_Mplus_clicked()
{
    m_res_memory += m_display.toDouble();
    m_display_memory = m_display_memory.number(m_res_memory);
    display_memory_res();
}


void MyMainWindow::on_m_pb_Sqrt_clicked()
{
    m_res = m_display.toDouble();
    m_res = sqrt(m_res);
    m_display = m_display.number(m_res);
    display_res();
}

void MyMainWindow::on_m_pb_plus_clicked()
{
    flag_operation = 1;
    m_res = m_display.toDouble();
    m_display_operation = "+";
    display_operation_res();
    m_display.clear();
    display_res();
}

void MyMainWindow::on_m_pb_minus_clicked()
{
    flag_operation =2;
    m_res = m_display.toDouble();
    m_display_operation = "-";
    display_operation_res();
    m_display.clear();
    display_res();
}

void MyMainWindow::on_m_pb_mult_clicked()
{
    flag_operation = 3;
    m_res = m_display.toDouble();
    m_display_operation = "*";
    display_operation_res();
    m_display.clear();
    display_res();
}

void MyMainWindow::on_m_pb_div_clicked()
{
    flag_operation = 4;
    m_res = m_display.toDouble();
    m_display_operation = "÷";
    display_operation_res();
    m_display.clear();
    display_res();
}

void MyMainWindow::on_m_pb_equal_clicked()
{
    switch(flag_operation)
    {
    case(1):
        m_res += m_display.toDouble();
        break;
    case(2):
        m_res -= m_display.toDouble();
        break;
    case(3):
        m_res *= m_display.toDouble();
        break;
    case(4):
        m_res /= m_display.toDouble();
        break;
    default:
        break;
    }
    flag_operation = 0;
    m_display.number(m_res);
    display_res();

}


void MyMainWindow::on_m_pb_sq_clicked()
{

}


void MyMainWindow::on_m_pb_fraction_clicked()
{

}


void MyMainWindow::on_m_pb_sign_clicked()
{

}


void MyMainWindow::on_m_pb_dot_clicked()
{

}

