#include <QApplication>
#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include <QSplitter>
#include <QStandardItemModel>

int main(int argc, char *argv[]) 
{
	QApplication app(argc, argv);

	QStandardItem* item1 = 
					new QStandardItem("item1");
	QStandardItem* item2 = 
					new QStandardItem("item2");
	QStandardItem* item3 = 
					new QStandardItem("item3");

	//qstmodel->appendRow(item1);
	//qstmodel->appendRow(item3);

	QStandardItemModel * model = 
					new QStandardItemModel;

	model->setHeaderData(0, Qt::Horizontal, "id");
	model->setHeaderData(1, Qt::Horizontal, "name");
	model->setHeaderData(2, Qt::Horizontal, "result");

	for (int i = 0; i < 3; i++)
	{
		QStandardItem * item = new QStandardItem(0, 3);
		item.setData();
	}

	QTableView * view = new QTableView;

	view->setModel(model);
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
