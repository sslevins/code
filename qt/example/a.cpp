#include <QApplication>
#include <QWidget>
#include<QTreeView>
#include<QDirModel>
#include<QHBoxLayout>
#include<QSplitter>
#include<QStringListModel>
#include<QListView>
#include<QStandardItemModel>

int main(int argc, char *argv[]) 
{
	QApplication app(argc, argv);

	QStandardItemModel *qstmodel = 
					new QStandardItemModel();
	QStandardItem* item1 = 
					new QStandardItem("item1");
	QStandardItem* item2 = 
					new QStandardItem("item2");
	QStandardItem* item3 = 
					new QStandardItem("item3");


	qstmodel->appendRow(item1);
	//qstmodel->appendRow(item2);
	item1->appendRow(item2);
	qstmodel->appendRow(item3);

	QListView *view=new QListView;
	view->setModel(qstmodel);

	view->setSelectionMode(QAbstractItemView::SingleSelection);
	view->setAutoFillBackground(true);
	QHBoxLayout *blayout=new QHBoxLayout;
	blayout->addWidget(view);
	blayout->addStretch();
	QSplitter *splitter = new QSplitter; 
	splitter->setLayout(blayout);
	splitter->show();

	return app.exec();
}
