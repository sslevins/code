#include <QApplication>
#include <QWidget>
#include <QTableView>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QSplitter>
#include <QStandardItemModel>

int main(int argc, char *argv[]) 
{

	QApplication app(argc, argv);

	QStandardItemModel * model = new QStandardItemModel;
	model->setRowCount(3);
	model->setColumnCount(3);

	model->setHeaderData(0, Qt::Horizontal, "ID");
	model->setHeaderData(1, Qt::Horizontal, "User");
	model->setHeaderData(2, Qt::Horizontal, "PassWd");

	for (int j = 0; j < 3; j++)
	{
		QStandardItem * itemId = 
			new QStandardItem(QString::number(j));
		model->setItem(j, 0, itemId);

		QStandardItem * itemUser = 
			new QStandardItem("author" + QString::number(j));
		model->setItem(j, 1, itemUser);

		QStandardItem * itemPassWd = new QStandardItem("123456");
		model->setItem(j, 2, itemPassWd);
	}

	QTableView * tableView = new QTableView;
	tableView->verticalHeader()->hide();
	tableView->setModel(model);

	tableView->setColumnWidth(0, 30);
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


	QHBoxLayout *blayout=new QHBoxLayout;
	blayout->addWidget(tableView);
	blayout->addStretch();
	QSplitter *splitter = new QSplitter;
	splitter->setLayout(blayout);
	splitter->show();
	return app.exec();


}
