#include <QApplication>
#include <iostream>
#include <QPushButton>
#include <QTreeView>
#include <QFileSystemModel>
#include <QSplitter>
#include <QListView>
#include <QTextEdit>
#include <QDir>
#include <QHBoxLayout>
using namespace std;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget* window=new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    window->resize(QSize(1000,1000));

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::homePath());
    model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    QTreeView *tree = new QTreeView();
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::homePath()));
    tree->setColumnWidth(0,400);
    tree->setColumnHidden(2,true);

    // here i will try to get the selected .zip/.tar/.tar.gz file

    layout->addWidget(tree);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
// to implrement the QFileSystemModel::dromMimeData for a drag and drop