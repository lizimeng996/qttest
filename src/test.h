#pragma once
#include "ui_test.h"
#include <QMainWindow>
#include <QTableView>
#include <QTreeWidgetItem>
class test : public QMainWindow {
    Q_OBJECT
    
public:
    test(QWidget* parent = nullptr);
    ~test();
    
public:
    QTableView *testView;


private:
    Ui_test* ui;
public slots:
    void getItem(QTreeWidgetItem*,int);
};