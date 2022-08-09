#include "test.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QDebug>
#include <QTreeWidgetItem>

test::test(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_test)
{
  qDebug()<<"yunxing.............";
  ui->setupUi(this);
  testView = new QTableView(this);
  testView->resize(500,500);
  testView->horizontalHeader()->hide();//隐藏列头方法
  testView->verticalHeader()->hide();//隐藏行号方法 
  testView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置只读属性不可编辑
  testView->setSelectionMode(QAbstractItemView::SingleSelection);//设置一次只能选一行
 // testView->setFocusPolicy(Qt::NoFocus);	//设置无焦点，鼠标选中不会显示虚线框,键盘方向键会失效

 // testView->setStyleSheet("selection-background-color:rgb(100,200,200)");
  testView->setShowGrid(false);//不显示网格线
  QStandardItemModel *m_itemModel = new QStandardItemModel();
  testView->setModel(m_itemModel);
  testView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //所有列都扩展自适应宽度，填充充满整个QTableView宽度,列宽的设置需要放在setModel之后，否则会出现异常现象
  QList<QStandardItem *> itemList;
  QString tt = "111";
  itemList.append(new QStandardItem("-1"));
  itemList.append(new QStandardItem("-1"));
  itemList.append(new QStandardItem("-1"));
  itemList.append(new QStandardItem("-1"));
  m_itemModel->appendColumn(itemList);
  connect(testView,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this, SLOT( getItem(QTreeWidgetItem*,int)) );
}
test::~test()
{
    delete ui; 
}
void test::getItem(QTreeWidgetItem*,int){
    qDebug()<<"testtttttttttttttttttttttttttt";
}