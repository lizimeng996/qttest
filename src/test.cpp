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
  testView->horizontalHeader()->hide();//������ͷ����
  testView->verticalHeader()->hide();//�����кŷ��� 
  testView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //����ֻ�����Բ��ɱ༭
  testView->setSelectionMode(QAbstractItemView::SingleSelection);//����һ��ֻ��ѡһ��
 // testView->setFocusPolicy(Qt::NoFocus);	//�����޽��㣬���ѡ�в�����ʾ���߿�,���̷������ʧЧ

 // testView->setStyleSheet("selection-background-color:rgb(100,200,200)");
  testView->setShowGrid(false);//����ʾ������
  QStandardItemModel *m_itemModel = new QStandardItemModel();
  testView->setModel(m_itemModel);
  testView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //�����ж���չ����Ӧ��ȣ�����������QTableView���,�п��������Ҫ����setModel֮�󣬷��������쳣����
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