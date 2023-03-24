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

/*
* Выводит на LCD Number введеное число
*/
void MyMainWindow::display_res()
{
    ui->m_lcd_result->display(m_display);
}
/*
* Выводит в label число, которое находится в памяти калькулятора
*/
void MyMainWindow::display_memory_res()
{
    ui->m_label_memory_res->setText("Memory: " + m_display_memory);
}

/*
* Выводит в label символ знака последней нажатой операции 
*/
void MyMainWindow::display_operation_res()
{
    ui->m_label_ar_op->setText(m_display_operation);
}

/*
* Выводит в лсд цифру 0
*/
void MyMainWindow::on_m_pb_0_clicked()
{
    // возможно нужно сделать так, чтобы если в lsd находится 0, то новые не печатать
    m_display += '0';
    display_res();
}

/*
* Выводит в лсд цифру 1
*/
void MyMainWindow::on_m_pb_1_clicked()
{
    m_display += '1';
    display_res();
}

/*
* Выводит в лсд цифру 2
*/
void MyMainWindow::on_m_pb_2_clicked()
{
    m_display += '2';
    display_res();
}

/*
* Выводит в лсд цифру 3
*/
void MyMainWindow::on_m_pb_3_clicked()
{
    m_display += '3';
    display_res();
}

/*
* Выводит в лсд цифру 4
*/
void MyMainWindow::on_m_pb_4_clicked()
{
    m_display += '4';
    display_res();
}

/*
* Выводит в лсд цифру 5
*/
void MyMainWindow::on_m_pb_5_clicked()
{
    m_display += '5';
    display_res();
}

/*
* Выводит в лсд цифру 6
*/
void MyMainWindow::on_m_pb_6_clicked()
{
    m_display += '6';
    display_res();
}

/*
* Выводит в лсд цифру 7
*/
void MyMainWindow::on_m_pb_7_clicked()
{
    m_display += '7';
    display_res();
}

/*
* Выводит в лсд цифру 8
*/
void MyMainWindow::on_m_pb_8_clicked()
{
    m_display += '8';
    display_res();
}

/*
* Выводит в лсд цифру 9
*/
void MyMainWindow::on_m_pb_9_clicked()
{
    m_display += '9';
    display_res();
}

/*
* Удаляет последнюю введенную цифру с экрана
*/
void MyMainWindow::on_m_pb_Backspace_clicked()
{
    m_display.chop(1);
    display_res();
}

/*
* Очищает число, выведенное на экране
*/
void MyMainWindow::on_m_pb_Clear_clicked()
{
    m_display.clear();
    display_res();
}

/*
* Очищает число, введенное на экране и обнуляет число-результат
*/
void MyMainWindow::on_m_pb_Clear_All_clicked()
{
    m_display.clear();
    m_res = 0;
    display_res();
}

/*
* Очищает число в памяти калькулятора
*/
void MyMainWindow::on_m_pb_MC_clicked()
{
    m_res_memory = 0;
    m_display_memory.clear();
    display_memory_res();
}

/*
* Выводит на экран число из памяти калькулятора
*/
void MyMainWindow::on_m_pb_MR_clicked()
{
    m_display = m_display.number(m_res_memory);
    display_res();
}

/*
* Сохраняет число с экрана в память калькулятора
*/
void MyMainWindow::on_m_pb_MS_clicked()
{
    m_res_memory = m_display.toDouble();
    m_display_memory = m_display_memory.number(m_res_memory);
    display_memory_res();
}

/*
* Прабавляет число с экрана к числу в памяти
*/
void MyMainWindow::on_m_pb_Mplus_clicked()
{
    m_res_memory += m_display.toDouble();
    m_display_memory = m_display_memory.number(m_res_memory);
    display_memory_res();
}

/*
* Вычисляет квадратный корень числа с экрана и выводит результат
*/ 
void MyMainWindow::on_m_pb_Sqrt_clicked()
{
    m_res = m_display.toDouble();
    m_res = sqrt(m_res);
    m_display = m_display.number(m_res);
    display_res();
}

/*
* Запоминает в буфер число с экрана и присваивает флагу операции нужный код (для '+' - 1)
*/
void MyMainWindow::on_m_pb_plus_clicked()
{
    flag_operation = 1;
    m_res = m_display.toDouble();
    m_display_operation = "+";
    display_operation_res();
    m_display.clear();
    display_res();
}

/*
* Запоминает в буфер число с экрана и присваивает флагу операции нужный код (для '-' - 2)
*/
void MyMainWindow::on_m_pb_minus_clicked()
{
    flag_operation = 2;
    m_res = m_display.toDouble();
    m_display_operation = "-";
    display_operation_res();
    m_display.clear();
    display_res();
}

/*
* Запоминает в буфер число с экрана и присваивает флагу операции нужный код (для '*' - 3)
*/
void MyMainWindow::on_m_pb_mult_clicked()
{
    flag_operation = 3;
    m_res = m_display.toDouble();
    m_display_operation = "*";
    display_operation_res();
    m_display.clear();
    display_res();
}

/*
* Запоминает в буфер число с экрана и присваивает флагу операции нужный код (для '/' - 4)
*/
void MyMainWindow::on_m_pb_div_clicked()
{
    flag_operation = 4;
    m_res = m_display.toDouble();
    m_display_operation = "÷";
    display_operation_res();
    m_display.clear();
    display_res();
}

/*
* Вычисляет выражение в соответствии с кодом операции и выводит результат на экран
*/
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
    m_display = m_display.number(m_res);
    display_res();
}

/*
* Возводит число с экрана в квадрат и выводит его на экран
*/
void MyMainWindow::on_m_pb_sq_clicked()
{
    m_res = m_display.toDouble();
    m_res *= m_res;
    m_display = m_display.number(m_res);
    display_res();
}

/*
* Делит 1 на число с экрана и выводит результат на экран
*/
void MyMainWindow::on_m_pb_fraction_clicked()
{
    m_res = m_display.toDouble();
    m_res = 1/m_res;
    m_display = m_display.number(m_res);
    display_res();
}

/*
* Заменяет знак числа с экрана
*/
void MyMainWindow::on_m_pb_sign_clicked()
{
    m_res = m_display.toDouble();
    m_res = -1 * m_res;
    m_display = m_display.number(m_res);
    display_res();
}

/*
* Добавляет точку на экран, делая число десятичной дробью
*/
void MyMainWindow::on_m_pb_dot_clicked()
{
    if(!m_display.contains('.'))
    {
        m_display = m_display + ".";
        display_res();
    }
}

